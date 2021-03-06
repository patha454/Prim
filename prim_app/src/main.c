#include "format/elf64/header/header.h"
#include "format/elf64/header/ident.h"
#include "format/elf64/header/machine.h"
#include "format/elf64/header/type.h"
#include "format/elf64/section/flags.h"
#include "format/elf64/section/header.h"
#include "format/elf64/section/string_table.h"
#include "format/elf64/section/type.h"
#include "format/elf64/segment/flags.h"
#include "format/elf64/segment/header.h"
#include "format/elf64/segment/type.h"
#include "platform/file.h"
#include "platform/memory.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Prints an ELF64 sections data to the standard out.
 *
 * @param header The ELF64 section header to print.
 */
void elf64_print_section_info(const ELF64_Section_Header* const header,
    const ELF64_Section_Header* section_name_table,
    const char* section_name_data)
{
    PrimStatus status = STATUS_INVALID;
    const char* section_name = NULL;
    printf("--- ELF64 Section Header ---\n");
    printf("ELF64 section name index: 0x%x\n", elf64_get_section_name(header));
    status = elf64_get_string_table_entry(&section_name, section_name_table,
        section_name_data, elf64_get_section_name(header));
    if (status != STATUS_OKAY)
    {
        printf("Failed to read section name: %s\n", get_status_string(status));
        exit(EXIT_FAILURE);
    }
    printf("ELF64 section name: %s\n", section_name);
    printf("ELF64 section type: %s\n",
        elf64_get_section_type_string(elf64_get_section_type(header)));
    if (STATUS_OKAY != elf64_is_section_type_valid(header->type))
    {
        printf("\tELF64 section type value: 0x%x\n", header->type);
    }
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

void elf64_print_segment_info(const Elf64_Segment_Header* const header)
{
    PrimStatus status = STATUS_OKAY;
    printf("--- ELF64 Segment Header ---\n");
    status = elf64_is_section_type_valid(elf64_get_segment_type(header));
    if (status != STATUS_OKAY)
    {
        printf("ELF64 segment type invalid. Value: 0x%x\n",
            elf64_get_segment_type(header));
    }
    printf("ELF64 segment type: %s\n",
        efl64_get_segment_type_string(elf64_get_segment_type(header)));
    printf("ELf64 segment flags: %s\n",
        elf64_get_segment_flag_string(elf64_get_segment_flags(header)));
    printf("ELF64 segment offset: 0x%lx\n", elf64_get_segment_offset(header));
    printf("ELF64 segment virtual address: 0x%lx\n",
        elf64_get_segment_vaddr(header));
    printf("ELF64 segment physical address: 0x%lx\n",
        elf64_get_segment_paddr(header));
    printf("ELF64 segment fsize: 0x%lx\n", elf64_get_segment_fsize(header));
    printf("ELf64 segment msize: 0x%lx\n", elf64_get_segment_msize(header));
    printf("ELF64 sement alignment: 0x%lx\n", elf64_get_segment_align(header));
}

int main(int argc, char* argv[])
{
    prim_file_handle handle = NULL;
    PrimStatus status = STATUS_ERROR;
    Elf64_Header header = { 0 };
    ELF64_Section_Header section_header = { 0 };
    ELF64_Section_Header section_name_str_table_header = { 0 };
    Elf64_Segment_Header segment_header = { 0 };
    char* str_table_data = 0;
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
    status = prim_fseek(handle,
        header.sh_offset
            + header.header_name_strs_index * sizeof(ELF64_Section_Header));
    if (status != STATUS_OKAY)
    {
        printf("Seek section header name string table failed: %s\n",
            get_status_string(status));
        exit(EXIT_FAILURE);
    }
    status = prim_fread(&section_name_str_table_header,
        sizeof(ELF64_Section_Header), 1, handle);
    if (status != STATUS_OKAY)
    {
        printf("Section string table name header read failed: %s\n",
            get_status_string(status));
    }
    status = prim_fseek(handle, section_name_str_table_header.offset);
    if (status != STATUS_OKAY)
    {
        printf("Section string table read failed: %s\n",
            get_status_string(status));
        exit(EXIT_FAILURE);
    }
    status = prim_malloc(
        (void**) &str_table_data, section_name_str_table_header.size);
    if (status != STATUS_OKAY)
    {
        printf("Malloc str table failed: %s\n", get_status_string(status));
        exit(EXIT_FAILURE);
    }
    status = prim_fread(
        str_table_data, section_name_str_table_header.size, 1, handle);
    if (status != STATUS_OKAY)
    {
        printf("Read section header string table failed: %s\n",
            get_status_string(status));
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
        elf64_get_type_string(elf64_parse_object_type(header.type)));
    printf("ELF64 machine: %s\n",
        elf64_get_machine_string(elf64_parse_machine(header.machine)));
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
        elf64_print_section_info(
            &section_header, &section_name_str_table_header, str_table_data);
    }
    for (int segment = 0; segment < elf64_get_ph_entry_count(&header);
         segment++)
    {
        status = prim_fseek(handle,
            segment * sizeof(Elf64_Segment_Header)
                + elf64_get_ph_offset(&header));
        if (status != STATUS_OKAY)
        {
            printf("ELF64 segment header seek failed: %s\n",
                get_status_string(status));
            exit(EXIT_FAILURE);
        }
        status = prim_fread(
            &segment_header, sizeof(Elf64_Segment_Header), 1, handle);
        if (status != STATUS_OKAY)
        {
            printf(
                "ELF64 segment read failed: %s\n", get_status_string(status));
            exit(EXIT_FAILURE);
        }
        elf64_print_segment_info(&segment_header);
    }
    return 0;
}
