// clang-format Language: C
#pragma once

#include "kpl/common.h"

struct kpl_string
{
    i32 len;
    i32 padding;
    const char *cstring;
};

static_assert(sizeof(struct kpl_string) == 16);

#define MAKE_KPL_STRING(x)                   \
    (struct kpl_string)                      \
    {                                        \
        .len = (sizeof(x) - 1), .cstring = x \
    }
