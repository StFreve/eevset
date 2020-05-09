cmake_minimum_required(VERSION 3.10)

########################################
# Project setup
########################################
set(PROJECT_NAME eevset)
project(${PROJECT_NAME})
# After project(..) is called, the following variables are available:
# * PROJECT_SOURCE_DIR - Top level source directory for the project
# * PROJECT_BINARY_DIR - Full path to build directory for project

########################################
# Set up the compiler flags
########################################
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQURED True)

########################################
# Main is separate (e.g. library client)
########################################
add_executable(eevset ${PROJECT_SOURCE_DIR}/src/eevset.cpp)

########################################
# Testing
########################################
# Options. Turn on with 'cmake -Dmyvarname=ON'.
# option(BUILD_TESTS "Build all tests." ON) # Makes boolean 'test' available.

# google test is a git submodule for the project, and it is also cmake-based
add_subdirectory(./googletest)

enable_testing()
# 
# Include the gtest library. gtest_SOURCE_DIR is available due to
# 'project(gtest)' above.
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
 
########################################
# Test files
########################################
file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)

########################################
# Unit Tests
########################################
add_executable(unit_test ${TEST_SRC_FILES})

########################################
# Standard linking to gtest stuff.
########################################
target_link_libraries(unit_test gtest gtest_main)

########################################
# Extra linking for the project.
########################################
# target_link_libraries(unit_test project1_lib)

# This is so you can do 'make test' to see all your tests run, instead of
# manually running the executable runUnitTests to see those specific tests.
add_test(UnitTests unit_test)