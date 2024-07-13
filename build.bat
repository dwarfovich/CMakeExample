@echo off

cmake -B build
cmake --build build
build\Debug\run_example.exe