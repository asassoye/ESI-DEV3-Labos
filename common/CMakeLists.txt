project(dev3 C CXX)

add_library(mathesi
        src/mathesi.h
        src/mathesi.c
        )

add_library(
        mathesicpp
        src/mathesi.hpp
        src/mathesi.cpp
)

add_library(
        utilscpp
        src/utilscpp.hpp
        src/utilscpp.cpp
)
