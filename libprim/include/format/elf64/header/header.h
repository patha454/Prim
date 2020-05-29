/**
 * @file header.h
 *
 * The file header used by the EFL64 binary format.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_HEADER_HEADER_H
#define FORMAT_ELF64_HEADER_HEADER_H

#include "format/elf64/header/ident.h"
#include "format/elf64/types.h"
#include "status.h"

typedef struct
{
    /** Magic number and machine-independent identification
     * code. */
    unsigned char ident[ELF64_IDENT_LEN];

    /** Type of the binary: Executable, core, object... */
    Elf64_Half type;

    /** Machine architecture targeted by the binary. */
    Elf64_Half machine;

    /** ELF version of this binary. */
    Elf64_Word version;

    /** Process entry point. */
    Elf64_Address entry;

    /** Program header table offset. */
    Elf64_Offset ph_offset;

    /** Section header table offset. */
    Elf64_Offset sh_offset;

    /** ELF binary flags. */
    Elf64_Word flags;

    /** Length of this header. */
    Elf64_Half header_size;

    /** Length of a program header entry. */
    Elf64_Half ph_entry_size;

    /** Tally of program header entires. */
    Elf64_Half ph_entry_count;

    /** Length of a section header entry. */
    Elf64_Half sh_entry_size;

    /** Tally of section header entries. */
    Elf64_Half sh_entry_count;

    /** Index to the section header name string table. */
    Elf64_Half header_name_strs_index;

} Elf64_Header;

/**
 * Get the start virtual address for the process.
 *
 * `elf64_get_entry_address` returns 0 if the file has no
 * associated entry point, for example because it is a core
 * or object file.
 *
 * @param header The ELF64 header to read.
 * @return The start virtual address for the process, or 0 if no such address.
 */
extern Elf64_Address elf64_get_entry_address(Elf64_Header* header);

/**
 * Get the offset to the program (segment) header table.
 *
 * @note The program header offset will be zero if the file has no program
 * header, for example because it is an object file.
 *
 * @param header The ELF64 header to read.
 * @return The offset to the program header, or 0 if no such header.
 */
extern Elf64_Offset elf64_get_ph_offset(Elf64_Header* header);

/**
 * Get the offset to the section (linking) header table.
 *
 * @note The section header offset will be zero if the file has no section
 * header, for example because it is an executable file.
 *
 * @param header the ELF64 header to read.
 * @return The offset to the section header, or 0 if no such header.
 */
extern Elf64_Offset elf64_get_sh_offset(Elf64_Header* header);

/**
 * Get the CPU specific flags for this binary.
 *
 * @param header The ELF64 header to read.
 * @return The offset to the section header, or 0 if no such header.
 */
extern Elf64_Word elf64_get_flags(Elf64_Header* header);

/**
 * Get the size of the header according to this binary.
 *
 * @param header The ELF64 header to read.
 * @return The length of this version of the ELF64 header.
 */
extern Elf64_Half elf64_get_header_size(Elf64_Header* header);

/**
 * Gets the size of a program header entry, according to this binary.
 *
 * @param header The ELF64 header to read.
 * @return The length of a program header entry in this binary.
 */
extern Elf64_Half elf64_get_ph_entry_size(Elf64_Header* header);

/**
 * Gets the number of program header entries (segments) in this binary.
 *
 * @note The number of segments can be zero, for example if this is a core file.
 *
 * @param header The ELF64 header to read.
 * @return The number of segments in the binary.
 */
extern Elf64_Half elf64_get_ph_entry_count(Elf64_Header* header);

/**
 * Gets the size of a program header entry, according to this binary.
 *
 * @param header The ELF64 header to read.
 * @return The length of a section header entry in this binary.
 */
extern Elf64_Half elf64_get_sh_entry_size(Elf64_Header* header);

/**
 * Gets the number of section header entries in this binary.
 *
 * @note The number of sections can be zero, for example if this is an
 * executable file.
 *
 * @param header The ELF64 header to read.
 * @return The number of sections in the binary.
 */
extern Elf64_Half elf64_get_sh_entry_count(Elf64_Header* header);

/**
 * Gets the index of the section name section index.
 *
 * The section header string table is a section contaning a table of string
 * names for each section in the binary.
 *
 * @note If the file has no section name string table, this member holds the
 * value `SHN_UNDEF`
 *
 * @todo Update the undefined value note to reflect the actual value name, once
 * section headers are implimented.
 *
 * @param header The ELF64 header to read.
 * @return The index of the string table section in the section header table.
 */
extern Elf64_Half elf64_get_shstr_index(Elf64_Header* header);

#endif
