cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.5.${PATCH_VERSION})
set(PROJECT_NAME_UPPERCASE "CMAKE_EXAMPLE")
project(CMakeExample VERSION ${PROJECT_VERSION})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/lib>)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/lib>)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<1:${CMAKE_BINARY_DIR}/bin>)

add_executable(run_example src/main.cpp)
configure_file(headers/project_metadata.h.in project_metadata.h)
target_include_directories(run_example PUBLIC "${PROJECT_BINARY_DIR}" "headers")

#set(CMAKE_CXX_STANDARD 20)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

# Libraries
add_library(run_example_compiler_flags INTERFACE)
target_compile_features(run_example_compiler_flags INTERFACE cxx_std_20)
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(run_example_compiler_flags INTERFACE
  "$<${gcc_like_cxx}:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>"
  "$<${msvc_cxx}:-Wall>"
)

add_subdirectory(mylib/)
#target_link_libraries(run_example PUBLIC MyLib)
target_link_libraries(run_example PUBLIC MyLib run_example_compiler_flags)

# Tests
enable_testing()

add_test(NAME Runs COMMAND run_example 25)
add_test(NAME Usage COMMAND run_example)
set_tests_properties(Usage PROPERTIES PASS_REGULAR_EXPRESSION "Version")