#include "platform/file.h"
#include "format/elf64/header.h"
#include "format/elf64/ident.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    prim_file_handle handle = NULL;
    PrimStatus status = STATUS_ERROR;
    Elf64_Header header = { 0 };
    unsigned char* ident = NULL;
    status = prim_fopen("build/prim", &handle);
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
    printf("ELF64 class: %s\n", elf64_get_class_string(ident[ELF64_IDENT_CLASS]));
    printf("ELF64 data (endianess): %s\n", elf64_get_data_string(ident[ELF64_IDENT_CLASS]));
    printf("ELF64 version: %s\n", elf64_get_version_string(ident[ELF64_IDENT_VERSION]));
    return 0;
}
