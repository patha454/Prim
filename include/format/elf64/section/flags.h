/**
 * @file include/format/elf64/section/flag.h
 *
 * Provides access to the ELF64 section header flags field.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_SECTION_FLAGS_H
#define FORMAT_ELF64_SECTION_FLAGS_H

#include "format/elf64/section/header.h"
#include "format/elf64/types.h"

/**
 * @typedef ELF64_Section_Flags
 *
 * ELF64 section flag encoding. We avoid an enum because some
 * specified values are too large for standard C enums (int width).
 */
typedef Elf64_Xword ELF64_Section_Flag;
/** Section writable during execution. */
#define ELF64_SECTION_FLAG_WRITE 0x1

/** Section occupies memory. */
#define ELF64_SECTION_FLAG_ALLOC 0x2

/** Section executable during execution. */
#define ELF64_SECTION_FLAG_EXEC 0x4

/** Reserved for CPU specific flags. */
#define ELF64_SECTION_FLAG_MASK_PROC 0xf0000000

/**
 * Extract the ELF64 section flags from a section header.
 *
 * @note elf64_get_section_flags does not check if the flags
 * is valid. See `elf64_is_section_flag_valid`.
 *
 * @param header pointer to the ELF64 section header.
 * @return The bitfield containing the section flags.
 */
extern Elf64_Xword elf64_get_section_flags(const ELF64_Section_Header* header);

/**
 * Get a string with a human readable section flag name.
 *
 * @param type The section flag to string-fiy.
 * @return A human readable section flag name.
 */
extern const char* elf64_get_section_flag_string(ELF64_Section_Flag flag);

/**
 * Checks if an ELF64 flag is a valid flag code.
 *
 * @param flag A flag to test.
 * @return `STATUS_OKAY` if the flag is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_section_flag_valid(ELF64_Section_Flag flag);

#endif
