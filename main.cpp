#include <iostream>
#include "GpuArray.h"

int main() {
    GpuArray gpuArray;
    int size = 10;
    GpuArray_allocate(&gpuArray, &size);
    for (int i = 0; i < GpuArray_size(&gpuArray); i++) {
        float value = (float)i;
        GpuArray_set(&gpuArray, &i, &value);
    }
    for (int i = 0; i < GpuArray_size(&gpuArray); i++) {
        std::cout << GpuArray_get(&gpuArray, &i) << std::endl;
    }
    GpuArray_deallocate(&gpuArray);

    return 0;
}
