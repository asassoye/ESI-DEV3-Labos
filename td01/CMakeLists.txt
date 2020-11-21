cmake_minimum_required(VERSION 3.16)
project(dev3 C)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pedantic -lm")

add_library(mathesi
        src/mathesi.h
        src/mathesi.c
        )

add_executable(td01 src/main.c)
target_link_libraries(td01 PUBLIC mathesi)
