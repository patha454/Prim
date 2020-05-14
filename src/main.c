#include "format/elf64/types.h"
#include "status.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    PrimStatus status = is_status_code_valid(9);
    Elf64_Sword include_test = 1;
    printf("%s\n", get_status_string(status));
    printf("Edit main.c to start the project.\n");
    return include_test;
}
