cmake_minimum_required(VERSION 3.16)
project(dev3 C CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic -lm")

add_subdirectory("${PROJECT_SOURCE_DIR}/common" "${PROJECT_SOURCE_DIR}/common/build/${CMAKE_BUILD_TYPE}")

add_subdirectory("${PROJECT_SOURCE_DIR}/td01" "${PROJECT_SOURCE_DIR}/td01/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td02" "${PROJECT_SOURCE_DIR}/td02/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td03" "${PROJECT_SOURCE_DIR}/td03/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td04" "${PROJECT_SOURCE_DIR}/td04/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td05" "${PROJECT_SOURCE_DIR}/td05/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td06" "${PROJECT_SOURCE_DIR}/td06/build/${CMAKE_BUILD_TYPE}")
add_subdirectory("${PROJECT_SOURCE_DIR}/td07" "${PROJECT_SOURCE_DIR}/td07/build/${CMAKE_BUILD_TYPE}")

add_subdirectory("${PROJECT_SOURCE_DIR}/i1" "${PROJECT_SOURCE_DIR}/i1/build")
