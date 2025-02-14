#pragma once

#include "kpl/string.h"

#define KPL_GLOG_DEBUG_ENABLE 1

#define kpl_glog_error(message) kpl_glog_error_impl(message)
#define kpl_glog_warn(message) kpl_glog_warn_impl(message)
#define kpl_glog_info(message) kpl_glog_info_impl(message)

#ifdef KPL_GLOG_DEBUG_ENABLE
#define kpl_glog_debug(message) kpl_glog_debug_impl(message)
#elif
#define kpl_glog_debug(message)
#endif

void kpl_glog_error_impl(KplString message);
void kpl_glog_warn_impl(KplString message);
void kpl_glog_info_impl(KplString message);

#ifdef KPL_GLOG_DEBUG_ENABLE
void kpl_glog_debug_impl(KplString message);
#endif

static char kpl_glog_line_buffer[512];

void kpl_glog_debug_statement_begin();
void kpl_glog_debug_statement_end();

void kpl_glog_debug_add_string();
void kpl_glog_debug_add_u32();
void kpl_glog_debug_add_i32();

