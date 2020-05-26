/**
 * @file include/format/elf64/header/machine.h
 *
 * Provides access to the machine field in the ELF64 header.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_HEADER_MACHINE_H
#define FORMAT_ELF64_HEADER_MACHINE_H

#include "format/elf64/types.h"
#include "status.h"

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
 * Parse the machine code from the header.
 *
 * @note elf64_get_machine does not check if the machine
 * is valid. See `elf64_is_machine_valid`.
 *
 * @param header Pointer to the ELF64 header.
 * @return The ELF64 machine target.
 */
extern ELF64_Machine elf64_parse_machine(Elf64_Half machine);

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
 * @return `STATUS_OKAY` if the machine is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_machine_valid(ELF64_Machine machine);

#endif
