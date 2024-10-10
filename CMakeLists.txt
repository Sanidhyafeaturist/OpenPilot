# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify the source files
set(SOURCES
    main.cpp
)

# Specify the header files
set(HEADERS
    includes/OpenPilot.h # Add your header files here
)

# Create the executable
add_executable(MyExecutable ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(MyExecutable PRIVATE include)

# Optionally add libraries
# target_link_libraries(MyExecutable PRIVATE some_library)  # Uncomment and modify as needed


