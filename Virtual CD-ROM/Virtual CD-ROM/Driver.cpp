/*
NTSTATUS DriverEntry(IN PDRIVER_OBJECT DriverObject,
                     IN PUNICODE_STRING RegistryPath)
{

    NTSTATUS status;
    status = IoCreateDevice(DriverObject,     
                            0,                
                            &gDeviceName,    
                            FILE_DEVICE_NULL, 
                            0,                
                            FALSE,            
                            &gDeviceObject);  
    if (status != STATUS_SUCCESS)
        return STATUS_FAILED_DRIVER_ENTRY;
	for (size_t i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; ++i) 
        DriverObject->MajorFunction[i] = //обработчики;
    return STATUS_SUCCESS;
}*/