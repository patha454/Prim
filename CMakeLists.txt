# Specify Cmake required to build the project.
cmake_minimum_required(VERSION 3.10)

# Set the project name.
project(Prim)

# Set the include paths.
include_directories(include)

# Declare the prim library target.
add_library(prim STATIC
    src/status.c
    src/format/elf64/header/machine.c
    src/format/elf64/header/type.c
    src/format/elf64/header/header.c
    src/format/elf64/header/ident.c
    src/format/elf64/section.c
    src/platform/file.c
)

# Declare the prim driver executable target.
add_executable(prim_app
    src/main.c
)

# Link the Prim driver to the library.
target_link_libraries(prim_app prim)

# Just name the Prim driver 'prim'. The library should be something like 'libprim' by default.
set_target_properties(prim_app PROPERTIES OUTPUT_NAME "prim")
