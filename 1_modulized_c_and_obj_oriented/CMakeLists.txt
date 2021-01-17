# cmake_minimum_required(VERSION <specify CMake version here>)
project(1_modulized_c_and_obj_oriented C)

set(CMAKE_C_STANDARD 99)

add_executable(1_modulized_c_and_obj_oriented main.c regarcy_stack.c regarcy_stack.h step1.c step1.h step2.c step2.h)