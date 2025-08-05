// clang-format Language: C
#pragma once

#include "kpl/common.h"

struct kpl_arena
{
    u8 *ptr;
    u32 capacity;
    u32 used;
};

void kpl_arena_init_from_buffer(struct kpl_arena *arena, u8 *buffer, u32 capacity);
void kpl_arena_reset(struct kpl_arena *arena);
bool kpl_arena_is_initialized(struct kpl_arena *arena);
void kpl_arena_deinit(struct kpl_arena *arena);
void *kpl_arena_alloc(struct kpl_arena *arena, i64 size, i64 align);
