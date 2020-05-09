/**
 * @file types.h
 *
 * Types used by the ELF64 binary format.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_TYPES_H
#define FORMAT_ELF64_TYPES_H


#include <stdint.h>


/** ELF64 program address. */
typedef uint64_t Elf64_Address;

/** ELF6 small unsigned integer. */
typedef uint16_t Elf64_Half;

/** ELF64 unsigned file offset. */
typedef uint64_t Elf64_Offset;

/** ELF64 signed medium integer. */
typedef int32_t Elf64_Sword;

/** ELF64 signed large integer. */
typedef int64_t Elf64_Sxword;

/** ELF64 unsigned medium integer. */
typedef int32_t Elf64_Word;

/** ELF64 Unsigned large integer. */
typedef int64_t Elf64_Xword;

/** ELF64 unsigned tiny integer. */
typedef uint8_t Elf64_Byte;

/** ELF64 section index. */
typedef uint16_t Elf64_Section;

#endif
