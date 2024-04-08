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

    void allocate(int *size);

    void deallocate();

    void toDevice();

    void toHost();

    void set(
            int *index,
            float *value
    );

    float get(
            int *index
    );

    void allocateDevice();

    void deallocateDevice();

    float sumReduction();

};

void GpuArray_deallocateDevice_Cuda(GpuArray *self);

void GpuArray_allocateDevice_Cuda(GpuArray *self);

void GpuArray_toDevice_Cuda(GpuArray *self);

void GpuArray_toHost_Cuda(GpuArray *self);

float GpuArray_sumReduction_Cuda(GpuArray *self);

void GpuArray_allocate(
        GpuArray *self,
        int *size
) {
    self->size = *size;
    self->data = new float *;
    *self->data = new float[*size];
    for (int i = 0; i < *size; i++) {
        (*(self->data))[i] = 0.0;
    }
}
void GpuArray_deallocate(GpuArray *self) {
    delete[] *self->data;
    delete self->data;
}

void GpuArray_set(
        GpuArray *self,
        int *index,
        float *value
) {
    (*self->data)[*index-1] = *value;
}

float GpuArray_get(
        GpuArray *self,
        int *index
) {
    return (*self->data)[*index-1];
}

int GpuArray_size(GpuArray *self) {
    return self->size;
}

void GpuArray_allocateDevice(GpuArray *self) {
    GpuArray_allocateDevice_Cuda(self);
}

void GpuArray_deallocateDevice(GpuArray *self) {
    GpuArray_deallocateDevice_Cuda(self);
}

void GpuArray_toDevice(GpuArray *self) {
    GpuArray_toDevice_Cuda(self);
}

void GpuArray_toHost(GpuArray *self) {
    GpuArray_toHost_Cuda(self);
}

float GpuArray_sumReduction(GpuArray *self) {
    return GpuArray_sumReduction_Cuda(self);
}
}

#endif //GPUARRAY_GPUARRAY_C_H
