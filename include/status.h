/**
 * @file status.h
 * 
 * Status codes used to indicate error conditions from
 * Prim operations.
 * 
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef STATUS_H
#define STATUS_H

typedef enum PrimStatus
{
    /** Success - No error. */
    STATUS_OKAY,

    /** Unspecified error. */
    STATUS_ERROR,

    /** Invalid input. */
    STATUS_INVALID,

    /** File does not exist, or cannot be opened. */
    STATUS_BAD_FILE,

    /** Internal file read/write error. */
    STATUS_FILE_IO_ERROR,

} PrimStatus;

/**
 * Get a string with a human readable status message.
 *
 * @param status The status code to string-ify;
 * @return A human readable status string.
 */
extern const char* get_status_string(PrimStatus status);

/**
 * Checks is a status code is a valid status code.
 * 
 * @param status A status to test.
 * @return 1 if the status code is valid, 0 otherwise.
 */
extern PrimStatus is_status_code_valid(PrimStatus status);

#endif
