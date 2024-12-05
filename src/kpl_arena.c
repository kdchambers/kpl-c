#include "kpl/arena.h"

void kpl_arena_init_from_buffer(KplArena* arena, u8* buffer, u32 capacity)
{
    arena->ptr = buffer;
    arena->capacity = capacity;
    arena->used = 0;
}

void kpl_arena_reset(KplArena* arena)
{
    arena->used = 0;
}

bool kpl_arena_is_initialized(KplArena* arena)
{
    return !(arena->capacity == 0 || arena->ptr == nullptr);
}

void kpl_arena_deinit(KplArena* arena)
{
    arena->ptr = nullptr;
    arena->capacity = 0;
    arena->used = 0;
}
