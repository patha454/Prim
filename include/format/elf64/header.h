/**
 * @file header.h
 * 
 * The file header used by the EFL64 binary format.
 * 
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_HEADER_H
#define FORMAT_ELF64_HEADER_H


#include "format/elf64/types.h"


/** ELF64 Identification code length. */
#define ELF64_IDENT_LEN 16

typedef struct 
{
    /** Magic number and machine-independent identification code. */
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
    Elf64_Offset section_header;

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


#endif
