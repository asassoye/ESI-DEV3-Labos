cmake_minimum_required(VERSION 3.16)
project(dev3 CXX)

add_executable(
        td06
        src/main.cpp
)

target_link_libraries(td06 PUBLIC mathesicpp utilscpp)
