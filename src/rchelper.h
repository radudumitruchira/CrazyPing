#ifndef __RCHELPER_H__
#define __RCHELPER_H__

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned char b8;

typedef unsigned short u16;
typedef signed short s16;

typedef unsigned int u32;
typedef signed int s32;
/* Use as a boolean type for int return types */
typedef unsigned int b32;

typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long long usize;
typedef signed long long ssize;

typedef float f32;
typedef double f64;

#ifndef __cplusplus
#ifndef false
#define false 0
#endif

#ifndef true
#define true 1
#endif
#endif // __cplusplus

#ifndef __cplusplus

#if _STDC_VERSION_ < 202311L
// #include <assert.h>
// #define static_assert(expression, message) _Static_assert(expression, message)
#endif // __cplusplus

#endif

static_assert((sizeof(u8)) == 1, "u8 expected to be 1 byte!");
static_assert((sizeof(s8)) == 1, "s8 expected to be 1 byte!");
static_assert((sizeof(b8)) == 1, "b8 expected to be 1 byte!");

static_assert((sizeof(u16)) == 2, "u16 expected to be 2 byte!");
static_assert((sizeof(s16)) == 2, "s16 expected to be 2 byte!");

static_assert((sizeof(u32)) == 4, "u32 expected to be 4 byte!");
static_assert((sizeof(s32)) == 4, "s32 expected to be 4 byte!");
static_assert((sizeof(b32)) == 4, "b32 expected to be 4 byte!");

static_assert((sizeof(u64)) == 8, "u64 expected to be 8 byte!");
static_assert((sizeof(s64)) == 8, "s64 expected to be 8 byte!");
static_assert((sizeof(usize)) == 8, "usize expected to be 8 byte!");
static_assert((sizeof(ssize)) == 8, "ssize expected to be 8 byte!");

static_assert((sizeof(f32)) == 4, "f32 expected to be 4 byte!");
static_assert((sizeof(f64)) == 8, "f64 expected to be 8 byte!");

/* Global variables in a file*/
#define global static
/* File internal variables*/
#define internal static
/* File internal functions */
#define function static
/* Function call persistent variables */
#define persistent static

#define c_linkage_begin extern "C" {
#define c_linkage_end }
#define c_linkage extern "C"

#define B(x) ((u64)(x)
#define KB(x) (B(x) * (1024ULL))
#define MB(x) (KB(x) * (1024ULL))
#define GB(x) (MB(x) * (1024ULL))

#define ArrayCount(a) (sizeof(a) / sizeof(a[0]))

#define Max(a, b) (((a) < (b)) ? (a) : (b))
#define Min(a, b) (((a) > (b)) ? (a) : (b))

#define AlignUpPow2(n, p) (((U64)(n) + ((U64)(p) - 1ULL)) & ~(((U64)(p)) - 1ULL))
#endif // __RCHELPER_H__
