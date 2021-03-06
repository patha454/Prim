/**
 * @file src/format/elf64/type.c
 *
 * Implements functions relating to the ELF64 header type field.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020
 */

#include "format/elf64/header/type.h"

/**
 * Associates an ELF64 type with a human readable string.
 */
struct TypeString
{
    const ELF64_Type type;
    const char* const name;
};

/** Maps ELF64 object types to human readable names. */
static const struct TypeString type_strings[] = {
    { ELF64_TYPE_NONE, "ELF64_TYPE_NONE" },
    { ELF64_TYPE_RELOCATABLE, "ELF64_TYPE_RELOCATABLE" },
    { ELF64_TYPE_EXECUTABLE, "ELF64_TYPE_EXECUTABLE" },
    { ELF64_TYPE_DYNAMIC, "ELF64_TYPE_DYNAMIC" },
    { ELF64_TYPE_CORE, "ELF64_TYPE_CORE" },
    { ELF64_TYPE_LOPROC, "ELF64_TYPE_LOPROC" },
    { ELF64_TYPE_HIPROC, "ELF64_TYPE_HIPROC" },
};

/**
 * Parse an ELF64 half-word into an object type.
 *
 * @note elf64_get_object_type does not check if the value
 * is valid. See `elf64_is_object_type_valid`.
 *
 * @param A pointer to the ELF64 header.
 * @return The ELF64 object type.
 */
extern ELF64_Type elf64_parse_object_type(const Elf64_Half type)
{
    ELF64_Type type_ = ELF64_TYPE_NONE;
    type_ = (ELF64_Type) type;
    return type_;
}

/**
 * Get a string with a human readable object type name.
 *
 * @param type The object type to string-fiy.
 * @return A human readable object type.
 */
extern const char* elf64_get_type_string(const ELF64_Type type)
{
    static const char* const unrecognised_type = "<ELF64_TYPE_CODE_INVALID>";
    static const char* const proc_defined = "ELF64_TYPE_PROC_DEFINED";
    unsigned int i = 0;
    if (type >= ELF64_TYPE_LOPROC && type <= ELF64_TYPE_HIPROC)
    {
        return proc_defined;
    }
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
 * Checks if an ELF64 type is a valid type code.
 *
 * @param type A status to test.
 * @return `STATUS_OKAY` if the class is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_type_valid(ELF64_Type type)
{
    unsigned int i = 0;
    if (type >= ELF64_TYPE_LOPROC && type <= ELF64_TYPE_HIPROC)
    {
        return STATUS_OKAY;
    }
    for (i = 0; i < sizeof(type_strings) / sizeof(struct TypeString); i++)
    {
        if (type_strings[i].type == type)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}
