project(dev3 CXX)

add_library(
        td07_lib
        src/td07.cpp
)

add_executable(
        td07
        src/main.cpp
)

target_link_libraries(td07 PUBLIC td07_lib mathesicpp utilscpp)
