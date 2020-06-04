/**
 * @file include/format/elf64/segment/flags.h
 *
 * `flags.h` provides access and parsing for ELF64 segment header flags.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date June 2020.
 */

#ifndef FORMAT_ELF64_SEGMENT_FLAGS_H
#define FORMAT_ELF64_SEGMENT_FLAGS_H

#include "format/elf64/segment/header.h"
#include "format/elf64/types.h"
#include "status.h"

/**
 * Segment flags for ELF64 binaries. We avoid an enum here because some
 * specified values are outside the range of a C99 standard enum (int).
 */
typedef Elf64_Xword Elf64_Segment_Flag;

/** Executable segment. */
#define ELF64_PF_X 0x1

/** Writable segment. */
#define ELF64_PF_W 0x2

/** Readable segment. */
#define ELF64_PF_R 0x4

/** Executable and writable segment. */
#define ELF64_PF_WX 0x3

/** Executable and readable segment. */
#define ELF64_PF_RX 0x5

/** Readable and writable segment. */
#define ELF64_PF_RW 0x6

/** Readable, writable, and executable segment. */
#define ELF64_PF_RWX 0x7

/** Mask for CPU specific flags. */
#define ELF64_PF_MASKPROC 0xf0000000

/**
 * Extract the ELF64 segment flags from a segment header.
 *
 * @note elf64_get_segment_flags does not check if the flags are valid. See
 * `elf64_is_segment_flag_valid`.
 *
 * @param header Pointer to the ELF64 segment header.
 * @return The bitfield containing the segment flags.
 */
extern Elf64_Segment_Flag elf64_get_segment_flags(
    const Elf64_Segment_Header* header);

/**
 * Get a human readable string associated with a segment flag.
 *
 * @param flag The flag to stringify.
 * @return A human readable segment flag name.
 */
extern const char* elf64_get_segment_flag_string(Elf64_Segment_Flag flag);

/**
 * Checks if an ELF64 segment flag is a valid flag.
 *
 * @param flag A flag to test.
 * @return `STATUS_OKAY` if the flag is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_segment_flag_valid(Elf64_Segment_Flag flag);

#endif
