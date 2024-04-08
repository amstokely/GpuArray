#include "GpuArray.h"

void GpuArray::allocate(int *size) {
    GpuArray_allocate(this, size);
}

void GpuArray::deallocate() {
    GpuArray_deallocate(this);
}

void GpuArray::set(
        int *index,
        float *value
) {
    int fortranIndex = *index + 1;
    GpuArray_set(this, &fortranIndex, value);
}

float GpuArray::get(
    int *index
) {
    int fortranIndex = *index + 1;
    return GpuArray_get(this, &fortranIndex);
}

void GpuArray::toDevice() {
    GpuArray_toDevice(this);
}

void GpuArray::toHost() {
    GpuArray_toHost(this);
}

void GpuArray::allocateDevice() {
    GpuArray_allocateDevice(this);
}

void GpuArray::deallocateDevice() {
    GpuArray_deallocateDevice(this);
}
