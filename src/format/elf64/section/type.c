/**
 * @file src/format/elf64/section/type.c
 *
 * Defines functions related to the ELF64 section header type field.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "format/elf64/section/type.h"
#include "format/elf64/section/header.h"

/**
 * Associates an ELF64 section type with a human readable string.
 */
struct TypeString
{
    const ELF64_Section_Type type;
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