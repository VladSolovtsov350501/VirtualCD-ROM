#include <windows.h>
#include <winioctl.h>
#include <shlobj.h>
#include <stdio.h>
#include <stdlib.h>
#include "vcdrom.h"

#ifdef NTDDI_VERSION
// This warning only applies to drivers not applications.
#pragma warning(disable:28719)
#endif // NTDDI_VERSION

void PrintMenu()
{
    fprintf(stderr, "Menu:\n");
    fprintf(stderr, "filedisk /mount  <devicenumber> <filename> [size[k|M|G] | /ro | /cd] <drive:>\n");
    fprintf(stderr, "filedisk /unmount <drive:>\n");
    fprintf(stderr, "filedisk /status <drive:>\n");
    fprintf(stderr, "\n");
}

void PrintLastError(char* Prefix)
{
    LPVOID lpMsgBuf;

    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, GetLastError(), 0, (LPTSTR) &lpMsgBuf, 0, NULL);

    fprintf(stderr, "%s %s", Prefix, (LPTSTR) lpMsgBuf);

    LocalFree(lpMsgBuf);
}

int FileDiskMount(int DeviceNumber, POPEN_FILE_INFORMATION OpenFileInformation, BOOLEAN CdImage)
{
    char    VolumeName[] = "\\\\.\\ :";
    char    DriveName[] = " :\\";
    char    DeviceName[255];
    HANDLE  Device;
    DWORD   BytesReturned;

    VolumeName[4] = OpenFileInformation->DriveLetter;
    DriveName[0] = OpenFileInformation->DriveLetter;

    Device = CreateFile(VolumeName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL);

    if (Device != INVALID_HANDLE_VALUE)
    {
        CloseHandle(Device);
        SetLastError(ERROR_BUSY);
        PrintLastError(&VolumeName[4]);
        return -1;
    }

    if (CdImage)
        sprintf(DeviceName, DEVICE_NAME_PREFIX "Cd" "%u", DeviceNumber);
    else
        sprintf(DeviceName, DEVICE_NAME_PREFIX "%u", DeviceNumber);

    if (!DefineDosDevice(DDD_RAW_TARGET_PATH, &VolumeName[4], DeviceName))
    {
        PrintLastError(&VolumeName[4]);
        return -1;
    }

    Device = CreateFile(VolumeName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL);

    if (Device == INVALID_HANDLE_VALUE)
    {
        PrintLastError(&VolumeName[4]);
        DefineDosDevice(DDD_REMOVE_DEFINITION, &VolumeName[4], NULL);
        return -1;
    }

    if (!DeviceIoControl(Device, IOCTL_FILE_DISK_OPEN_FILE, OpenFileInformation, sizeof(OPEN_FILE_INFORMATION) + OpenFileInformation->FileNameLength - 1, NULL, 0, &BytesReturned, NULL))
    {
        PrintLastError("FileDisk:");
        DefineDosDevice(DDD_REMOVE_DEFINITION, &VolumeName[4], NULL);
        CloseHandle(Device);
        return -1;
    }

    CloseHandle(Device);

    SHChangeNotify(SHCNE_DRIVEADD, SHCNF_PATH, DriveName, NULL);

    return 0;
}

int FileDiskUmount(char DriveLetter)
{
    char    VolumeName[] = "\\\\.\\ :";
    char    DriveName[] = " :\\";
    HANDLE  Device;
    DWORD   BytesReturned;

    VolumeName[4] = DriveLetter;
    DriveName[0] = DriveLetter;

    Device = CreateFile(VolumeName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL);

    if (Device == INVALID_HANDLE_VALUE)
    {
        PrintLastError(&VolumeName[4]);
        return -1;
    }

    if (!DeviceIoControl(Device, FSCTL_LOCK_VOLUME, NULL, 0, NULL, 0, &BytesReturned, NULL))
    {
        PrintLastError(&VolumeName[4]);
        CloseHandle(Device);
        return -1;
    }

    if (!DeviceIoControl(Device, IOCTL_FILE_DISK_CLOSE_FILE, NULL, 0, NULL, 0, &BytesReturned, NULL))
    {
        PrintLastError("FileDisk:");
        CloseHandle(Device);
        return -1;
    }

    if (!DeviceIoControl(Device, FSCTL_DISMOUNT_VOLUME, NULL, 0, NULL, 0, &BytesReturned, NULL))
    {
        PrintLastError(&VolumeName[4]);
        CloseHandle(Device);
        return -1;
    }

    if (!DeviceIoControl(Device, FSCTL_UNLOCK_VOLUME, NULL, 0, NULL, 0, &BytesReturned, NULL))
    {
        PrintLastError(&VolumeName[4]);
        CloseHandle(Device);
        return -1;
    }

    CloseHandle(Device);

    if (!DefineDosDevice(DDD_REMOVE_DEFINITION, &VolumeName[4], NULL))
    {
        PrintLastError(&VolumeName[4]);
        return -1;
    }

    SHChangeNotify(SHCNE_DRIVEREMOVED, SHCNF_PATH, DriveName, NULL);

    return 0;
}

