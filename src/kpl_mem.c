#include "kpl/mem.h"

void kpl_memset_u64(u64* data, u64 value, u32 count)
{
    const u64* end = data + count;
    while (data != end)
    {
        (*data) = value;
        data++;
    }
}

void kpl_memset_u32(u32* data, u32 value, u32 count)
{
    const u32* end = data + count;
    while (data != end)
    {
        (*data) = value;
        data++;
    }
}

void kpl_mem_copy_char(char* dst, const char* src, i32 count)
{
    //
    // TODO: Make faster with u64 or SIMD
    //
    for (i32 i = 0; i < count; i++)
    {
        (*dst) = (*src);
        dst++;
        src++;
    }
}

