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

set(F_HEADERS src/fraction.hpp)

set(F_SOURCES src/fraction.cpp)

set(FCE_HEADERS src/fraction_constexpr.hpp)

set(F_TESTS
        resources/tests-main.cpp
        test/fractiontest.cpp
        )

set(FCE_TESTS resources/tests-main.cpp test/fraction_constexprTest.cpp)

add_library(fraction ${S_HEADERS} ${S_SOURCES})

add_executable(td08 src/main.cpp)
target_link_libraries(td08 PUBLIC fraction utilscpp)

add_executable(signtest ${S_TESTS})
target_link_libraries(signtest Catch2::Catch2 fraction)
add_test(NAME SignTest COMMAND signtest)

add_executable(fractiontest ${F_TESTS} ${F_SOURCES} resources/data_fraction.cpp)
target_link_libraries(fractiontest Catch2::Catch2 fraction mathesicpp)
add_test(NAME FractionTest COMMAND fractiontest)

add_executable(fractionConstexprTest ${FCE_TESTS} resources/data_fraction.cpp)
target_link_libraries(fractionConstexprTest Catch2::Catch2 fraction mathesicpp)
add_test(NAME FractionConstExprTest COMMAND fractionConstexprTest)
