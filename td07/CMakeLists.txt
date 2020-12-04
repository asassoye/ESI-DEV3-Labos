cmake_minimum_required(VERSION 3.16)
project(dev3 CXX)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -lm")

add_library(
        td07_lib
        src/td07.cpp
)

add_executable(
        td07
        src/main.cpp
)

target_link_libraries(td07 PUBLIC td07_lib)
