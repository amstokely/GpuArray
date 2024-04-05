#include <iostream>
#include "GpuArray.h"

int main() {
    GpuArray gpuArray;
    int size = 10;
    GpuArray_allocate(&gpuArray, &size);
    GpuArray_allocateDevice(&gpuArray);

    for (int i = 0; i < GpuArray_size(&gpuArray); i++) {
        float value = (float)i;
        GpuArray_set(&gpuArray, &i, &value);
    }
    GpuArray_toDevice(&gpuArray);
    for (int i = 0; i < GpuArray_size(&gpuArray); i++) {
        float value = (float)i+10.0;
        GpuArray_set(&gpuArray, &i, &value);
    }
    GpuArray_toHost(&gpuArray);
    for (int i = 0; i < GpuArray_size(&gpuArray); i++) {
        std::cout << GpuArray_get(&gpuArray, &i) << std::endl;
    }
    GpuArray_toHost(&gpuArray);
    GpuArray_deallocate(&gpuArray);

    return 0;
}
