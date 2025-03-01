cmake_minimum_required(VERSION 3.10)

# Project name and version
project(StudentDatabase VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the main executable
add_executable(StudentDatabase main.cpp)

# Add the test executable
add_executable(test_executable test.cpp)

# Link Google Test libraries
target_link_libraries(test_executable gtest gtest_main)

# Add include directories for Google Test
target_include_directories(test_executable PRIVATE ${GTEST_INCLUDE_DIRS})

# Enable testing
enable_testing()

# Add the test
add_test(NAME ExampleTest COMMAND test_executable)
