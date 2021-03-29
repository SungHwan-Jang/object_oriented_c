cmake_minimum_required(VERSION 3.17)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(myself)

add_executable(src
        myself/db_read.c
        myself/db_read.h
        myself/file_read.c
        myself/file_read.h
        file_reader.c
        file_reader.h
        main.c
        range.c
        range.h)
