cmake_minimum_required(VERSION 3.10)
project(LeetCodeExercises)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include Boost using vcpkg
set(BOOST_ROOT "C:/Program Files/vcpkg/installed/x64-mingw-dynamic")
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Include directories for Boost
include_directories(${Boost_INCLUDE_DIRS})

# Variable to specify the active problem
set(ACTIVE_PROBLEM "128.LongestConsecutiveSequence")  # Change this to the folder of the current problem

# Define source file paths relative to the exercise folder
set(EXERCISE_DIR ${CMAKE_SOURCE_DIR}/exercises/${ACTIVE_PROBLEM})

# Source files for main_program
set(MAIN_PROGRAM_SOURCES
    ${EXERCISE_DIR}/functions.cpp
    ${EXERCISE_DIR}/main.cpp
)

# Source files for test_program
set(TEST_PROGRAM_SOURCES
    ${EXERCISE_DIR}/functions.cpp
    ${EXERCISE_DIR}/test.cpp
)

# Add executables
add_executable(main_program ${MAIN_PROGRAM_SOURCES})
add_executable(test_program ${TEST_PROGRAM_SOURCES})

# Link Boost to test_program
target_link_libraries(test_program ${Boost_LIBRARIES})

# Set custom output directory for executables
set(CUSTOM_OUTPUT_DIR ${CMAKE_SOURCE_DIR}/bin)
set_target_properties(main_program PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_OUTPUT_DIR})
set_target_properties(test_program PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_OUTPUT_DIR})
