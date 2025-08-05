// clang-format Language: C
#pragma once

#include "kpl/common.h"

void kpl_memset_u64(u64 *data, u64 value, u32 count);
void kpl_memset_u32(u32 *data, u32 value, u32 count);
void kpl_mem_copy_char(char *dst, const char *src, i32 count);
void *kpl_align_ptr(void *ptr, u64 align);
i64 kpl_round_up_i64(i64 value, u64 align);
