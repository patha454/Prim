#include "platform/file.h"
#include "format/elf64/header.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    prim_file_handle handle;
    PrimStatus status;
    Elf64_Header header;
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
    printf("Object type is: %d\n", header.type);
    return 0;
}
