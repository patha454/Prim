/**
 * @file include/platform/memory.h
 *
 * Provides access to the host's memory allocation services.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef PLATFORM_MEMORY_H
#define PLATFORM_MEMORY_H

#include "status.h"
#include "types.h"

/**
 * Allocates a contigious block of memory at least `size` bytes long.
 *
 * @param result Location to return a pointer to the block.
 * @return STATUS_OKAY if the memory is allocated, STATUS_INVALID otherwise.
 */
PrimStatus prim_malloc(void** result, prim_usize size);

/**
 * Deallocates a block of memory allocated by `prim_malloc`.
 *
 * @param memory Pointer to the memory to free.
 */
void prim_free(void* memory);

#endif
