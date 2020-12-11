cmake_minimum_required(VERSION 3.16)
project(dev3 CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -lm")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_library(
        mathesicpp
        src/mathesi.cpp
)

add_library(
        utilscpp
        src/utils.h
        src/utils.cpp
)

add_executable(
        td06
        src/main.cpp
)

target_link_libraries(td06 PUBLIC mathesicpp utilscpp)
