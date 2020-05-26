/**
 * @file include/format/elf64/section.h
 *
 * `section.h` defines the section (linking) header format used by ELF64, and
 * provides definitions for accessing and reading the section headers.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_SECTION_H
#define FORMAT_ELF64_SECTION_H

#include "format/elf64/types.h"
#include "status.h"

typedef struct
{
    /**
     * Index into the section header string table, which provides the
     * section's name.
     */
    Elf64_Word name;

    /** Type and contents of the section: bytes, notes, symbol table... */
    Elf64_Word type;

    /** Access mode flag (Read, Write, Execute.) */
    Elf64_Xword flags;

    /** Memory address for the start of this section, or 0. */
    Elf64_Address address;

    /** Offset of the section data in the binary. */
    Elf64_Offset offset;

    /** Length of the section, in bytes. */
    Elf64_Xword size;

    /**
     * Section header table index link. Semantics are section type specific.
     */
    Elf64_Word link;

    /**
     * Extra section information. Semantics are section type specific.
     */
    Elf64_Word info;

    /**
     * Address alignment requirements for the section. 0 or 1 if no
     * alignment restrictions.
     */
    Elf64_Xword address_align;

    /** Size of fixed size entries in this section, if any. */
    Elf64_Xword entry_size;
} ELF64_Section_Header;

/**
 * Section type encoding for ELF64 binaries. We avoid an enum because some
 * specified values are too large for standard C enums (max width: int).
 */
typedef Elf64_Word ELF64_Section_Type;

/** Inactive section, to be ignored. */
#define ELF64_SECTION_TYPE_NULL 0

/** Information defined by the program. Semantics are program specific. */
#define ELF64_SECTION_TYPE_PROGBITS 1

/** Symbol table intended for static linking. */
#define ELF64_SECTION_TYPE_SYMBOL_TABLE 2

/** String table. */
#define ELF64_SECTION_TYPE_STRING_TABLE 3

/** Relocatable section with explicit addends. */
#define ELF64_SECTION_TYPE_RELOC_A 4

/** Symbol hash table. */
#define ELF64_SECTION_TYPE_HASH 5

/** Dynamic linking information. */
#define ELF64_SECTION_TYPE_DYNAMIC 6

/** Notes on the object file. */
#define ELF64_SECTION_TYPE_NOTE 7

/** Occupies no space in the binary. */
#define ELF64_SECTION_TYPE_NOBITS 8

/** Relocatable section without explicit addends. */
#define ELF64_SECTION_TYPE_RELOC 9

/** Reserved. Undefined semantics. */
#define ELF64_SECTION_TYPE_SHLIB 10

/** Dynamic linker symbol table. */
#define ELF64_SECTION_TYPE_DYNSYM 11

/** Low end of the CPU specific semantics range. */
#define ELF64_SECTION_TYPE_LOPROC 0x70000000

/** High end of the CPU specific semantics range. */
#define ELF64_SECTION_TYPE_HIPROC 0x7fffffff

/** Low end of the application specific semantics range. */
#define ELF64_SECTION_TYPE_LOUSER 0x80000000

/** High end of the application specific semantics range. */
#define ELF64_SECTION_TYPE_HIUSER 0x90000000

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
 * Extract the ELF64 section name index.
 *
 * @note `elf64_get_section_name` returns in index into the section header
 * name string table, not the string name.
 *
 * @param A pointer to the ELF64 section header.
 * @return The ELF64 object type.
 */
extern Elf64_Word elf64_get_section_name(const ELF64_Section_Header* header);

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
    const ELF64_Section_Header* header);

/**
 * Get a string with a human readable section type name.
 *
 * @param type The section type to string-fiy.
 * @return A human readable section type.
 */
extern const char* elf64_get_section_type_string(ELF64_Section_Type type);

/**
 * Checks if an ELF64 section type is a valid type code.
 *
 * @param type A section type to test.
 * @return `STATUS_OKAY` if the class is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_section_type_valid(ELF64_Section_Type type);

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

/**
 * Get the load address of an ELF64 section.
 *
 * @param header The ELF64 section header to read.
 * @return The address to load the section into.
 */
extern Elf64_Address elf64_get_section_address(
    const ELF64_Section_Header* header);

/**
 * Get the offset to section data in an ELF64 binary.
 *
 * @param header The ELF64 section header to read.
 * @return The offset for the data the heder refers to.
 */
extern Elf64_Offset elf64_get_section_offset(
    const ELF64_Section_Header* header);

/**
 * Get the length of an ELF64 section's data.
 *
 * @param header The ELF64 section header to read.
 * @return The length of the section's data, in bytes.
 */
extern Elf64_Xword elf64_get_section_size(const ELF64_Section_Header* header);

/**
 * Get an ELF64 section's link table index.
 *
 * @param header the ELF64 section header to read.
 * @return The section's link table index.
 */
extern Elf64_Word elf64_get_section_link_table_index(
    const ELF64_Section_Header* header);

/**
 * Get an ELF64 section's extra information.
 *
 * @param header The ELF64 section header to read.
 * @return The section's extra information. Semantics are CPU dependent.
 */
extern Elf64_Word elf64_get_section_extra_info(
    const ELF64_Section_Header* header);

/**
 * Get an ELF64 section's alignment restriction.
 *
 * @param header The ELF64 section header to read.
 * @return The section's mandatory data alignment.
 */
extern Elf64_Xword elf64_get_section_alignment(
    const ELF64_Section_Header* header);

/**
 * Get an ELF64 section's fixed entry size, if any exists.
 *
 * @param header The ELF64 section header to read.
 * @return The section's fixed entry size.
 */
extern Elf64_Xword elf64_get_section_entry_size(
    const ELF64_Section_Header* header);

#endif
