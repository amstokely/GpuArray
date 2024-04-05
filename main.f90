program MainProgram
    use GpuArray_mod
    implicit none
    type(GpuArray) :: gpu_array
    real :: value
    integer :: i, index

    call GpuArray_allocate(gpu_array, 10)
    call GpuArray_allocateDevice(gpu_array)


    value = 1.0
    index = 1

    do i = 1, 10
        call GpuArray_set(gpu_array, index, value)
        index = index + 1
        value = value + 1.0
    end do
    call GpuArray_toDevice(gpu_array)
    index = 1
    do i = 1, 10
        call GpuArray_set(gpu_array, index, value)
        index = index + 1
        value = value + 1.0
    end do
    index = 1
    do i = 1, 10
        print *, GpuArray_get(gpu_array, index)
        index = index + 1
    end do
    call GpuArray_toHost(gpu_array)
    index = 1
    do i = 1, 10
        print *, GpuArray_get(gpu_array, index)
        index = index + 1
    end do
    call GpuArray_deallocate(gpu_array)
    call GpuArray_deallocateDevice(gpu_array)

end program MainProgram
