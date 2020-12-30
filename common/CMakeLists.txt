project(dev3 C CXX)


#########################################################################################
# MATHESI LIBRARY
#########################################################################################
add_library(mathesi
        src/mathesi.h
        src/mathesi.c
        )
target_link_libraries(mathesi ${MATH_LIBRARIES})

#########################################################################################
# MATHESICPP LIBRARY
#########################################################################################
set(MCPP_HEADERS
        src/mathesi.hpp
        )

set(MCPP_SOURCES
        src/mathesi.cpp
        )

set(MCPP_TESTS
        test/tests-main.cpp
        test/mathesicpptest.cpp
        )

add_library(mathesicpp ${MCPP_HEADERS} ${MCPP_SOURCES})

add_executable(mathesicpptest ${MCPP_TESTS})
target_link_libraries(mathesicpptest Catch2::Catch2 mathesicpp)
add_test(NAME MathESITest COMMAND mathesicpptest)

#########################################################################################
# UTILSCPP LIBRARY
#########################################################################################
add_library(
        utilscpp
        src/utilscpp.hpp
        src/utilscpp.cpp
)

#########################################################################################
# TESTING
#########################################################################################






