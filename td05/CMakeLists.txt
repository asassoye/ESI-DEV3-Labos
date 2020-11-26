cmake_minimum_required(VERSION 3.16)
project(dev3 C)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pedantic -lm")

add_library(slnode src/slnode.c)
add_library(slnode_utility src/slnode_utility.c)
add_library(slcircularlist src/slcircularlist.c)
add_library(slcircularlist_utility src/slcircularlist_utility.c)

add_executable(
        td05
        src/main.c
        src/value_t.h
)
target_link_libraries(
        td05 PUBLIC
        slnode
        slnode_utility
        slcircularlist
        slcircularlist_utility
)