#include <kpl/assert.h>

#if KPL_ASSERT_BEHAVIOUR == KPL_ASSERT_BEHAVIOUR_PANIC

#include <stdio.h>
#include <stdlib.h>

void kpl_assert_impl(const char* condition_string, const char* message, const char* file_string, int line_number)
{
    fprintf(stderr, "ASSERT FAILED: Condition (%s) Message: (%s), File %s:%d. Terminating process.\n", condition_string,
            message, file_string, line_number);
    exit(EXIT_FAILURE);
}

#elif KPL_ASSERT_BEHAVIOUR == KPL_ASSERT_BEHAVIOUR_LOG

#include <stdio.h>

void kpl_assert_impl(const char* condition_string, const char* message, const char* file_string, int line_number)
{
    fprintf(stderr, "ASSERT FAILED: Condition (%s) Message: (%s), File %s:%d. Terminating process.\n", condition_string,
            message, file_string, line_number);
}

#elif KPL_ASSERT_BEHAVIOUR == KPL_ASSERT_BEHAVIOUR_IGNORE
#define kpl_assert(condition, message)
#else
#error "KPL_ASSERT_BEHAVIOUR not set to a valid value. See kpl/assert.h"
#endif
