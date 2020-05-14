/** @file types.h
 *
 * `types.h` provides abstraction of the platform's native
 * integer types for maximum portability.
 *
 * Prim needs fixed width types to correctly parse binary
 * formats. Diffrent platforms (freestanding, UEFI,
 * Linux kernal, Unix userspace...) provide diffrent
 * definitions for a fixed width type.
 *
 * Prim uses its own type internally, so the system can be
 * ported to a new platform by modifying only the types in
 * this file.
 *
 * This version of `types.h` is configured for a Unix
 * userspace, using the C99 `stdint.h` header.
 * 
 * @author H Paterson.
 * @copyright BSL-1.0.
 * @date May 2020.
 */

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H


#include <stdint.h>


/** Unsigned 8-bit integer. */
typedef uint8_t prim_u8;

/** Unsigned 16-bit integer. */
typedef uint16_t prim_u16;

/** Unsigned 32-bit integer. */
typedef uint32_t prim_u32;

/** Unsigned 64-bit integer. */
typedef uint64_t prim_u64;

/** Signed 8-bit integer. */
typedef int8_t prim_s8;

/** Signed 16-bit integer. */
typedef int16_t prim_s16;

/** Signed 32-bit integer. */
typedef int32_t prim_s32;

/** Signed 64-bit integer. */
typedef int64_t prim_s64;

#endif
