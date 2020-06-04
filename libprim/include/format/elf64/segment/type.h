/**
 * @file include/format/elf64/type.h
 *
 * `type.h` defines the ELF64 segment (program) header types, and provides
 * functions for validating them.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date June 2020.
 */

#ifndef FORMAT_ELF64_SEGMENT_TYPE_H
#define FORMAT_ELF64_SEGMENT_TYPE_H

#include "format/elf64/segment/header.h"
#include "format/elf64/types.h"

/** Segment type for ELF64 binaries. */
typedef enum Elf64_Type
{
    /** Null segment to be ignored. */
    ELF64_PT_NULL = 0,

    /** Loadable segment. */
    ELF64_PT_LOAD = 1,

    /** Dynamic segment. */
    ELF64_PT_DYNAMIC = 2,

    /** Interpreter Pathname segment. */
    ELF64_PT_INTERP = 3,

    /** Auxiliary information segment. */
    ELF64_PT_NOTE = 4,

    /** Reserved segment type. */
    ELF64_PT_SHLIB = 5,

    /** Program header segment. */
    ELF64_PT_PHDR = 6,

    /** First processor-specific segment type. */
    ELF64_PT_LOPROC = 0x70000000,

    /** Last Processor specific segment types. */
    ELF64_PT_HIPROC = 0x7fffffff,
} Elf64_Segment_Type;

/**
 * Extract the ELF64 segment type from a segment header.
 *
 * @note elf64_get_segment_type does not check if the value is valid. See
 * `elf64_is_segment_type_valid`.
 *
 * @param A pointer to the ELF64 segment header.
 * @return The ELF64 segment types.
 */
extern Elf64_Segment_Type elf64_get_segment_type(
    const Elf64_Segment_Header* header);

#endif
