cmake_minimum_required(VERSION 3.17)
project(src C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(src
        cdplayer.c
        cdplayer.h main.c)
