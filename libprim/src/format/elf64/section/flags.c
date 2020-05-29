/**
 * @file src/format/elf64/section/flags.c
 *
 * Defines functions relating to the ELF64 section header flags field.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "format/elf64/section/flags.h"

/**
 * Associates an ELF64 flag with a human readable string.
 */
struct FlagString
{
    const ELF64_Section_Flag flag;
    const char* const name;
};

/** Maps ELF64 section flags to human readable names. */
static const struct FlagString flag_strings[] = {
    { ELF64_SECTION_FLAG_WRITE, "ELF64_SECTION_FLAG_WRITE" },
    { ELF64_SECTION_FLAG_ALLOC, "ELF64_SECTION_FLAG_ALLOC" },
    { ELF64_SECTION_FLAG_EXEC, "ELF64_SECTION_FLAG_EXEC" },
    { ELF64_SECTION_FLAG_MASK_PROC, "ELF64_SECTION_FLAG_MASK_PROC" },
};

/**
 * Extract the ELF64 section flags from a section header.
 *
 * @note elf64_get_section_flags does not check if the flags
 * is valid. See `elf64_is_section_flag_valid`.
 *
 * @param header pointer to the ELF64 section header.
 * @return The bitfield containing the section flags.
 */
extern Elf64_Xword elf64_get_section_flags(
    const ELF64_Section_Header* const header)
{
    Elf64_Xword flags = 0;
    flags = header->flags;
    return flags;
}

/**
 * Get a string with a human readable section flag name.
 *
 * @param type The section flag to string-fiy.
 * @return A human readable section flag name.
 */
extern const char* elf64_get_section_flag_string(const ELF64_Section_Flag flag)
{
    static const char* const unrecognised_type
        = "<ELF64_SECTION_FLAG_CODE_INVALID>";
    unsigned int i = 0;
    for (i = 0; i < sizeof(flag_strings) / sizeof(struct FlagString); i++)
    {
        if (flag_strings[i].flag && flag)
        {
            return flag_strings[i].name;
        }
    }
    return unrecognised_type;
}

/**
 * Checks if an ELF64 flag is a valid flag code.
 *
 * @param flag A flag to test.
 * @return `STATUS_OKAY` if the flag is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_section_flag_valid(ELF64_Section_Flag flag)
{
    unsigned int i = 0;
    for (i = 0; i < sizeof(flag_strings) / sizeof(struct FlagString); i++)
    {
        if (flag_strings[i].flag && flag)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}
