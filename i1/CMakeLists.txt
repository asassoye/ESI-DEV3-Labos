cmake_minimum_required(VERSION 3.16)
project(dev3 C)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pedantic -lm")

add_executable(interro1 src/main.c src/primestat.c src/primestat.h)
target_link_libraries(interro1 PUBLIC td04_lib mathesi)
