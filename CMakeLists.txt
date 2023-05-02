cmake_minimum_required(VERSION 3.25)
project(VectorMath C)

set(CMAKE_C_STANDARD 11)

add_executable(VectorMath main.c Vector3.c Vector3.h)
