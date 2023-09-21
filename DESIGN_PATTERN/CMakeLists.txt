cmake_minimum_required(VERSION 3.26)
project(A_01_Singleton_Pattern C)

set(CMAKE_C_STANDARD 99)

add_executable(A_01_Singleton_Pattern singleton.c
        main.c
        compile_option.h
        decorator.c)
