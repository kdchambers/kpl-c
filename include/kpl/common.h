#pragma once

#if __STDC_VERSION__ >= 199901L
#define _XOPEN_SOURCE 600
#else
#define _XOPEN_SOURCE 500
#endif /* __STDC_VERSION__ */

#define UNUSED(x) (void) (x)

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef int_fast16_t if16;
typedef int_fast32_t if32;

#define ns_per_sec 1000000000
#define ns_per_ms  1000000

#define KPL_OK     0
