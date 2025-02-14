#include "kpl/common.h"
#include "kpl/string.h"
#include "kpl/mem.h"

typedef struct 
{
    char* ptr;
    i32 used;
    i32 capacity;
} KplStringBuilder;

#define KPL_STRING_BUILDER_ERROR_OUT_OF_SPACE 1

i32 kpl_string_builder_append_string(KplStringBuilder* builder, KplString string)
{
    const i32 free_space = builder->capacity - builder->used;

    if (free_space <= string.len)
    {
        return KPL_STRING_BUILDER_ERROR_OUT_OF_SPACE;
    }

    kpl_mem_copy_char(builder->ptr + builder->used, string.cstring, string.len);
    builder->used += string.len;
    *(builder->ptr + builder->used) = '\0';

    return KPL_OK;        
}

#define KPL_U32_AS_STRING_MAX_LEN 9

//
// TODO: Implement properly
// 
i32 kpl_u32_to_string(u32 number, char* buffer, i32 buffer_size)
{
    const i32 digit_char_base = '0';
    const i32 digit_count = 8;

    for (i32 i = 0; i < digit_count; i++)
    {
        const i32 digit = number % 10;
        const char digit_char = (char)(digit + digit_char_base);
        buffer[i] = digit_char;

        if (number == 0)
        {
            return i;
        }

        number = number / 10;
    }

    return digit_count;
}

void kpl_string_builder_append_u32(KplStringBuilder* builder, u32 number)
{
    char* dst_ptr = builder->ptr + builder->used;
    const i32 dst_size = builder->capacity - builder->used;
    const i32 str_len = kpl_u32_to_string(number, dst_ptr, dst_size);
    builder->used += str_len;
}

