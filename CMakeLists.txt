# Specify Cmake required to build the project.
cmake_minimum_required(VERSION 3.10)

# Set the project name.
project(Prim)

# Set the include paths.
include_directories(include)

add_executable(prim main.c
    src/status.c)
