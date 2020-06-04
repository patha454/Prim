/**
 * @file src/format/elf64/segment/type.c
 *
 * `type.c` provides functions for validating ELF64 segment (program) header
 * types.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date June 2020.
 */

#include "format/elf64/segment/type.h"
#include "format/elf64/segment/header.h"
#include "status.h"

/** Associates an ELF64 section type with a human readable string. */
struct Type_String
{
    const Elf64_Segment_Type type;
    const char* const name;
};

/** Maps ELF64 segment types to human readable names. */
static const struct Type_String type_strings[] = {
    { ELF64_PT_NULL, "ELF64_PT_NULL" },
    { ELF64_PT_LOAD, "ELF64_PT_LOAD" },
    { ELF64_PT_DYNAMIC, "ELF64_PT_DYNAMIC" },
    { ELF64_PT_INTERP, "ELF64_PT_INTERP" },
    { ELF64_PT_NOTE, "ELF64_PT_NOTE" },
    { ELF64_PT_SHLIB, "ELF64_PT_SHLIB" },
    { ELF64_PT_PHDR, "ELF64_PT_PHDR" },
    { ELF64_PT_LOPROC, "ELF64_PT_LOPROC" },
    { ELF64_PT_HIPROC, "ELF64_PT_HIPROC" },
};

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
    const Elf64_Segment_Header* const header)
{
    Elf64_Segment_Type type = ELF64_PT_NULL;
    type = (Elf64_Segment_Type) header->p_type;
    return type;
}

/**
 * Get a string with a human readable segment type name.
 *
 * @param type The segment type to string-ify.
 * @return A human readable segment type name.
 */
extern const char* efl64_get_segment_type_string(const Elf64_Segment_Type type)
{
    static const char* const unrecognised_type = "<ELF64_SEGMENT_TYPE_INVALID>";
    static const char* const proc_range = "ELF64_PT_PROC";
    unsigned int i = 0;
    if (type >= ELF64_PT_LOPROC && type <= ELF64_PT_HIPROC)
    {
        return proc_range;
    }
    for (i = 0; i < sizeof(type_strings) / sizeof(struct Type_String); i++)
    {
        if (type_strings[i].type == type)
        {
            return type_strings[i].name;
        }
    }
    return unrecognised_type;
}

/**
 * Checks if an ELF64 segment type is a valid segment type value.
 *
 * @param type A segment type to test.
 * @return 'STATUS_OKAY` if the type is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus efl64_is_segment_type_valid(Elf64_Segment_Type type)
{
    unsigned int i = 0;
    if (type >= ELF64_PT_LOPROC && type <= ELF64_PT_HIPROC)
    {
        return STATUS_OKAY;
    }
    for (i = 0; i < sizeof(type_strings) / sizeof(struct Type_String); i++)
    {
        if (type_strings[i].type == type)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}
