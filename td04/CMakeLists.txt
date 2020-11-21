cmake_minimum_required(VERSION 3.16)
project(dev3 CXX)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pedantic -lm")

add_library(td04_lib
        src/td04.h
        src/td04.c
        src/PrimeFactor.c
        src/PrimeFactor.h
        src/PrimeFactorization.c src/PrimeFactorization.h)

add_executable(td04 src/main.c)
target_link_libraries(td04
        PUBLIC
            td04_lib
            mathesi
        )
