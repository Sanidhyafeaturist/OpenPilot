cmake_minimum_required(VERSION 3.10)

project(OpenPilot VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    serial.cc
)

set(HEADERS
    OpenPilot.h    # Your project headers
    serial.h
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Specify the static library you want to link against
set(STATIC_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}serial.lib")  # Adjust the path to where serial.lib is located
set(STATIC_LIB_NAME "serial")

# Add the imported library
add_library(${STATIC_LIB_NAME} STATIC IMPORTED)
set_target_properties(${STATIC_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${STATIC_LIB_PATH})

# Add the main executable
add_executable(OpenPilot ${SOURCES})

# Link the static library to your executable
target_link_libraries(OpenPilot ${STATIC_LIB_NAME})

# CPack configuration
set(CPACK_PROJECT_NAME "OpenPilot")
set(CPACK_PROJECT_VERSION "1.0")
set(CPACK_GENERATOR "ZIP")  # Choose your desired package format

include(CPack)
