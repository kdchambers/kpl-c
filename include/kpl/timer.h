#pragma once

#include "kpl/common.h"

#include <time.h>

i64 kpl_nano_timestamp(clockid_t clock_id);

typedef i64 KplTimer;

KplTimer kpl_cpu_timer_start(void);
i64 kpl_cpu_timer_ns_since(KplTimer timer);
