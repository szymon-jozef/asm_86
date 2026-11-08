cmake_minimum_required(VERSION 3.29)

project(asm LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)


add_compile_options(-g -m32 -fasm-blocks -fms-extensions -masm=intel)
add_link_options(-m32)

add_executable(asm ./src/main.cpp)
