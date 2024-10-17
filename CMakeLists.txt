cmake_minimum_required(VERSION 3.10)

project(OpenPilot VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    serial.cpp  # Adjust to your actual path
)

set(HEADERS
    OpenPilot.h        # Your project headers
    serial.h           # Adjust this path
)

set(SERIAL_SOURCES
    serial.cpp  # Adjust this path to your serial library implementation
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(OpenPilot ${SOURCES} ${SERIAL_SOURCES})

# CPack configuration
set(CPACK_PROJECT_NAME "OpenPilot")
set(CPACK_PROJECT_VERSION "1.0")
set(CPACK_GENERATOR "ZIP")  # Choose your desired package format

include(CPack)
