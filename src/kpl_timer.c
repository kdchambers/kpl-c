#include "kpl/timer.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

i64 kpl_nano_timestamp(clockid_t clock_id)
{
    struct timespec start_time;
    clock_gettime(clock_id, &start_time);
    return start_time.tv_nsec + (start_time.tv_sec * ns_per_sec);
}

KplTimer kpl_cpu_timer_start(void)
{
    return kpl_nano_timestamp(CLOCK_MONOTONIC);
}

i64 kpl_cpu_timer_ns_since(KplTimer timer)
{
    const i64 current_ts_ns = kpl_nano_timestamp(CLOCK_MONOTONIC);
    return current_ts_ns - timer;
}
