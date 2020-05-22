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

#include "platform/types.h"

/** ELF64 program address. */
typedef prim_u64 Elf64_Address;

/** ELF6 small unsigned integer. */
typedef prim_u16 Elf64_Half;

/** ELF64 unsigned file offset. */
typedef prim_u64 Elf64_Offset;

/** ELF64 signed medium integer. */
typedef prim_s32 Elf64_Sword;

/** ELF64 signed large integer. */
typedef prim_s64 Elf64_Sxword;

/** ELF64 unsigned medium integer. */
typedef prim_u32 Elf64_Word;

/** ELF64 Unsigned large integer. */
typedef prim_u64 Elf64_Xword;

/** ELF64 unsigned tiny integer. */
typedef prim_u8 Elf64_Byte;

/** ELF64 section index. */
typedef prim_u16 Elf64_Section;

#endif
