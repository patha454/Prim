/**
 * @file src/format/elf64/section/string_table.c
 *
 * Implements access to data in the section string tables.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "format/elf64/section/header.h"
#include "format/elf64/types.h"
#include "status.h"

/**
 * Gets a string from the string table.
 *
 * @note ELF64 strings are indexed by character offset, not by string number.
 * For example `\0.bss\0.rodata\0` contains two strings, but index 3 refers to
 * a string `bss\0` - starting at the third character, running until the next
 * `\0`. Index 10 is valid and refers to the string `ata\0` - Starting at the
 * 10th character and running to the next `\0`.
 *
 * @param string Variable to store the resulting string in.
 * @param str_table The string table header.
 * @param data The string table data.
 * @param index The index to read from the string table.
 * @return STATUS_OKAY if the read is successful, otherwise an error code.
 */
extern PrimStatus elf64_get_string_table_entry(const char** result,
    const ELF64_Section_Header* str_table, const char* data, Elf64_Xword index)
{
    const char* string = data + index;
    const char* contents = string;
    const char* end_of_table = data + str_table->size;
    if (string >= end_of_table)
    {
        *result = 0;
        return STATUS_INVALID;
    }
    /* Check the string is null terminated. */
    while (*contents != '\0' && contents < end_of_table)
    {
        contents++;
    }
    if (contents >= end_of_table)
    {
        return STATUS_INVALID;
    }
    *result = string;
    return STATUS_OKAY;
}
