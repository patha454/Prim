/**
 * @file src/format/elf64/segment/header.c
 *
 * `header.c defines function used to access ELF64 segment header fields.
 *
 * @author H Paterson.
 * @copyright BSL1.0.
 * @date June 2020.
 */

#include "format/elf64/segment/header.h"
#include "format/elf64/types.h"

/**
 * Read the segment offset from an ELF64 segment header.
 *
 * @param header The segment header.
 * @return The offset of the segment data in the ELF file.
 */
extern Elf64_Offset elf64_get_segment_offset(
    const Elf64_Segment_Header* const header)
{
    Elf64_Offset offset = 0;
    offset = header->p_offset;
    return offset;
}

/**
 * Read the segment virtual address from an ELF64 segment header.
 *
 * @param header The segment header.
 * @return The virtual address of the segment when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_vaddr(
    const Elf64_Segment_Header* const header)
{
    Elf64_Address vaddr = 0;
    vaddr = header->p_vaddr;
    return vaddr;
}

/**
 * Read the segment physical address from an ELF64 segment header.
 *
 * @param header The segment header.
 * @return The physical address of the segment when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_paddr(
    const Elf64_Segment_Header* const header)
{
    Elf64_Address paddr = 0;
    paddr = header->p_paddr;
    return paddr;
}

/**
 * Read the the size of an ELF64 segment in the binary file.
 *
 * @param header The segment header.
 * @return The size of the segment when reading from the file.
 */
extern Elf64_Address elf64_get_segment_fsize(
    const Elf64_Segment_Header* const header)
{
    Elf64_Xword file_size = 0;
    file_size = header->p_filesz;
    return file_size;
}

/**
 * Read the the size of an ELF64 segment in the memory.
 *
 * @param header The segment header.
 * @return The size of the segment when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_msize(
    const Elf64_Segment_Header* const header)
{
    Elf64_Xword mem_size = 0;
    mem_size = header->p_memsz;
    return mem_size;
}

/**
 * Read the the alignment requirements for an ELF64 segment.
 *
 * @param header The segment header.
 * @return The alignment required when loaded into memory.
 */
extern Elf64_Address elf64_get_segment_align(
    const Elf64_Segment_Header* const header)
{
    Elf64_Xword align = 0;
    align = header->p_align;
    return align;
}
