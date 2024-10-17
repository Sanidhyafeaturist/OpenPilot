# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(OpenPilot VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
set(SOURCES
    main.cpp
    serial.cc # Adjust to your actual path
)

# Specify the header files
set(HEADERS
    OpenPilot.h        # Your project headers
    serial.h           # Adjust this path
)

# Add the serial source files (if you have them)
set(SERIAL_SOURCES
    serial.cpp # Adjust this path to your serial library implementation
)

