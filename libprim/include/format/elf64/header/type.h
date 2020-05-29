/**
 * @file include/format/elf64/header/type.h
 *
 * Provides access to the type field in the ELF64 header.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_HEADER_TYPE_H
#define FORMAT_ELF64_HEADER_TYPE_H

#include "format/elf64/types.h"
#include "status.h"

/** Object file type encoding for ELF64 binaries. */
typedef enum ELF64_Type
{
    /** Invalid type. */
    ELF64_TYPE_NONE = 0,

    /** Relocatable file. */
    ELF64_TYPE_RELOCATABLE = 1,

    /** Executable file. */
    ELF64_TYPE_EXECUTABLE = 2,

    /** Dynamic library (shared object) file. */
    ELF64_TYPE_DYNAMIC = 3,

    /** Core dump file. */
    ELF64_TYPE_CORE = 4,

    /** Processor specific semantics. */
    ELF64_TYPE_LOPROC = 0xff00,

    /** Processor specific semantics. */
    ELF64_TYPE_HIPROC = 0xffff,
} ELF64_Type;

/**
 * Parse an ELF64 half-word into an object type.
 *
 * @note elf64_get_object_type does not check if the value
 * is valid. See `elf64_is_object_type_valid`.
 *
 * @param A pointer to the ELF64 header.
 * @return The ELF64 object type.
 */
extern ELF64_Type elf64_parse_object_type(Elf64_Half type);

/**
 * Get a string with a human readable object type name.
 *
 * @param type The object type to string-fiy.
 * @return A human readable object type.
 */
extern const char* elf64_get_type_string(ELF64_Type type);

/**
 * Checks if an ELF64 type is a valid type code.
 *
 * @param type A status to test.
 * @return `STATUS_OKAY` if the class is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_type_valid(ELF64_Type type);

#endif
