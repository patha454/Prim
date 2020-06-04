/**
 * @file src/include/elf64/segment/flags.c
 *
 * Defines functions relating to the ELF64 segment flags field.
 *
 * @author H Paterson.
 * @copyright BSl-1.0.
 * @date May 2020.
 */

#include "format/elf64/segment/flags.h"
#include "format/elf64/segment/header.h"
#include "status.h"

/** Associates an ELF64 flag with a human readable string. */
struct Flag_String
{
    const Elf64_Segment_Flag flag;
    const char* const name;
};

static const struct Flag_String flag_strings[] = {
    { ELF64_PF_X, "ELF64_PF_X" },
    { ELF64_PF_W, "ELF64_PF_W" },
    { ELF64_PF_R, "ELF64_PF_R" },
    { ELF64_PF_WX, "ELF64_PF_WX" },
    { ELF64_PF_RX, "ELF64_PF_RX" },
    { ELF64_PF_RW, "ELF64_PF_RW" },
    { ELF64_PF_RWX, "ELF64_PF_RWX" },
    { ELF64_PF_MASKPROC, "ELF64_PF_MASKPROC" },
};

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
    const Elf64_Segment_Header* const header)
{
    Elf64_Segment_Flag flags = 0;
    flags = header->p_flags;
    return flags;
}

/**
 * Get a human readable string associated with a segment flag.
 *
 * @param flag The flag to stringify.
 * @return A human readable segment flag name.
 */
extern const char* elf64_get_segment_flag_string(Elf64_Segment_Flag flag)
{
    static const char* const unrecognised_flag = "<ELF64_SEGMENT_FLAG_UNKNOWN>";
    unsigned int i = 0;
    if (flag & ELF64_PF_MASKPROC)
    {
        flag = ELF64_PF_MASKPROC;
    }
    for (i = 0; i < sizeof(flag_strings) / sizeof(struct Flag_String); i++)
    {
        if (flag_strings[i].flag == flag)
        {
            return flag_strings[i].name;
        }
    }
    return unrecognised_flag;
}

/**
 * Checks if an ELF64 segment flag is a valid flag.
 *
 * @param flag A flag to test.
 * @return `STATUS_OKAY` if the flag is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_segment_flag_valid(const Elf64_Segment_Flag flag)
{
    unsigned int i = 0;
    for (i = 0; i < sizeof(flag_strings) / sizeof(struct Flag_String); i++)
    {
        if (flag_strings[i].flag == flag)
        {
            return STATUS_OKAY;
        }
    }
    if (flag & ELF64_PF_MASKPROC)
    {
        return STATUS_OKAY;
    }
    return STATUS_INVALID;
}
