#include <stdlib.h>
#include <assert.h>
#include "util.h"
#include <signal.h>
#include <stdio.h>
#include <stdarg.h>

noreturn void fatal(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    //if assertions are enabled, this will cause a failure. debuggers will stop at this point.
    assert(0);
    
    //if assertions are disabled, this will cause debuggers to stop at this point, which is more helpful than an exit.
    raise(SIGSEGV);
    
    //exit app
    exit(1);
}

void fatal_if(int cond, const char *fmt, ...) {
    if (!cond)
        return;
    
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    //if assertions are enabled, this will cause a failure. debuggers will stop at this point.
    assert(0);
    
    //if assertions are disabled, this will cause debuggers to stop at this point, which is more helpful than an exit.
    raise(SIGSEGV);
    
    //exit app
    exit(1);
}

//less fatal version
void print_if(int cond, const char *fmt, ...) {
    if (!cond)
        return;

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

void fatal_if_or_ferror(int cond, FILE* stream, const char *fmt, ...) {
    if (!cond || ferror(stream))
        return;

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    //if assertions are enabled, this will cause a failure. debuggers will stop at this point.
    assert(0);

    //if assertions are disabled, this will cause debuggers to stop at this point, which is more helpful than an exit.
    raise(SIGSEGV);

    //exit app
    exit(1);
}

void fatal_if_ferror(FILE* stream, const char *fmt, ...) {
    if (ferror(stream))
        return;

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    //if assertions are enabled, this will cause a failure. debuggers will stop at this point.
    assert(0);

    //if assertions are disabled, this will cause debuggers to stop at this point, which is more helpful than an exit.
    raise(SIGSEGV);

    //exit app
    exit(1);
}

int fatal_int(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    
    //if assertions are enabled, this will cause a failure. debuggers will stop at this point.
    assert(0);
    
    //if assertions are disabled, this will cause debuggers to stop at this point, which is more helpful than an exit.
    raise(SIGSEGV);
    
    //exit app
    exit(1);
    
    return -1;
}
