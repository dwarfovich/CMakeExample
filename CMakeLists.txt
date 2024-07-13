cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.5.${PATCH_VERSION})

project(CMakeExample VERSION ${PROJECT_VERSION})

set(PROJECT_NAME_UPPERCASE "CMAKE_EXAMPLE")

add_executable(run_example src/main.cpp)
configure_file(headers/project_metadata.h.in project_metadata.h)
target_include_directories(run_example PUBLIC "${PROJECT_BINARY_DIR}" "headers")

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(run_example_compiler_flags INTERFACE)
target_compile_features(run_example_compiler_flags INTERFACE cxx_std_20)

add_subdirectory(mylib/)
#target_link_libraries(run_example PUBLIC MyLib)
target_link_libraries(run_example PUBLIC MyLib run_example_compiler_flags)