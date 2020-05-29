# Specify Cmake required to build the project.
CMAKE_MINIMUM_REQUIRED(VERSION 3.13)

# Use the new TARGET_SOURCES behaviour (converting relative paths to absolute)
CMAKE_POLICY(SET CMP0076 NEW)

# Set the project name.
PROJECT(Prim)

# Add the Prim library to the project.
ADD_SUBDIRECTORY(libprim)

# Add the Prim driver application to the project.
ADD_SUBDIRECTORY(prim_app)
