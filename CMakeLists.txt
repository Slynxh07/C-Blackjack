cmake_minimum_required(VERSION 3.10)
project(Blackjack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define source and include directories
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")

# Collect all source files
file(GLOB SRC_FILES "${SRC_DIR}/*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SRC_FILES})

# Tell the compiler where to find header files
target_include_directories(${PROJECT_NAME} PRIVATE ${INCLUDE_DIR})

# Optional: Enable warnings
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()