/**
 * @file include/format/elf64/section/type.h
 *
 * Provides access to the ELF64 section header type field.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef FORMAT_ELF64_SECTION_TYPE_H
#define FORMAT_ELF64_SECTION_TYPE_H

#include "format/elf64/section/header.h"

/**
 * Section type encoding for ELF64 binaries. We avoid an enum because some
 * specified values are too large for standard C enums (max width: int).
 */
typedef Elf64_Word ELF64_Section_Type;

/** Inactive section, to be ignored. */
#define ELF64_SECTION_TYPE_NULL 0

/** Information defined by the program. Semantics are program specific. */
#define ELF64_SECTION_TYPE_PROGBITS 0x1

/** Symbol table intended for static linking. */
#define ELF64_SECTION_TYPE_SYMBOL_TABLE 0x2

/** String table. */
#define ELF64_SECTION_TYPE_STRING_TABLE 0x3

/** Relocatable section with explicit addends. */
#define ELF64_SECTION_TYPE_RELOC_A 0x4

/** Symbol hash table. */
#define ELF64_SECTION_TYPE_HASH 0x5

/** Dynamic linking information. */
#define ELF64_SECTION_TYPE_DYNAMIC 0x6

/** Notes on the object file. */
#define ELF64_SECTION_TYPE_NOTE 0x7

/** Occupies no space in the binary. */
#define ELF64_SECTION_TYPE_NOBITS 0x8

/** Relocatable section without explicit addends. */
#define ELF64_SECTION_TYPE_RELOC 0x9

/** Reserved. Undefined semantics. */
#define ELF64_SECTION_TYPE_SHLIB 0xa

/** Dynamic linker symbol table. */
#define ELF64_SECTION_TYPE_DYNSYM 0xb

/** Initialisation function table. */
#define ELF64_SECTION_TYPE_INIT_ARRAY 0xe

/** Pre-initialisation initialisation function table. */
#define ELF64_SECTION_TYPE_PREINIT_ARRAY 0x10

/** Termination function table. */
#define ELF64_SECTION_TYPE_FINI_ARRAY 0xf

/** GNU style symbol version provisions. */
#define ELF64_SECTION_TYPE_GNU_VER_DEF 0x6ffffffd

/** GNU style symbol version requirements. */
#define ELF64_SECTION_TYPE_GNU_VER_REQ 0x6ffffffe

/** GNU style symbol version table. */
#define ELF64_SECTION_TYPE_GNU_VER_SYM 0x6fffffff

/** Low end of the CPU specific semantics range. */
#define ELF64_SECTION_TYPE_LOPROC 0x70000000

/** High end of the CPU specific semantics range. */
#define ELF64_SECTION_TYPE_HIPROC 0x7fffffff

/** Low end of the application specific semantics range. */
#define ELF64_SECTION_TYPE_LOUSER 0x80000000

/** High end of the application specific semantics range. */
#define ELF64_SECTION_TYPE_HIUSER 0x90000000

/**
 * Extract the ELF64 section type from a section header.
 *
 * @note elf64_get_section_type does not check if the value
 * is valid. See `elf64_is_section_type_valid`.
 *
 * @param A pointer to the ELF64 section header.
 * @return The ELF64 object type.
 */
extern ELF64_Section_Type elf64_get_section_type(
    const ELF64_Section_Header* header);

/**
 * Get a string with a human readable section type name.
 *
 * @param type The section type to string-fiy.
 * @return A human readable section type.
 */
extern const char* elf64_get_section_type_string(ELF64_Section_Type type);

/**
 * Checks if an ELF64 section type is a valid type code.
 *
 * @param type A section type to test.
 * @return `STATUS_OKAY` if the class is valid,
 * `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_section_type_valid(ELF64_Section_Type type);

#endif
