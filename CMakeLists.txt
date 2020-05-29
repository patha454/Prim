# Specify Cmake required to build the project.
cmake_minimum_required(VERSION 3.10)

# Set the project name.
project(Prim)

# Set the include paths.
include_directories(libprim/include)

# Declare the prim library target.
add_library(prim STATIC
        libprim/src/status.c
        libprim/src/format/elf64/header/machine.c
        libprim/src/format/elf64/header/type.c
        libprim/src/format/elf64/header/header.c
        libprim/src/format/elf64/header/ident.c
        libprim/src/format/elf64/section/header.c
        libprim/src/format/elf64/section/type.c
        libprim/src/format/elf64/section/flags.c
        libprim/src/format/elf64/section/string_table.c
        libprim/src/platform/memory.c
        libprim/src/platform/file.c
)

# Declare the prim driver executable target.
add_executable(prim_app
        prim_app/src/main.c
)

# Link the Prim driver to the library.
target_link_libraries(prim_app prim)

# Just name the Prim driver 'prim'. The library should be something like 'libprim' by default.
set_target_properties(prim_app PROPERTIES OUTPUT_NAME "prim")
