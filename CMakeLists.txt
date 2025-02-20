cmake_minimum_required(VERSION 3.16)
set(ProjectName "DnT4")
project(${ProjectName} LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# External libraries
add_subdirectory(external)

# Examples
add_subdirectory(examples/SDL2_hellow_world)
