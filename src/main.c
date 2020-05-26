#include "format/elf64/header.h"
#include "format/elf64/ident.h"
#include "format/elf64/machine.h"
#include "format/elf64/section.h"
#include "format/elf64/type.h"
#include "platform/file.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Prints an ELF64 sections data to the standard out.
 *
 * @param header The ELF64 section header to print.
 */
extern void elf64_print_section_info(const ELF64_Section_Header* header)
{
    printf("--- ELF64 Section Header ---\n");
    printf("ELF64 section name index: 0x%x\n", elf64_get_section_name(header));
    printf("ELF64 section type: %s\n",
        elf64_get_section_type_string(elf64_get_section_type(header)));
    printf("ELF64 section flags: 0x%lx\n", elf64_get_section_flags(header));
    printf("ELF64 section load address: 0x%lx\n",
        elf64_get_section_address(header));
    printf("ELF64 section offset: 0x%lx\n", elf64_get_section_offset(header));
    printf("ELF64 section size: 0x%lx\n", elf64_get_section_size(header));
    printf("ELF64 section link table index: 0x%x\n",
        elf64_get_section_link_table_index(header));
    printf("ELF64 section extra info: 0x%x\n",
        elf64_get_section_extra_info(header));
    printf("ELF64 section alignment restriction: 0x%lx\n",
        elf64_get_section_alignment(header));
    printf("ELF64 section fixed entry size: 0x%lx\n",
        elf64_get_section_entry_size(header));
}

int main(int argc, char* argv[])
{
    prim_file_handle handle = NULL;
    PrimStatus status = STATUS_ERROR;
    Elf64_Header header = { 0 };
    ELF64_Section_Header section_header = { 0 };
    unsigned char* ident = NULL;
    if (argc < 2)
    {
        printf("Usage: prim <file>\n");
        exit(EXIT_FAILURE);
    }
    status = prim_fopen(argv[1], &handle);
    if (status != STATUS_OKAY)
    {
        printf("Open failed: %s\n", get_status_string(status));
        exit(EXIT_FAILURE);
    }
    status = prim_fread(&header, sizeof(Elf64_Header), 1, handle);
    if (status != STATUS_OKAY)
    {
        printf("Read failed: %s\n", get_status_string(status));
        exit(EXIT_FAILURE);
    }
    ident = header.ident;
    status = elf64_is_magic_okay(ident);
    printf("ELF64 magic: %s\n", get_status_string(status));
    printf("ELF64 class: %s\n", elf64_get_class_string(elf64_get_class(ident)));
    printf("ELF64 data (endianess): %s\n",
        elf64_get_data_string(elf64_get_data_encoding(ident)));
    printf("ELF64 version: %s\n",
        elf64_get_version_string(elf64_get_version(ident)));
    printf("ELF64 type: %s\n",
        elf64_get_type_string(elf64_get_object_type(&header)));
    printf("ELF64 machine: %s\n",
        elf64_get_machine_string(elf64_get_machine(&header)));
    printf(
        "ELF64 reported header size: 0x%x\n", elf64_get_header_size(&header));
    printf("ELF64 CPU specific flags: 0x%x\n", elf64_get_flags(&header));
    printf("ELF64 entry address: 0x%lx\n", elf64_get_entry_address(&header));
    printf(
        "ELF64 segment header offset: 0x%lx\n", elf64_get_ph_offset(&header));
    printf(
        "ELF64 segment header size: 0x%x\n", elf64_get_ph_entry_size(&header));
    printf("ELF64 segment count: 0x%x\n", elf64_get_ph_entry_count(&header));
    printf(
        "ELF64 section header offset: 0x%lx\n", elf64_get_sh_offset(&header));
    printf(
        "ELF64 section header size: 0x%x\n", elf64_get_sh_entry_size(&header));
    printf("ELF64 section header count: 0x%x\n",
        elf64_get_sh_entry_count(&header));
    printf("ELF64 section name secion header index: 0x%x\n",
        elf64_get_shstr_index(&header));
    for (int section = 0; section < elf64_get_sh_entry_count(&header);
         section++)
    {
        status = prim_fseek(handle,
            section * sizeof(ELF64_Section_Header)
                + elf64_get_sh_offset(&header));
        if (status != STATUS_OKAY)
        {
            printf("ELF64 section header seek failed: %s\n",
                get_status_string(status));
            exit(EXIT_FAILURE);
        }
        status = prim_fread(
            &section_header, sizeof(ELF64_Section_Header), 1, handle);
        if (status != STATUS_OKAY)
        {
            printf("ELF64 section header read failed: %s\n",
                get_status_string(status));
            exit(EXIT_FAILURE);
        }
        elf64_print_section_info(&section_header);
    }
    return 0;
}
