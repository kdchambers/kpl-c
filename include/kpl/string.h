#pragma once

#include "kpl/common.h"

typedef struct KplString
{
    i32 len;
    i32 padding;
    const char* cstring;
} KplString;

static_assert(sizeof(KplString) == 16);

#define MAKE_KPL_STRING(x) { .len = (sizeof(x) - 1), .cstring = x }

