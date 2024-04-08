program MainProgram
    use GpuArray_mod
    implicit none
    type(GpuArray) :: gpu_array
    real :: value
    integer :: i, index, size

    size = 10240
    call GpuArray_allocate(gpu_array, size)
    call GpuArray_allocateDevice(gpu_array)


    value = 1.0
    index = 1

    do i = 1, size
        call GpuArray_set(gpu_array, index, value)
        index = index + 1
        value = value + 1.0
    end do
    call GpuArray_toDevice(gpu_array)
    value = GpuArray_sumReduction(gpu_array)
    print *, value



end program MainProgram
