#pragma once

#include "kpl/common.h"

typedef struct
{
    u8* ptr;
    u32 capacity;
    u32 used;
} KplArena;

void kpl_arena_init_from_buffer(KplArena* arena, u8* buffer, u32 capacity);
void kpl_arena_reset(KplArena* arena);
bool kpl_arena_is_initialized(KplArena* arena);
void kpl_arena_deinit(KplArena* arena);
