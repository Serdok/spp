cmake_minimum_required(VERSION 3.17)
project(SocketPP)

# Options
option(SPP_BUILD_TESTS "Configure CMake to build test targets" OFF)

# Variables
set(CMAKE_CXX_STANDARD 20)

# Library setup
add_library(${PROJECT_NAME} SHARED)
add_subdirectory(src)

# Library parameters
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_include_directories(${PROJECT_NAME} PRIVATE src/)


# Test setup
if (SPP_BUILD_TESTS)
    add_subdirectory(test)
endif ()