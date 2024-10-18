cmake_minimum_required(VERSION 3.10)
project(serial)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify build mode
set(BUILD_MODE "x64" CACHE STRING "Build mode: x64 or Win32")

# Collect source files
set(SOURCES
    ../../../serial.cc
)

# Create a static library
add_library(serial STATIC ${SOURCES})

# Specify the include directories for the library
target_include_directories(serial PUBLIC
    ${PROJECT_SOURCE_DIR}/include
    # Add any additional include directories here if needed
)
