/**
 * @file src/format/elf64/header.c
 *
 * Header format information for the ELF64 binaries.
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "format/elf64/header.h"
#include "status.h"

/** Associates an ELF64 type with a human readable string. */
struct TypeString
{
    const ELF64_Type type;
    const char* const name;
};

/** Associates an ELF64 machine with a human readable string. */
struct MachineString
{
    const ELF64_Machine machine;
    const char* const name;
};

/** Maps ELF64 object types to human readable names. */
static const struct TypeString type_strings[] = {
    { ELF64_TYPE_NONE, "ELF64_TYPE_NONE" },
    { ELF64_TYPE_RELOCATABLE, "ELF64_TYPE_RELOCATABLE" },
    { ELF64_TYPE_EXECUTABLE, "ELF64_TYPE_EXECUTABLE" },
    { ELF64_TYPE_DYNAMIC, "ELF64_TYPE_DYNAMIC" },
    { ELF64_TYPE_CORE, "ELF64_TYPE_CORE" },
    { ELF64_TYPE_LOPROC, "ELF64_TYPE_LOPROC" },
    { ELF64_TYPE_HIPROC, "ELF64_TYPE_HIPROC" },
};

/** Maps ELF64 machine codes to human readable names. */
static const struct MachineString machine_strings[] = {
    { ELF64_MACHINE_NONE, "ELF64_MACHINE_NONE" },
    { ELF64_MACHINE_M32, "ELF64_MACHINE_M32" },
    { ELF64_MACHINE_SPARC, "ELF64_MACHINE_SPARC" },
    { ELF64_MACHINE_I386, "ELF64_MACHINE_I386" },
    { ELF64_MACHINE_68K, "ELF64_MACHINE_68K" },
    { ELF64_MACHINE_88K, "ELF64_MACHINE_88K" },
    { ELF64_MACHINE_860, "ELF64_MACHINE_860" },
    { ELF64_MACHINE_MIPS, "ELF64_MACHINE_MIPS" },
    { ELF64_MACHINE_MIPS_RS4_BE, "ELF64_MACHINE_MIPS_RS4_BE" },
    { ELF64_MACHINE_POWERPC32, "ELF64_MACHINE_POWERPC32" },
    { ELF64_MACHINE_POWERPC64, "ELF64_MACHINE_POWERPC64" },
    { ELF64_MACHINE_S390, "ELF64_MACHINE_S390" },
    { ELF64_MACHINE_ARM, "ELF64_MACHINE_ARM" },
    { ELF64_MACHINE_SUPERH, "ELF64_MACHINE_SUPERH" },
    { ELF64_MACHINE_IA64, "ELF64_MACHINE_IA64" },
    { ELF64_MACHINE_AMD64, "ELF64_MACHINE_AMD64" },
    { ELF64_MACHINE_AARCH64, "ELF64_MACHINE_AARCH64" },
    { ELF64_MACHINE_RISC_V, "ELF64_MACHINE_RISC_V" },
};

/**
 * Extract the ELF64 object type from the header.
 *
 * @note elf64_get_object_type does not check if the value
 * is valid. See `elf64_is_object_type_valid`.
 *
 * @param A pointer to the ELF64 header.
 * @return The ELF64 object type.
 */
extern ELF64_Type elf64_get_object_type(
    const Elf64_Header* const header)
{
    ELF64_Type type = ELF64_TYPE_NONE;
    type = (ELF64_Type)header->type;
    return type;
}

/**
 * Get a string with a human readable object type name.
 * 
 * @param type The object type to string-fiy.
 * @return A human readable object type.
 */
extern const char* elf64_get_type_string(const ELF64_Type type)
{
    static const char* const unrecognised_type = "<ELF64_TYPE_CODE_INVALID>";
    unsigned int i = 0;
    for (i = 0;
         i < sizeof(type_strings) / sizeof(struct TypeString);
         i++)
    {
        if (type_strings[i].type == type)
        {
            return type_strings[i].name;
        }
    }
    return unrecognised_type;
}

/**
 * Checks if an ELF64 type is a valid type code.
 * 
 * @param type A status to test.
 * @return `STATUS_OKAY` if the class is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_type_valid(ELF64_Type type)
{
    unsigned int i = 0;
    for (i = 0;
         i < sizeof(type_strings) / sizeof(struct TypeString);
         i++)
    {
        if (type_strings[i].type == type)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}

/**
 * Extract the ELF64 machine target from the header.
 * 
 * @note elf64_get_machine does not check if the machine
 * is valid. See `elf64_is_machine_valid`.
 *
 * @param header Pointer to the ELF64 header.
 * @return The ELF64 machine target.
 */
extern ELF64_Machine elf64_get_machine(
    const Elf64_Header* const header)
{
    ELF64_Machine machine = ELF64_MACHINE_NONE;
    machine = (ELF64_Machine)header->machine;
    return machine;
}

/**
 * Get a string with a human readable machine name.
 * 
 * @param machine The machine to string-fiy.
 * @return A human readable machine mane.
 */
extern const char* elf64_get_machine_string(const ELF64_Machine machine)
{
    static const char* const unrecognised_machine = "<ELF64_MACHINE_CODE_INVALID>";
    unsigned int i = 0;
    for (i = 0; i < sizeof(machine_strings) / sizeof(struct MachineString); i++)
    {
        if (machine_strings[i].machine == machine)
        {
            return machine_strings[i].name;
        }
    }
    return unrecognised_machine;
}

/**
 * Checks if an ELF64 machine is a valid machine code.
 * 
 * @param machine A machine to test.
 * @return `STATUS_OKAY` if the machine is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus elf64_is_machine_valid(ELF64_Machine machine)
{
    unsigned int i = 0;
    for (i = 0; i < sizeof(machine_strings) / sizeof(struct MachineString); i++)
    {
        if (machine_strings[i].machine == machine)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}
