/**
 * @file src/format/elf64/ident.c
 *
 * Ident field information for ELF64 binaries.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "format/elf64/header/ident.h"
#include "format/elf64/header/header.h"
#include "status.h"

/** Associates an ELF64 class with a human readable name. */
struct ClassString
{
    const ELF64_Class class;
    const char* const name;
};

/** Associates an ELF64 data code with a human readable
 * name. */
struct DataString
{
    const ELF64_Data_Encoding data;
    const char* const name;
};

/** Associates an ELF64 version code with a human readable
 * name. */
struct VersionString
{
    const ELF64_Version version;
    const char* const name;
};

/** Maps class codes to human readable names. */
static const struct ClassString class_strings[] = {
    { ELF64_CLASS_NONE, "ELF64_CLASS_NONE" },
    { ELF64_CLASS_32BIT, "ELF64_CLASS_32BIT" },
    { ELF64_CLASS_64BIT, "ELF64_CLASS_64BIT" },
};

/** Maps data codes with human readable names. */
static const struct DataString data_strings[] = {
    { ELF64_DATA_NONE, "ELF64_DATA_NONE" },
    { ELF64_DATA_LSB, "ELF64_DATA_LSB" },
    { ELF64_DATA_MSB, "ELF64_DATA_MSB" },
};

/** Maps version codes with human readable names. */
static const struct VersionString version_strings[] = {
    { ELF64_VERSION_NONE, "ELF64_VERSION_NONE" },
    { ELF64_VERSION_CURRENT, "ELF64_VERSION_CURRENT" },
};

extern PrimStatus elf64_is_magic_okay(
    unsigned const char ident[ELF64_IDENT_LEN])
{
    int magic0_okay = 0;
    int magic1_okay = 0;
    int magic2_okay = 0;
    int magic3_okay = 0;
    magic0_okay = ident[ELF64_IDENT_MAGIC0] == ELF64_MAGIC0;
    magic1_okay = ident[ELF64_IDENT_MAGIC1] == ELF64_MAGIC1;
    magic2_okay = ident[ELF64_IDENT_MAGIC2] == ELF64_MAGIC2;
    magic3_okay = ident[ELF64_IDENT_MAGIC3] == ELF64_MAGIC3;
    if (magic0_okay && magic1_okay && magic2_okay && magic3_okay)
    {
        return STATUS_OKAY;
    }
    return STATUS_INVALID;
}

/**
 * Extract the ELF64 class field from the header ident.
 *
 * @note elf64_get_class does not check the class value is
 * valid. See `elf64_is_class_code_valid`.
 *
 * @param ident The ELF64 ident header field.
 * @return The ELF64 ident header value.
 */
extern ELF64_Class elf64_get_class(unsigned const char ident[ELF64_IDENT_LEN])
{
    ELF64_Class class = ELF64_CLASS_NONE;
    class = (ELF64_Class) ident[ELF64_IDENT_CLASS];
    return class;
}

/**
 * Get a string with a human readable class message.
 *
 * @param class The class to string-ify;
 * @return A human readable status string.
 */
extern const char* elf64_get_class_string(const ELF64_Class class)
{
    static const char* const unrecognised_class = "<ELF64_CLASS_CODE_INVALID>";
    unsigned int i = 0;
    for (i = 0; i < sizeof(class_strings) / sizeof(struct ClassString); i++)
    {
        if (class_strings[i].class == class)
        {
            return class_strings[i].name;
        }
    }
    return unrecognised_class;
}

/**
 * Checks if an ELF64 class is a valid class code.
 *
 * @param class A status to test.
 * @return `STATUS_OKAY` if the class is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_class_code_valid(ELF64_Class class)
{
    unsigned int i = 0;
    for (i = 0; i < sizeof(class_strings) / sizeof(struct ClassString); i++)
    {
        if (class_strings[i].class == class)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}

/**
 * Extract the ELF64 data (endianess) code from the header
 * ident.
 *
 * @note elf64_get_data_encoding does not check the code is
 * valid.
 * @see `elf64_is_data_code_valid`.
 *
 * @param ident The ELF64 ident header field.
 * @return The ELF64 data code contained in the header.
 */
extern ELF64_Data_Encoding elf64_get_data_encoding(
    unsigned const char ident[ELF64_IDENT_LEN])
{
    ELF64_Data_Encoding data = ELF64_DATA_NONE;
    data = (ELF64_Data_Encoding) ident[ELF64_IDENT_DATA];
    return data;
}

/**
 * Get a string with a human readable data encoding message.
 *
 * @param data The class to string-ify;
 * @return A human readable status string.
 */
extern const char* elf64_get_data_string(const ELF64_Data_Encoding data)
{
    static const char* const unrecognised_data = "<ELF64_DATA_CODE_INVALID>";
    unsigned int i = 0;
    for (i = 0; i < sizeof(data_strings) / sizeof(struct DataString); i++)
    {
        if (data_strings[i].data == data)
        {
            return data_strings[i].name;
        }
    }
    return unrecognised_data;
}

/**
 * Checks if an ELF64 data encoding is a valid data code.
 *
 * @param data A data code to test.
 * @return `STATUS_OKAY` if the data code is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_data_code_valid(ELF64_Data_Encoding data)
{
    unsigned int i = 0;
    for (i = 0; i < sizeof(data_strings) / sizeof(struct DataString); i++)
    {
        if (data_strings[i].data == data)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}

/**
 * Extract the version field from an ELF64 header ident.
 *
 * @note elf64_get_version does not check if the version
 * code is valid. See `elf64_is_version_code_valid`.
 *
 * @param ident The ELF64 header ident field.
 * @return The ELF64 data encoding.
 */
extern ELF64_Version elf64_get_version(
    unsigned const char ident[ELF64_IDENT_LEN])
{
    ELF64_Version version = ELF64_VERSION_NONE;
    version = (ELF64_Version) ident[ELF64_IDENT_VERSION];
    return version;
}

/**
 * Get a string with a human readable version encoding
 * message.
 *
 * @param version The version to string-ify;
 * @return A human readable version string.
 */
extern const char* elf64_get_version_string(const ELF64_Version version)
{
    static const char* const unrecognised_version
        = "<ELF64_VERSION_CODE_INVALID>";
    unsigned int i = 0;
    for (i = 0; i < sizeof(version_strings) / sizeof(struct VersionString); i++)
    {
        if (version_strings[i].version == version)
        {
            return version_strings[i].name;
        }
    }
    return unrecognised_version;
}

/**
 * Checks if an ELF64 version encoding is a valid version
 * code.
 *
 * @param version A version code to test.
 * @return `STATUS_OKAY` if the version code is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_version_code_valid(ELF64_Version version)
{
    unsigned int i = 0;
    for (i = 0; i < sizeof(version_strings) / sizeof(struct VersionString); i++)
    {
        if (version_strings[i].version == version)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}
