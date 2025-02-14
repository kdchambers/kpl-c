#include "kpl/common.h"

#include <assert.h>

#ifdef __linux__
#include <sys/mman.h>
#include <unistd.h>
#else
#error "Not implemented for non-Linux"
#endif

void *kpl_alloc_pages(i32 bytes)
{
    const i32 page_size = (i32) sysconf(_SC_PAGE_SIZE);
    assert(bytes % page_size == 0);
    const i32 page_count = bytes / page_size;
    void *ptr = mmap(nullptr, page_size * page_count, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    return ptr;
}

void kpl_free_pages(void* addr, i32 size)
{
    i32 ret = munmap(addr, size);
    assert(ret == 0);
}

