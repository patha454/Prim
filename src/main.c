#include "format/elf64/header.h"
#include "format/elf64/ident.h"
#include "platform/file.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    prim_file_handle handle = NULL;
    PrimStatus status = STATUS_ERROR;
    Elf64_Header header = { 0 };
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
    return 0;
}