int FileDiskStatus(char DriveLetter)
{
    char                    VolumeName[] = "\\\\.\\ :";
    HANDLE                  Device;
    POPEN_FILE_INFORMATION  OpenFileInformation;
    DWORD                   BytesReturned;

    VolumeName[4] = DriveLetter;

    Device = CreateFile(VolumeName, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_NO_BUFFERING, NULL);

    if (Device == INVALID_HANDLE_VALUE)
    {
        PrintLastError(&VolumeName[4]);
        return -1;
    }

    OpenFileInformation = malloc(sizeof(OPEN_FILE_INFORMATION) + MAX_PATH);

    if (!DeviceIoControl(Device, IOCTL_FILE_DISK_QUERY_FILE, NULL, 0, OpenFileInformation, sizeof(OPEN_FILE_INFORMATION) + MAX_PATH, &BytesReturned, NULL))
    {
        PrintLastError(&VolumeName[4]);
        CloseHandle(Device);
        free(OpenFileInformation);
        return -1;
    }

    if (BytesReturned < sizeof(OPEN_FILE_INFORMATION))
    {
        SetLastError(ERROR_INSUFFICIENT_BUFFER);
        PrintLastError(&VolumeName[4]);
        CloseHandle(Device);
        free(OpenFileInformation);
        return -1;
    }

    CloseHandle(Device);

    printf("%c: %.*s %I64u bytes%s\n", DriveLetter, OpenFileInformation->FileNameLength, OpenFileInformation->FileName, OpenFileInformation->FileSize, OpenFileInformation->ReadOnly ? " ro" : "");

    free(OpenFileInformation);

    return 0;
}

int __cdecl main(int argc, char* argv[])
{
    char* Command;
    int DeviceNumber;
    char* FileName;
    char* Option;
    char DriveLetter;
    BOOLEAN CdImage = FALSE;
    POPEN_FILE_INFORMATION OpenFileInformation;

    Command = argv[1];

    if ((argc == 5 || argc == 6) && !strcmp(Command, "/mount"))
    {
        FileName = argv[3];

        if (strlen(FileName) < 2)
			PrintMenu();

        OpenFileInformation = malloc(sizeof(OPEN_FILE_INFORMATION) + strlen(FileName) + 7);

        memset(OpenFileInformation, 0, sizeof(OPEN_FILE_INFORMATION) + strlen(FileName) + 7);

		strcpy(OpenFileInformation->FileName, "\\??\\");
        strcat(OpenFileInformation->FileName, FileName);

        OpenFileInformation->FileNameLength = (USHORT) strlen(OpenFileInformation->FileName);

        if (argc > 5)
        {
            Option = argv[4];
            DriveLetter = argv[5][0];

            if (!strcmp(Option, "/ro"))
                OpenFileInformation->ReadOnly = TRUE;
            else if (!strcmp(Option, "/cd"))
                CdImage = TRUE;
            else
            {
                if (Option[strlen(Option) - 1] == 'G')
                    OpenFileInformation->FileSize.QuadPart = _atoi64(Option) * 1024 * 1024 * 1024;
                else if (Option[strlen(Option) - 1] == 'M')
                    OpenFileInformation->FileSize.QuadPart = _atoi64(Option) * 1024 * 1024;
                else if (Option[strlen(Option) - 1] == 'k')
                    OpenFileInformation->FileSize.QuadPart = _atoi64(Option) * 1024;
                else
                    OpenFileInformation->FileSize.QuadPart = _atoi64(Option);
            }
        }
        else
            DriveLetter = argv[4][0];
        OpenFileInformation->DriveLetter = DriveLetter;
        DeviceNumber = atoi(argv[2]);
        return FileDiskMount(DeviceNumber, OpenFileInformation, CdImage);
    }
    else if (argc == 3 && !strcmp(Command, "/unmount"))
    {
        DriveLetter = argv[2][0];
        return FileDiskUmount(DriveLetter);
    }
	else if (argc == 3 && !strcmp(Command, "/status"))
	{
		DriveLetter = argv[2][0];
		return FileDiskStatus(DriveLetter);
	}
	else PrintMenu();
}
