cmake_minimum_required(VERSION 3.0)
project(brainfuck C)

set(CMAKE_C_STANDARD 99)
SET(CMAKE_C_FLAGS  "-O2")
add_executable(brainfuck main.c brainfuck.c instructions.c)