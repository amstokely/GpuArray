cmake_minimum_required(VERSION 3.20)
project(GpuArray LANGUAGES CXX C Fortran)

set(CMAKE_CXX_STANDARD 17)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/include)

set(GPU_ARRAY_LIB_FORTRAN_SRC_FILES ${SRC_DIR}/GpuArray.f90)
set(GPU_ARRAY_LIB_C_SRC_FILES ${SRC_DIR}/GpuArray.cpp)

include_directories(${INCLUDE_DIR})

add_library(
        GpuArray_CLib
        SHARED
        ${GPU_ARRAY_LIB_C_SRC_FILES}
)
set_target_properties(
        GpuArray_CLib
        PROPERTIES
        LINKER_LANGUAGE CXX
)
add_library(
        GpuArrayFortranLib
        SHARED
        ${GPU_ARRAY_LIB_FORTRAN_SRC_FILES}
)
set_target_properties(
        GpuArrayFortranLib
        PROPERTIES
        LINKER_LANGUAGE Fortran
)

target_link_libraries(
        GpuArrayFortranLib
        GpuArray_CLib
)

add_executable(
        GpuArray_C
        main.cpp
)

set_target_properties(
        GpuArray_C
        PROPERTIES
        LINKER_LANGUAGE CXX
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)

target_link_libraries(
        GpuArray_C
        GpuArray_CLib
)

add_executable(
        GpuArray_F
        main.f90
)
set_target_properties(
        GpuArray_F
        PROPERTIES
        LINKER_LANGUAGE Fortran
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
target_link_libraries(
        GpuArray_F
        GpuArrayFortranLib
        GpuArray_CLib
)
