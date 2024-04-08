#include "GpuArray.h"
#include <iostream>

__global__ void sumReductionKernel(
        float *a,
        float *r,
        int size
) {
    __shared__ float sharedData[1024];

    // Thread index
    unsigned int tid = threadIdx.x;

    // Global index
    unsigned int index = blockIdx.x * blockDim.x + tid;

    unsigned int stride;

    if (index < size) {
        sharedData[tid] = a[index];
    }
    else {
        sharedData[tid] = 0.0;
    }
    __syncthreads();
    for (stride = blockDim.x / 2; stride >0; stride >>=1) {
        if (tid < stride) {
            sharedData[tid] += sharedData[tid + stride];
        }
        __syncthreads();
    }
    if (tid == 0) {
        r[blockIdx.x] = sharedData[0];
    }
}

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

float GpuArray_sumReduction_Cuda(GpuArray *gpuArray) {
    int numThreads = 1024;
    int numBlocks, i;
    GpuArray *rArray;
    float r;
    numBlocks = (gpuArray->size / numThreads) + 1;
    rArray = new GpuArray;
    rArray->allocate(&numBlocks);
    rArray->allocateDevice();
    sumReductionKernel<<<numBlocks, numThreads>>>(
            gpuArray->deviceData,
            rArray->deviceData,
            gpuArray->size

    );
    rArray->toHost();
    r = 0.0;
    for (i = 0; i <numBlocks; i++) {
        r += (*(rArray->data))[i];
    }
    rArray->deallocateDevice();
    rArray->deallocate();
    delete rArray;
    return r;
}

