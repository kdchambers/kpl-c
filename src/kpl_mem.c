#include "kpl/assert.h"
#include "kpl/mem.h"
#include <stdint.h>

void kpl_memset_u64(u64 *data, u64 value, u32 count)
{
    const u64 *end = data + count;
    while (data != end)
    {
        (*data) = value;
        data++;
    }
}

void kpl_memset_u32(u32 *data, u32 value, u32 count)
{
    const u32 *end = data + count;
    while (data != end)
    {
        (*data) = value;
        data++;
    }
}

void kpl_mem_copy_char(char *dst, const char *src, i32 count)
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

void *kpl_align_ptr(void *ptr, u64 align)
{
    kpl_assert(align % 2 == 0);
    const uintptr_t addr = (uintptr_t) ptr;

    if (addr % align != 0)
    {
        return (void *) (addr + (align - (addr % align)));
    }
    return ptr;
}

i64 kpl_round_up_i64(i64 value, u64 align)
{
    if (value % align != 0)
    {
        return value + (align - (value % align));
    }
    return value;
}
