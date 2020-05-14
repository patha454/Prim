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

typedef enum PrimStatus
{
    /** Success - No error. */
    STATUS_OKAY,

    /** Unspecified error. */
    STATUS_ERROR,

    /** Invalid or out or range. */
    STATUS_INVALID,

} PrimStatus;

/**
 * Get a string with a human readable status message.
 *
 * @param status The status code to string-ify;
 * @return A human readable status string.
 */
extern const char* get_status_string(const PrimStatus status);

/**
 * Checks is a status code is a valid status code.
 * 
 * @param status A status to test.
 * @return 1 if the status code is valid, 0 otherwise.
 */
extern PrimStatus is_status_code_valid(PrimStatus status);
