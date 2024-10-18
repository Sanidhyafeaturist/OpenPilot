cmake_minimum_required(VERSION 3.10)

project(OpenPilot VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    serial.cc  # Adjust to your actual path
)

set(HEADERS
    OpenPilot.h        # Your project headers
    serial.h           # Adjust this path
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Specify the static library you want to link against
# Replace 'your_static_lib' with the actual name of your library
# and ensure the path to the library is correct.
set(STATIC_LIB_PATH "serial.lib")
set(STATIC_LIB_NAME "serial.lib")

# Add the library
add_library(${STATIC_LIB_NAME} STATIC IMPORTED)
set_target_properties(${STATIC_LIB_NAME} PROPERTIES IMPORTED_LOCATION ${STATIC_LIB_PATH})

add_executable(OpenPilot ${SOURCES})

# Link the static library to your executable
target_link_libraries(OpenPilot ${STATIC_LIB_NAME})

# CPack configuration
set(CPACK_PROJECT_NAME "OpenPilot")
set(CPACK_PROJECT_VERSION "1.0")
set(CPACK_GENERATOR "ZIP")  # Choose your desired package format

include(CPack)
