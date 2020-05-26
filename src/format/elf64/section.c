/**
 * @file src/format/elf64/section.c
 *
 * `section.c` functions and data structures for reading ELF64 section headers.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "format/elf64/section.h"
#include "status.h"

/**
 * Associates an ELF64 section type with a human readable string.
 */
struct TypeString
{
    const ELF64_Section_Type type;
    const char* const name;
};

/**
 * Associates an ELF64 flag with a human readable string.
 */
struct FlagString
{
    const ELF64_Section_Flag flag;
    const char* const name;
};

/** Maps ELF64 section types to human readable names. */
static const struct TypeString type_strings[] = {
    { ELF64_SECTION_TYPE_NULL, "ELF64_SECTION_TYPE_NULL" },
    { ELF64_SECTION_TYPE_PROGBITS, "ELF64_SECTION_TYPE_PROGBITS" },
    { ELF64_SECTION_TYPE_SYMBOL_TABLE, "ELF64_SECTION_TYPE_SYMBOL_TABLE" },
    { ELF64_SECTION_TYPE_STRING_TABLE, "ELF64_SECTION_TYPE_STRING_TABLE" },
    { ELF64_SECTION_TYPE_RELOC_A, "ELF64_SECTON_TYPE_RELOC_A" },
    { ELF64_SECTION_TYPE_HASH, "ELF64_SECTON_TYPE_HASH" },
    { ELF64_SECTION_TYPE_DYNAMIC, "ELF64_SECTON_TYPE_DYNAMIC" },
    { ELF64_SECTION_TYPE_NOTE, "ELF64_SECTON_TYPE_NOTE" },
    { ELF64_SECTION_TYPE_NOBITS, "ELF64_SECTION_TYPE_NOBITS" },
    { ELF64_SECTION_TYPE_RELOC, "ELF64_SECTION_TYPE_RELOC" },
    { ELF64_SECTION_TYPE_SHLIB, "ELF64_SECTION_TYPE_SHLIB" },
    { ELF64_SECTION_TYPE_DYNSYM, "ELF64_SECTION_TYPE_DYNSYM" },
    { ELF64_SECTION_TYPE_LOPROC, "ELF64_SECTION_TYPE_LOPROC" },
    { ELF64_SECTION_TYPE_HIPROC, "ELF64_SECTION_TYPE_HIPROC" },
    { ELF64_SECTION_TYPE_LOUSER, "ELF64_SECTION_TYPE_LOUSER" },
    { ELF64_SECTION_TYPE_HIUSER, "ELF64_SECTION_TYPE_HIUSER" },
};

/** Maps ELF64 section flags to human readable names. */
static const struct FlagString flag_strings[] = {
    { ELF64_SECTION_FLAG_WRITE, "ELF64_SECTION_FLAG_WRITE" },
    { ELF64_SECTION_FLAG_ALLOC, "ELF64_SECTION_FLAG_ALLOC" },
    { ELF64_SECTION_FLAG_EXEC, "ELF64_SECTION_FLAG_EXEC" },
    { ELF64_SECTION_FLAG_MASK_PROC, "ELF64_SECTION_FLAG_MASK_PROC" },
};

/**
 * Extract the ELF64 section name index.
 *
 * @note `elf64_get_section_name` returns in index into the section header
 * name string table, not the string name.
 *
 * @param A pointer to the ELF64 section header.
 * @return The ELF64 object type.
 */
extern Elf64_Word elf64_get_section_name(
    const ELF64_Section_Header* const header)
{
    Elf64_Word name = 0;
    name = header->name;
    return name;
}

/**
 * Extract the ELF64 section type from a section header.
 *
 * @note elf64_get_section_type does not check if the value
 * is valid. See `elf64_is_section_type_valid`.
 *
 * @param A pointer to the ELF64 section header.
 * @return The ELF64 object type.
 */
extern ELF64_Section_Type elf64_get_section_type(
    const ELF64_Section_Header* const header)
{
    ELF64_Section_Type type = ELF64_SECTION_TYPE_NULL;
    type = (ELF64_Section_Type) header->type;
    return type;
}

/**
 * Get a string with a human readable section type name.
 *
 * @param type The section type to string-fiy.
 * @return A human readable section type.
 */
extern const char* elf64_get_section_type_string(const ELF64_Section_Type type)
{
    static const char* const unrecognised_type
        = "<ELF64_SECTION_TYPE_CODE_INVALID>";
    unsigned int i = 0;
    for (i = 0; i < sizeof(type_strings) / sizeof(struct TypeString); i++)
    {
        if (type_strings[i].type == type)
        {
            return type_strings[i].name;
        }
    }
    return unrecognised_type;
}

/**
 * Checks if an ELF64 section type is a valid type code.
 *
 * @param type A section type to test.
 * @return `STATUS_OKAY` if the class is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_section_type_valid(ELF64_Section_Type type)
{
    unsigned int i = 0;
    for (i = 0; i < sizeof(type_strings) / sizeof(struct TypeString); i++)
    {
        if (type_strings[i].type == type)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}

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
        if (flag_strings[i].flag == flag)
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
        if (flag_strings[i].flag == flag)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}

/**
 * Get the load address of an ELF64 section.
 *
 * @param header The ELF64 section header to read.
 * @return The address to load the section into.
 */
extern Elf64_Address elf64_get_section_address(
    const ELF64_Section_Header* header)
{
    Elf64_Address address = 0;
    address = header->address;
    return address;
}

/**
 * Get the offset to section data in an ELF64 binary.
 *
 * @param header The ELF64 section header to read.
 * @return The offset for the data the heder refers to.
 */
extern Elf64_Offset elf64_get_section_offset(const ELF64_Section_Header* header)
{
    Elf64_Offset offset = 0;
    offset = header->offset;
    return offset;
}

/**
 * Get the length of an ELF64 section's data.
 *
 * @param header The ELF64 section header to read.
 * @return The length of the section's data, in bytes.
 */
extern Elf64_Xword elf64_get_section_size(const ELF64_Section_Header* header)
{
    Elf64_Xword length = 0;
    length = header->offset;
    return length;
}

/**
 * Get an ELF64 section's link table index.
 *
 * @param header the ELF64 section header to read.
 * @return The section's link table index.
 */
extern Elf64_Word elf64_get_section_link_table_index(
    const ELF64_Section_Header* header)
{
    Elf64_Word link_index = 0;
    link_index = header->link;
    return link_index;
}

/**
 * Get an ELF64 section's extra information.
 *
 * @param header The ELF64 section header to read.
 * @return The section's extra information. Semantics are CPU dependent.
 */
extern Elf64_Word elf64_get_section_extra_info(
    const ELF64_Section_Header* header)
{
    Elf64_Word info = 0;
    info = header->info;
    return info;
}

/**
 * Get an ELF64 section's alignment restriction.
 *
 * @param header The ELF64 section header to read.
 * @return The section's mandatory data alignment.
 */
extern Elf64_Xword elf64_get_section_alignment(
    const ELF64_Section_Header* header)
{
    Elf64_Xword align = 0;
    align = header->address_align;
    return align;
}

/**
 * Get an ELF64 section's fixed entry size, if any exists.
 *
 * @param header The ELF64 section header to read.
 * @return The section's fixed entry size.
 */
extern Elf64_Xword elf64_get_section_entry_size(
    const ELF64_Section_Header* header)
{
    Elf64_Xword entry_size = 0;
    entry_size = header->entry_size;
    return entry_size;
}
