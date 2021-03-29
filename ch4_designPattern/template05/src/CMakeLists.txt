cmake_minimum_required(VERSION 3.17)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        main.c
        file_reader.c
        file_reader.h
        range.c
        range.h)
