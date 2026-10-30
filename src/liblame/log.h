#pragma once
#include <stdio.h>
#include "config.h"
#define MAX_LOG_LEN 512
#ifdef __cplusplus
extern "C" 
#endif
void print_log(const char* file, int line, const char* current_level);

extern char log_msg[MAX_LOG_LEN];


#if USE_LOGGING_HACK || !LAME_LOGGING_ACTIVE

    #define DEBUGF  lame_debugf 
    #define ERRORF  lame_errorf
    #define MSGF    lame_msgf

    #if LAME_LOGGING_ACTIVE
        #define lame_errorf(gfc, ...) {  snprintf(log_msg, 512, __VA_ARGS__);  print_log(__FILE__,__LINE__, "Error"); }
        #define lame_msgf(gfc,  ...)   { snprintf(log_msg, 512, __VA_ARGS__);  print_log(__FILE__,__LINE__, "Info"); }
    #else
        #define lame_errorf(gfc, ...) do { } while (0)
        #define lame_msgf(gfc, ...) do { } while (0)
    #endif
    #if LAME_LOGGING_ACTIVE && USE_DEBUG
        #define lame_debugf(gfc, ...) {  snprintf(log_msg, 512, __VA_ARGS__);  print_log(__FILE__,__LINE__, "Debug"); }
    #else
        #define lame_debugf(gfc, ...) do { } while (0)
    #endif
#endif
