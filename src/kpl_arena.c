#include "kpl/arena.h"

#include "kpl/mem.h"
#include "kpl/assert.h"

void kpl_arena_init_from_buffer(struct kpl_arena *arena, u8 *buffer, u32 capacity)
{
    arena->ptr = buffer;
    arena->capacity = capacity;
    arena->used = 0;
}

void kpl_arena_reset(struct kpl_arena *arena)
{
    arena->used = 0;
}

bool kpl_arena_is_initialized(struct kpl_arena *arena)
{
    return !(arena->capacity == 0 || arena->ptr == nullptr);
}

void kpl_arena_deinit(struct kpl_arena *arena)
{
    arena->ptr = nullptr;
    arena->capacity = 0;
    arena->used = 0;
}

void *kpl_arena_alloc(struct kpl_arena *arena, i64 size, i64 align)
{
    const i64 aligned_index = kpl_round_up_i64(arena->used, align);
    const i64 after_space = arena->capacity - aligned_index;

    if (size > after_space)
    {
        return nullptr;
    }

    void *ptr = arena->ptr + aligned_index;

    kpl_assert(((uintptr_t)ptr) % align == 0);
    arena->used = aligned_index;
    kpl_assert(arena->used <= arena->capacity);

    return ptr;
}
