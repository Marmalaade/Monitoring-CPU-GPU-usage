#define GPUUSAGE_H
#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <QApplication>
#include <QFile>
#include <QProgressDialog>
#include <nvml.h>
#pragma comment(lib, "nvml")

class GPUusage:public QProgressDialog{
protected:


public :
    GPUusage();
protected:

virtual void timerEvent(QTimerEvent *)
{
    nvmlReturn_t result;
    unsigned int device_count;

    result = nvmlInit();
    if (result != NVML_SUCCESS)
        return;

    result = nvmlDeviceGetCount(&device_count);
    if (result != NVML_SUCCESS)
        return;

    for ( unsigned int i = 0; i < device_count; ++i) {
        nvmlDevice_t device;
        result = nvmlDeviceGetHandleByIndex(0, &device);
        if (result != NVML_SUCCESS)
            return;

//        char device_name[NVML_DEVICE_NAME_BUFFER_SIZE];
//        result = nvmlDeviceGetName(device, device_name, NVML_DEVICE_NAME_BUFFER_SIZE);
//        if (result != NVML_SUCCESS)
//            return 4;

//        std::printf("Device %d: %s\n", i, device_name);

        nvmlUtilization_st device_utilization;
        result = nvmlDeviceGetUtilizationRates(device, &device_utilization);

        if (result != NVML_SUCCESS)
            return;

        //std::printf("GPU Util: %u, device_utilization.gpu);
          setValue( device_utilization.gpu);
        }
    nvmlShutdown();

};
