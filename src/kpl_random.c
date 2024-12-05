#include "kpl/random.h"
#include <sys/random.h>

bool kpl_rand(void* buffer, ssize_t buffer_size)
{
    const int flags = 0;
    if (getrandom(buffer, buffer_size, flags) == -1)
    {
        return false;
    }
    return true;
}