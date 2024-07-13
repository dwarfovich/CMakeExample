add_library(MyLib src/lib_functions.cpp)
target_link_libraries(MyLib PUBLIC run_example_compiler_flags)
target_include_directories(MyLib PRIVATE "mylib")
target_include_directories(MyLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})