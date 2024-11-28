# Generic CMakeLists.txt for LeetCode Exercises
# Instructions to build:
# 1. Create a build directory: `mkdir build && cd build`
# 2. Run CMake: `cmake -DCMAKE_TOOLCHAIN_FILE="<path_to_vcpkg>/scripts/buildsystems/vcpkg.cmake" ..`
# 3. Build the project: `cmake --build . --config Release`

cmake_minimum_required(VERSION 3.10)
project(LeetCodeExercises)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Boost (via vcpkg or installed manually)
find_package(Boost REQUIRED COMPONENTS unit_test_framework)

# Include directories for Boost
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
else()
    message(FATAL_ERROR "Boost not found. Please ensure it is installed and available.")
endif()

# Variable to specify the active problem
# Update ACTIVE_PROBLEM to match the folder of the current problem
set(ACTIVE_PROBLEM "1071.GreatestCommonDivisorofStrings")  # Example problem

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
if(Boost_FOUND)
    target_link_libraries(test_program ${Boost_LIBRARIES})
endif()

# Set custom output directory for executables
set(CUSTOM_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
set_target_properties(main_program PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_OUTPUT_DIR})
set_target_properties(test_program PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CUSTOM_OUTPUT_DIR})

# Print configuration details
message(STATUS "Active Problem: ${ACTIVE_PROBLEM}")
message(STATUS "Custom Output Directory: ${CUSTOM_OUTPUT_DIR}")
