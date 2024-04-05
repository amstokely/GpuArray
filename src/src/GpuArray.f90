module GpuArray_mod
    use iso_c_binding, only : c_int, c_ptr
    implicit none

    type, bind(C) :: GpuArray
        type(c_ptr) :: data
        integer(c_int) :: size
    end type GpuArray

    interface
        subroutine GpuArray_allocate(self, size) bind(C, name = "GpuArray_allocate")
            import :: GpuArray
            type(GpuArray), intent(out) :: self
            integer, intent(in) :: size
        end subroutine GpuArray_allocate

        subroutine GpuArray_deallocate(self) bind(C, name = "GpuArray_deallocate")
            import :: GpuArray
            type(GpuArray), intent(inout) :: self
        end subroutine GpuArray_deallocate

        subroutine GpuArray_set(self, index, value) bind(C, name = "GpuArray_set")
            import :: GpuArray
            type(GpuArray), intent(inout) :: self
            integer, intent(in) :: index
            real, intent(in) :: value
        end subroutine GpuArray_set

        function GpuArray_get(self, index) result(value) bind(C, name = "GpuArray_get")
            import :: GpuArray
            type(GpuArray), intent(in) :: self
            integer, intent(in) :: index
            real :: value
        end function GpuArray_get

        function GpuArray_size(self) result(size) bind(C, name = "GpuArray_size")
            import :: GpuArray
            type(GpuArray), intent(in) :: self
            integer :: size
        end function GpuArray_size
    end interface

end module GpuArray_mod

