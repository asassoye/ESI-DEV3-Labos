project(dev3 CXX)

add_executable(
        td08
        src/main.cpp
)

target_link_libraries(td08 PUBLIC utilscpp)
