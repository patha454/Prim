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
#include "status.h"

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

/** Object file type encoding for ELF64 binaries. */
typedef enum ELF64_Type
{
    /** Invalid type. */
    ELF64_TYPE_NONE = 0,

    /** Relocatable file. */
    ELF64_TYPE_RELOCATABLE = 1,

    /** Executable file. */
    ELF64_TYPE_EXECUTABLE = 2,

    /** Dynamic library (shared object) file. */
    ELF64_TYPE_DYNAMIC = 3,

    /** Core dump file. */
    ELF64_TYPE_CORE = 4,

    /** Processor specific semantics. */
    ELF64_TYPE_LOPROC = 0xff00,

    /** Processor specific semantics. */
    ELF64_TYPE_HIPROC = 0xffff,
} ELF64_Type;

/** Machine type encoding for ELF64 binaries. */
typedef enum ELF64_Machine
{
    /** No or invalid machine. */
    ELF64_MACHINE_NONE = 0x0,

    /** AT&T WE 32100. */
    ELF64_MACHINE_M32 = 0x1,

    /** SPARC/ */
    ELF64_MACHINE_SPARC = 0x2,

    /** i386 (x86). */
    ELF64_MACHINE_I386 = 0x3,

    /** Motorola 68000. */
    ELF64_MACHINE_68K = 0x4,

    /** Motorola 88000. */
    ELF64_MACHINE_88K = 0x5,

    /** Intel 80860. */
    ELF64_MACHINE_860 = 0x7,

    /** MIPS RS3000 (big endian). */
    ELF64_MACHINE_MIPS = 0x8,

    /** MIPS RS4000 (big endian). */
    ELF64_MACHINE_MIPS_RS4_BE = 0xa,

    /** IBM PowerPC (32 bit). */
    ELF64_MACHINE_POWERPC32 = 0x14,

    /** IBM PowerPC (64 bit). */
    ELF64_MACHINE_POWERPC64 = 0x15,

    /** IBM System 390/zArchitecture. */
    ELF64_MACHINE_S390 = 0x16,

    /** ARM (32 bit). */
    ELF64_MACHINE_ARM = 0x28,

    /** Renasas/Hitachi SuperH. */
    ELF64_MACHINE_SUPERH = 0x2a,

    /** Intel IA-64. */
    ELF64_MACHINE_IA64 = 0x32,

    /** AMD64 (x86-64). */
    ELF64_MACHINE_AMD64 = 0x3e,

    /** Aarch64 (ARM 64 bit). */
    ELF64_MACHINE_AARCH64 = 0xb7,

    /** RISC-V. */
    ELF64_MACHINE_RISC_V = 0xf3,
} ELF64_Machine;

/**
 * Extract the ELF64 object type from the header.
 *
 * @note elf64_get_object_type does not check if the value
 * is valid. See `elf64_is_object_type_valid`.
 *
 * @param A pointer to the ELF64 header.
 * @return The ELF64 object type.
 */
extern ELF64_Type elf64_get_object_type(
    const Elf64_Header* header);

/**
 * Get a string with a human readable object type name.
 * 
 * @param type The object type to string-fiy.
 * @return A human readable object type.
 */
extern const char* elf64_get_type_string(ELF64_Type type);

/**
 * Checks if an ELF64 type is a valid type code.
 * 
 * @param type A status to test.
 * @return `STATUS_OKAY` if the class is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_type_valid(ELF64_Type type);

/**
 * Extract the ELF64 machine target from the header.
 * 
 * @note elf64_get_machine does not check if the machine
 * is valid. See `elf64_is_machine_valid`.
 *
 * @param header Pointer to the ELF64 header.
 * @return The ELF64 machine target.
 */
extern ELF64_Machine elf64_get_machine(
    const Elf64_Header* header);

/**
 * Get a string with a human readable machine name.
 * 
 * @param machine The machine to string-fiy.
 * @return A human readable machine mane.
 */
extern const char* elf64_get_machine_string(ELF64_Machine machine);

/**
 * Checks if an ELF64 machine is a valid machine code.
 * 
 * @param machine A machine to test.
 * @return `STATUS_OKAY` if the machine is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_machine_valid(ELF64_Machine machine);

#endif
