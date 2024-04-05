//
// Created by astokely on 4/5/24.
//

#ifndef GPUARRAY_GPUARRAY_C_H
#define GPUARRAY_GPUARRAY_C_H


extern "C" {
struct GpuArray {
    float **data;
    float *deviceData;
    int size;
};
void GpuArray_allocate(GpuArray *self, int *size);

void GpuArray_deallocate(GpuArray *self);

void GpuArray_set(GpuArray *self, int *index, float *value);

float GpuArray_get(GpuArray *self, int *index);

int GpuArray_size(GpuArray *self);

void GpuArray_allocateDevice_Cuda(GpuArray *self);

void GpuArray_allocateDevice(GpuArray *self);

void GpuArray_deallocateDevice_Cuda(GpuArray *self);

void GpuArray_deallocateDevice(GpuArray *self);

void GpuArray_toDevice_Cuda(GpuArray *self);

void GpuArray_toDevice(GpuArray *self);

void GpuArray_toHost_Cuda(GpuArray *self);

void GpuArray_toHost(GpuArray *self);


}

#endif //GPUARRAY_GPUARRAY_C_H
