add_library(MyLib src/lib_functions.cpp)
#target_include_directories(MyLib PUBLIC "mylib")
target_include_directories(MyLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})