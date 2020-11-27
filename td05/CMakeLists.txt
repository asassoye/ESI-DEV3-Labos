cmake_minimum_required(VERSION 3.16)
project(dev3 C)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -pedantic -lm")


add_library(
        slcircularlist
        src/slnode.c
        src/slnode_utility.c
        src/slcircularlist.c
        src/slcircularlist_utility.c
)

add_executable(
        td05
        src/main.c
        src/value_t.h
)
target_link_libraries(td05 PUBLIC slcircularlist)