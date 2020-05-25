![Style](https://github.com/patha454/Prim/workflows/Style/badge.svg?branch=master)
![Lint](https://github.com/patha454/Prim/workflows/Lint/badge.svg?branch=master)
![Build](https://github.com/patha454/Prim/workflows/Build/badge.svg?branch=master)

# Prim
Prim aims to be a process imager and loader. Right now it's junk.

# Building Prim

Prim is built with Cmake.

You can build Prim by running running:
```sh
Prim$ cmake -B build .
Prim$ cmake --build build
```

The build can be customized and controlled through standard Cmake configuration and options.

# Contributing

Prim expects all code contributions to pass Continuous Integration (CI) testing which enforces code style and correctness. We recommend you save time by checking your code meets our standards before pushing it. You can use the following commands to check code your code.

## Style Checking

You can check your code is formated to meets our style guide using:

```sh
$ find src include -name *.h -o -name *.c | xargs clang-format --style=file -dry-run -Werror
```
`clang-format` should produce no errors, returning status code 0.

You can automatically reformat any problematic files to meet our style guide using:
```sh
$ clang-format --style=file -i file/to/format
```

## Linting
```sh
$ find . -path "*/src/*.c" -or -path "*/include/*.h" | xargs -i clang-tidy --config="" {} -- -Iinclude
```
`clang-tidy` should produce no errors or warnings (suppressed warning from non-user code are okay), returning status code 0.

## Building
```sh
$ mkdir build
$ CFLAGS='-W -Wall -Wextra -pedantic -std=c99` cmake -B build .
$ cmake --build build [-j8]
```
Your code should compile under GCC or Clang with strict C99 errors enabled.

# Objectives

Prim initially aims to support loading statically linked ELF64 executable, from userspace, on a Linux x86-64 machine.

The aim is to enable performance comparisons between current kernel loaders, and Prim.

## Minimum Viable Product.

The minimum viable produced aims to demonstrate basic loading from userspace.

- Static loading only.
- ELF64 binaries only.
- Userspace Linux x86-64 platform.

### Roadmap

Further development may include:

- Dynamic loading and linking.
- Additional binary formats.
- Ports to other platforms, including kernel modules.
- Generating process images. (Core dumps on demand.)
- Generating binaries from raw data (Object file generation...)
