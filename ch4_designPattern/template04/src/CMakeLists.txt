cmake_minimum_required(VERSION 3.17)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        file_reader.c
        file_reader.h
        range.c
        range.h
        main.c)
