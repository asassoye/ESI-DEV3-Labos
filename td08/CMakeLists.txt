project(dev3 CXX)

set(S_HEADERS
        src/sign.hpp
        )

set(S_SOURCES
        src/sign.cpp
        )

set(S_TESTS
        resources/tests-main.cpp
        test/signtest.cpp
        )

add_library(sign ${S_HEADERS} ${S_SOURCES})

add_executable(td08 src/main.cpp)
target_link_libraries(td08 PUBLIC sign utilscpp)

add_executable(signtest ${S_TESTS})
target_link_libraries(signtest Catch2::Catch2 sign)
add_test(NAME SignTest COMMAND signtest)
