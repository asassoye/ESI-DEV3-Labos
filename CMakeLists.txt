cmake_minimum_required(VERSION 3.17.3)
project(dev3 C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 17)

if (NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic")
endif ()

if (NOT WIN32)
    find_library(MATH_LIBRARIES
            NAMES m
            PATHS /usr/lib /usr/local/lib
            )
    if (NOT MATH_LIBRARIES)
        message("Cannot find libm")
    endif ()
else ()
    set(MATH_LIBRARIES "")
endif ()

#########################################################################################
# TESTING
#########################################################################################
find_package(Catch2 QUIET)
if (NOT Catch2_FOUND)
    message("Catch not found, downloading from git.")
    Include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v2.13.1)
    FetchContent_MakeAvailable(Catch2)
endif ()
include(CTest)

#########################################################################################
# COMMON LIBRARIES
#########################################################################################
add_subdirectory("${PROJECT_SOURCE_DIR}/common" "${PROJECT_SOURCE_DIR}/common/build/${CMAKE_BUILD_TYPE}")

#########################################################################################
# LABS
#########################################################################################
add_subdirectory("${PROJECT_SOURCE_DIR}/td01" "${PROJECT_SOURCE_DIR}/td01/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td02" "${PROJECT_SOURCE_DIR}/td02/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td03" "${PROJECT_SOURCE_DIR}/td03/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td04" "${PROJECT_SOURCE_DIR}/td04/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td05" "${PROJECT_SOURCE_DIR}/td05/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td06" "${PROJECT_SOURCE_DIR}/td06/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td07" "${PROJECT_SOURCE_DIR}/td07/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td08" "${PROJECT_SOURCE_DIR}/td08/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td09" "${PROJECT_SOURCE_DIR}/td09/build/${CMAKE_BUILD_TYPE}")

#########################################################################################
# INTERROGATIONS
#########################################################################################
add_subdirectory("${PROJECT_SOURCE_DIR}/i1" "${PROJECT_SOURCE_DIR}/i1/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/i2" "${PROJECT_SOURCE_DIR}/i2/build/${CMAKE_BUILD_TYPE}")
