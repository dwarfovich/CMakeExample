@echo off

cmake -B build || exit /b
cmake --build build || exit /b
build\Debug\run_example.exe