cmake_minimum_required(VERSION 3.30)
project(KP_8 C)

set(CMAKE_C_STANDARD 99)

add_executable(KP_8 main.c
        calculation.h
        complex.h
        validation.h)
