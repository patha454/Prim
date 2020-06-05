/**
 * @file include/format/elf64/segment/header.h
 *
 * `header.h` defines the segment (program) header format used by ELF64, and
 * provides definitions for accessing and reading the segment headers.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date June 2020.
 */

#ifndef FORMAT_ELF64_SEGMENT_HEADER_H
#define FORMAT_ELF64_SEGMENT_HEADER_H

#include "format/elf64/types.h"

typedef struct
{

    /** The segment type or interpretation. */
    Elf64_Word p_type;

    /** Flags relevant to the segment. */
    Elf64_Word p_flags;

    /** The offset of the segment data in the binary file. */
    Elf64_Offset p_offset;

    /** The virtual address of the segment when loaded in memory. */
    Elf64_Address p_vaddr;

    /** The physical address of the segment loaded in memory, if relevant. */
    Elf64_Address p_paddr;

    /** The size of the segment in the file. May be zero - for example, .bss. */
    Elf64_Xword p_filesz;

    /** The size of the segment in the memory. May be zero - why? */
    Elf64_Xword p_memsz;

    /** Section alignment requirements in memory. 0 & 1 mean no requirement. */
    Elf64_Xword p_align;
} Elf64_Segment_Header;

/**
 * Read the segment offset from an ELF64 segment header.
 *
 * @param header The segment header.
 * @return The offset of the segment data in the ELF file.
 */
extern Elf64_Offset elf64_get_segment_offset(
    const Elf64_Segment_Header* header);

/**
 * Read the segment virtual address from an ELF64 segment header.
 *
 * @param header The segment header.
 * @return The virtual address of the segment when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_vaddr(
    const Elf64_Segment_Header* header);

/**
 * Read the segment physical address from an ELF64 segment header.
 *
 * @param header The segment header.
 * @return The physical address of the segment when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_paddr(
    const Elf64_Segment_Header* header);

/**
 * Read the the size of an ELF64 segment in the binary file.
 *
 * @param header The segment header.
 * @return The size of the segment when reading from the file.
 */
extern Elf64_Address elf64_get_segment_fsize(
    const Elf64_Segment_Header* header);

/**
 * Read the the size of an ELF64 segment in the memory.
 *
 * @param header The segment header.
 * @return The size of the segment when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_msize(
    const Elf64_Segment_Header* header);

/**
 * Read the the alignment requirements for an ELF64 segment.
 *
 * @param header The segment header.
 * @return The alignment required when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_align(
    const Elf64_Segment_Header* header);

#endif
