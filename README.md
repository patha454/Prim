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
