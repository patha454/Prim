/**
 * @file status.c
 * 
 * Status codes used to indicate error conditions from
 * Prim operations.
 * 
 * @see status.h
 * 
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "status.h"

/** Associates a status code with a human readable name. */
struct StatusString
{
    enum PrimStatus code;
    const char* const name;
};

/** Maps status strings with human readable names. */
static const struct StatusString status_strings[] =
{
    {STATUS_OKAY,           "STATUS_OKAY"},
    {STATUS_ERROR,          "STATUS_ERROR"},
    {STATUS_INVALID,        "STATUS_INVALID"},
    {STATUS_BAD_FILE,       "STATUS_BAD_FILE"},
    {STATUS_FILE_IO_ERROR,  "STATUS_FILE_IO_ERROR"},
};

/**
 * Get a string with a human readable status message.
 *
 * @param status The status code to string-ify;
 * @return A human readable status string.
 */
extern const char* get_status_string(const PrimStatus status)
{
    static const char* const unrecognised_status = "<STATUS_CODE_INVALID>";
    unsigned int i;
    for (i = 0;
         i < sizeof(status_strings) / sizeof(struct StatusString);
         i++)
    {
        if (status_strings[i].code == status)
        {
            return status_strings[i].name;
        }
    }
    return unrecognised_status;
}

/**
 * Checks is a status code is a valid status code.
 * 
 * @param status A status to test.
 * @return `STATUS_OKAY` if the code is valid, `STATUS_INVALID` otherwise.
 */
extern PrimStatus is_status_code_valid(PrimStatus status)
{
    unsigned int i;
    for (i = 0;
         i < sizeof(status_strings) / sizeof(struct StatusString);
         i++)
    {
        if (status_strings[i].code == status)
        {
            return STATUS_OKAY;
        }
    }
    return STATUS_INVALID;
}
