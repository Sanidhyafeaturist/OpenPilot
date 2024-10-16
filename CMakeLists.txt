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
    # Add other source files as needed
)

# Specify the header files
set(HEADERS
    OpenPilot.h        # Your project headers
    /OpenPilot/sensors/seriallib/include/serial/serial.h # Adjust this path
)

# Create the executable
add_executable(MyExecutable ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(MyExecutable PRIVATE include /path/to/serial) # Adjust to your actual paths

# Include the serial source file
set(SERIAL_SOURCES
    /Openpilot/sensors/seriallib/src/serial.cc # Adjust to your actual path
)

# Add the serial sources to the executable
target_sources(MyExecutable PRIVATE ${SERIAL_SOURCES})

