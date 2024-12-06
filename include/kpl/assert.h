#pragma once

//
// Set `KPL_ASSERT_BEHAVIOUR` to one of these values to set the bahaviour
//
#define KPL_ASSERT_BEHAVIOUR_PANIC  0
#define KPL_ASSERT_BEHAVIOUR_LOG    1
#define KPL_ASSERT_BEHAVIOUR_IGNORE 2

#define KPL_ASSERT_BEHAVIOUR        KPL_ASSERT_BEHAVIOUR_PANIC

#if KPL_ASSERT_BEHAVIOUR == KPL_ASSERT_BEHAVIOUR_PANIC

void kpl_assert_impl(const char* condition_string, const char* message, const char* file_string,
                     int line_number);

#define kpl_assert(condition, message)                            \
    if ((condition) == false)                                               \
    {                                                             \
        kpl_assert_impl(#condition, message, __FILE__, __LINE__); \
    }

#elif KPL_ASSERT_BEHAVIOUR == KPL_ASSERT_BEHAVIOUR_LOG

void kpl_assert_impl(const char* condition_string, const char* message, const char* file_string,
                     int line_number);

#define kpl_assert(condition, message)                           \
    if (!condition)                                              \
    {                                                            \
        kpl_assert_impl(#condition, message, __LINE__, __FILE__); \
    }

#elif KPL_ASSERT_BEHAVIOUR == KPL_ASSERT_BEHAVIOUR_IGNORE
#define kpl_assert(condition, message)
#else
#error "KPL_ASSERT_BEHAVIOUR not set to a valid value. See kpl/assert.h"
#endif
