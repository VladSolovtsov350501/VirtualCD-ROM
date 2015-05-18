#include <windef.h>

#ifndef _VCDROM_
#define _VCDROM_

#define VCDROM_POOL_TAG 'ksiD'

#ifndef __T
#ifdef _NTDDK_
#define __T(x)  L ## x
#else
#define __T(x)  x
#endif
#endif

#ifndef _T
#define _T(x)   __T(x)
#endif

#define DEVICE_BASE_NAME    _T("\\vcdrom")
#define DEVICE_DIR_NAME     _T("\\Device")      DEVICE_BASE_NAME
#define DEVICE_NAME_PREFIX  DEVICE_DIR_NAME     DEVICE_BASE_NAME

#define FILE_DEVICE_VCDROM       0x8000

#define IOCTL_VCDROM_OPEN_FILE   CTL_CODE(FILE_DEVICE_VCDROM, 0x800, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VCDROM_CLOSE_FILE  CTL_CODE(FILE_DEVICE_VCDROM, 0x801, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
#define IOCTL_VCDROM_QUERY_FILE  CTL_CODE(FILE_DEVICE_VCDROM, 0x802, METHOD_BUFFERED, FILE_READ_ACCESS)

typedef struct _OPEN_FILE_INFORMATION {
    LARGE_INTEGER   FileSize;
    BOOLEAN         ReadOnly;
    UCHAR           DriveLetter;
    USHORT          FileNameLength;
    UCHAR           FileName[1];
} OPEN_FILE_INFORMATION, *POPEN_FILE_INFORMATION;

#endif
