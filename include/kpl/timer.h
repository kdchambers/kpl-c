// clang-format Language: C
#pragma once

#include "kpl/common.h"

#include <time.h>

i64 kpl_nano_timestamp(clockid_t clock_id);

i64 kpl_cpu_timer_start(void);
i64 kpl_cpu_timer_ns_since(i64 timer);
