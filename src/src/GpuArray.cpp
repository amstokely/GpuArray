#include "GpuArray.h"

//
// Created by astokely on 4/5/24.
//

#include "GpuArray.h"

void GpuArray_allocate(GpuArray *self, int *size) {
    self->size = *size;
    self->data = new float *;
    *self->data = new float[*size];
    for (int i = 0; i < *size; i++) {
        (*self->data)[i] = 0.0;
    }
}
void GpuArray_deallocate(GpuArray *self) {
    delete[] *self->data;
    delete self->data;
}

void GpuArray_set(GpuArray *self, int *index, float *value) {
    (*self->data)[*index] = *value;
}

float GpuArray_get(GpuArray *self, int *index) {
    return (*self->data)[*index];
}

int GpuArray_size(GpuArray *self) {
    return self->size;
}

