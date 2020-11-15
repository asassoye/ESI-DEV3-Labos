cmake_minimum_required(VERSION 3.16)
project(dev3 C)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pedantic -lm")

add_executable(td04 src/main.c src/td04.c src/td04.h ../../td01/src/mathesi.h ../../td01/src/mathesi.c)
