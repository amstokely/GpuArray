#include "GpuArray.h"
#include <iostream>

void GpuArray_allocateDevice_Cuda(GpuArray *gpuArray) {
    cudaMalloc((void **) &gpuArray->deviceData,
               sizeof(float) * gpuArray->size
    );
}

void GpuArray_deallocateDevice_Cuda(GpuArray *gpuArray) {
    cudaFree(gpuArray->deviceData);
}


void GpuArray_toHost_Cuda(GpuArray *gpuArray) {
    cudaMemcpy(
            *(gpuArray->data),
            gpuArray->deviceData,
            sizeof(float) * gpuArray->size,
            cudaMemcpyDeviceToHost
    );
}

void GpuArray_toDevice_Cuda(GpuArray *gpuArray) {
    cudaMemcpy(
            gpuArray->deviceData,
            *(gpuArray->data),
            sizeof(float) * gpuArray->size,
            cudaMemcpyHostToDevice
    );
}


