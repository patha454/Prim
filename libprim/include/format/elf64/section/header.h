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

#ifndef FORMAT_ELF64_SECTION_HEADER_H
#define FORMAT_ELF64_SECTION_HEADER_H

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
