/**
 * @file src/format/elf64/section/header.c
 *
 * `section.c` functions and data structures for reading ELF64 section headers.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "format/elf64/section/header.h"
#include "status.h"

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
