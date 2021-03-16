cmake_minimum_required(VERSION 3.17)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        buffer.c
        buffer.h
        file_accessor.c
        file_accessor.h
        int_sorter.c
        int_sorter.h
        main.c)
