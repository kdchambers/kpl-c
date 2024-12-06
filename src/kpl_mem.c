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
