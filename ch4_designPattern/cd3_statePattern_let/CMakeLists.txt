cmake_minimum_required(VERSION 3.17)
project(cd3_statePattern_let C)

set(CMAKE_C_STANDARD 99)

add_executable(cd3_statePattern_let main.c state_pattern.c state_pattern.h self_state.c self_state.h)