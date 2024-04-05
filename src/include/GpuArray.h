//
// Created by astokely on 4/5/24.
//

#ifndef GPUARRAY_GPUARRAY_C_H
#define GPUARRAY_GPUARRAY_C_H


extern "C" {
struct GpuArray {
    float **data;
    int size;
};
void GpuArray_allocate(GpuArray *self, int *size);

void GpuArray_deallocate(GpuArray *self);

void GpuArray_set(GpuArray *self, int *index, float *value);

float GpuArray_get(GpuArray *self, int *index);

int GpuArray_size(GpuArray *self);


}

#endif //GPUARRAY_GPUARRAY_C_H
