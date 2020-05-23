/**
 * @file file.h
 *
 * `file.h` provides abstraction of the platform's file
 * handling system for maximum portability.
 *
 * Prim needs to manipulate files and to load in binaries.
 * Diffrent platforms (Linux kernel, Unix userspace...)
 * provided diffrent file handling libraries.
 *
 * Prim uses its own file handling API internally, so the
 * system can be ported to a new platform by modifying only
 * the abstractions in this file and the `file` C source.
 *
 * This version of `file.h` is configured for a hosted C
 * standard library platform.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef PLATFORM_FILE_H
#define PLATFORM_FILE_H

#include "status.h"
#include <stdio.h>

/** File handle.
 *
 * @note This typedef must be changed to suit
 * the host platform.
 *
 * @see `src/platform/file.c`.
 */
typedef FILE* prim_file_handle;

/**
 * Open the file specified by `path`.
 *
 * @param path Path to a file to open.
 * @param file_handle Location to return a handle to the
 * file.
 * @return STATUS_OKAY on success, otherwise an error code.
 */
extern PrimStatus prim_fopen(const char* path, prim_file_handle* file_handle);

/**
 * Read data from a file into memory.
 *
 * @param destination Destination to read to.
 * @param size Size of a data record.
 * @param count Number of records (of size `size`) to read.
 * @param file_handle File to read into memory.
 * @return STATUS_OKAY on success, otherwise an error code.
 */
extern PrimStatus prim_fread(void* destination, size_t size, size_t count,
                             prim_file_handle file_handle);

/**
 * Move the file position indicator to a diffrent position
 * in the file.
 *
 * @param file_handle The file handle to seek.
 * @param offset Move to this offset from the start of the
 * file.
 * @return STATUS_OKAY on success, otherwise an error code.
 */
extern PrimStatus prim_fseek(prim_file_handle file_handle, size_t offset);

#endif
