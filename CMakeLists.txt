# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(MyProject VERSION 1.0)

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
    serial.h # Adjust this path
)

# Create the executable
add_executable(MyExecutable ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(MyExecutable PRIVATE include /path/to/serial) # Adjust to your actual paths


  


# Add the serial sources to the executable
target_sources(MyExecutable PRIVATE ${SERIAL_SOURCES})

