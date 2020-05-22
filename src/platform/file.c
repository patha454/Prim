/**
 * @file file.c
 *
 * `file.c` provides a platform dependent implimentation of
 * file handeling.
 * 
 * Prim uses these platform dependent implimentations, with
 * a platform independent interface (`file.h`) for
 * portability between platforms with diffrent file
 * handeling. Code in a Linux kernel, for example, does not
 * have access to a C standard library style file
 * interface.
 *
 * @note This version of `file.c` is an implimentation for
 * a hosted platform with access to a C standard library.
 * 
 * @see `include/platform/file.h`
 *
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#include "platform/file.h"
#include "status.h"
#include <stdio.h>

/**
 * Open the file specified by `path`.
 *
 * @param path Path to a file to open.
 * @param file_handle Location to return a handle to the file.
 * @return STATUS_OKAY on success, otherwise an error code.
 */
extern PrimStatus prim_fopen(
    const char* path,
    prim_file_handle* file_handle)
{
    FILE* native_file = fopen(path, "r");
    if (native_file == NULL)
    {
        return STATUS_BAD_FILE;
    }
    *file_handle = (prim_file_handle)native_file;
    return STATUS_OKAY;
}

/**
 * Read data from a file into memory.
 *
 * @param destination Destination to read to.
 * @param size Size of a data record.
 * @param count Number of records (of size `size`) to read.
 * @param file_handle File to read into memory.
 * @return STATUS_OKAY on success, otherwise an error code.
 */
extern PrimStatus prim_fread(
    void* destination,
    size_t size,
    size_t count,
    prim_file_handle file_handle)
{
    size_t read_count = 0;
    read_count = fread(
        destination,
        size,
        count,
        (FILE*)file_handle);
    if (read_count == 0 && count != 0)
    {
        return STATUS_FILE_IO_ERROR;
    }
    return STATUS_OKAY;
}

/**
 * Move the file position indicator to a diffrent position
 * in the file.
 *
 * @param file_handle The file handle to seek.
 * @param offset Move to this offset from the start of the file.
 * @return STATUS_OKAY on success, otherwise an error code.
 */
extern PrimStatus prim_fseek(
    prim_file_handle file_handle,
    const size_t offset)
{
    int seek_status = 1;
    seek_status = fseek(
        (FILE*)file_handle,
        offset,
        SEEK_SET);
    if (seek_status != 0)
    {
        return STATUS_FILE_IO_ERROR;
    }
    return STATUS_OKAY;
}
