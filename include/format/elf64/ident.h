/**
 * @file include/format/elf64/ident.h
 * 
 * Header ident field information used by ELF64 binaries.
 * 
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_IDENT_H
#define FORMAT_ELF64_IDENT_H


#include "format/elf64/header.h"
#include "status.h"


/** ELF64 magic number 0. */
#define ELF64_MAGIC0 0x7f;

/** ELF64 magic number 1. */
#define ELF64_MAGIC1 'E';

/** ELF64 magic number 2. */
#define ELF64_MAGIC2 'L';

/** ELF64 magic number 3. */
#define ELF64_MAGIC3 'F';

/** Index of ELF magic number 0. */
#define ELF64_IDENT_MAGIC0 0

/** Index of ELF magic number 1. */
#define ELF64_IDENT_MAGIC1 1

/** Index of ELF magic number 2. */
#define ELF64_IDENT_MAGIC2 2

/** Index of ELF magic number 3. */
#define ELF64_IDENT_MAGIC3 3

/** Index the the ELF class (word-size). */
#define ELF64_IDENT_CLASS 4

/** Index of the ELF data encoding (endianess). */
#define ELF64_IDENT_DATA 5

/** Index of the ELF version. */
#define ELF64_IDENT_VERSION 6

/** Start of padding. */
#define ELF64_IDENT_PADDING 7

/** Length of the ELF64 ident, including padding. */
#define ELG64_IDENT_NIDENT 16


/** Class values for ELF64 binaries. */
typedef enum ELF64_Class
{
    /** Invalid class. */
    ELF64_CLASS_NONE = 0,

    /**
     * 32-bit class.
     * 
     * @note `ELF_CLASS_32BIT` should never be used in ELF64.
     */
    ELF64_CLASS_32BIT = 1,

    /** 64-bit class. */
    ELF64_CLASS_64BIT = 2,

} ELF64_Class;

/** Data encoding (endianess) values for ELF64 binaries. */
typedef enum ELF64_Data_Encoding
{
    /** Invalid data encoding. */
    ELF64_DATA_NONE = 0,

    /** Least significant bit first. */
    ELF64_DATA_LSB = 1,

    /** Most significant bit first. */
    ELF64_DATA_MSB = 2,

} ELF64_Data_Encoding;

/** Version encoding for ELF64 binaries. */
typedef enum ELF64_Version
{
    /** Invalid version. */
    ELF64_VERSION_NONE = 0,

    /** Version 1... */
    ELF64_VERSION_CURRENT = 1,

} ELF64_Version;

/**
 * Tests if an ELF64 ident contains the correct magic
 * number.
 *
 * @param ident The ELF64 ident header field.
 * @return STATUS_OKAY if the magic number is correct,
 *         STATUS_INVALID otherwise.
 */
extern PrimStatus elf64_is_magic_okay(
    unsigned const char ident[ELF64_IDENT_LEN]
);

/**
 * Extract the ELF64 class field from the header ident.
 * 
 * @note elf64_get_class does not check the class value is
 * valid. See `elf64_is_class_code_valid`.
 * 
 * @param ident The ELF64 ident header field.
 * @return The ELF64 ident header value.
 */
extern ELF64_Class elf64_get_class(
    unsigned const char ident[ELF64_IDENT_LEN]);

/**
 * Get a string with a human readable class message.
 *
 * @param class The class to string-ify;
 * @return A human readable status string.
 */
extern const char* elf64_get_class_string(ELF64_Class class);

/**
 * Checks if an ELF64 class is a valid class code.
 * 
 * @param class A class code to test.
 * @return `STATUS_OKAY` if the class is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_class_code_valid(ELF64_Class class);

/**
 * Extract the ELF64 data (endianess) code from the header ident.
 * 
 * @note elf64_get_data_encoding does not check the code is valid.
 * @see `elf64_is_data_code_valid`.
 * 
 * @param ident The ELF64 ident header field.
 * @return The ELF64 data code contained in the header.
 */
extern ELF64_Data_Encoding elf64_get_data_encoding(
    unsigned const char ident[ELF64_IDENT_LEN]
);

/**
 * Get a string with a human readable data encoding message.
 *
 * @param data The class to string-ify;
 * @return A human readable status string.
 */
extern const char* elf64_get_data_string(ELF64_Data_Encoding data);

/**
 * Checks if an ELF64 data encoding is a valid data code.
 * 
 * @param data A data code to test.
 * @return `STATUS_OKAY` if the data code is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_data_code_valid(ELF64_Data_Encoding data);

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
    unsigned const char ident[ELF64_IDENT_LEN]
);

/**
 * Get a string with a human readable version encoding message.
 *
 * @param version The version to string-ify;
 * @return A human readable version string.
 */
extern const char* elf64_get_version_string(ELF64_Version version);

/**
 * Checks if an ELF64 version encoding is a valid version code.
 * 
 * @param version A version code to test.
 * @return `STATUS_OKAY` if the version code is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_version_code_valid(ELF64_Version version);

#endif
