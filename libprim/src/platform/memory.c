/**
 * @file src/platform/memory.c
 *
 * Implements access to the host's memory allocation services.
 *
 * @note This file is currently setup for a hosted C stdlib environment.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "platform/types.h"
#include "status.h"
#include <stdlib.h>

/**
 * Allocates a contigious block of memory at least `size` bytes long.
 *
 * @param result Location to return a pointer to the block.
 * @return STATUS_OKAY if the memory is allocated, STATUS_INVALID otherwise.
 */
PrimStatus prim_malloc(void** result, prim_usize size)
{
    *result = malloc(size);
    if (*result == 0)
    {
        return STATUS_ERROR;
    }
    return STATUS_OKAY;
}

/**
 * Deallocates a block of memory allocated by `prim_malloc`.
 *
 * @param memory Pointer to the memory to free.
 */
void prim_free(void* memory) { free(memory); }
