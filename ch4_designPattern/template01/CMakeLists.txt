cmake_minimum_required(VERSION 3.17)
project(template01 C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(template01
        src/range.c
        src/range.h main.c)
