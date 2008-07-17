#include "debug.hpp"

#ifdef DEBUG

#include <stdarg.h>
#include <iostream>


void debug(const char * msg)
{
    std::cerr << msg << std::endl;
}

const char * va(const char * format, ...)
{
    static char buf[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, 1024, format, args);
    va_end(args);
    return buf;
}

#else

void debug(const char * msg)
{
}

const char * va(const char * format, ...)
{
    return 0;
}

#endif /* DEBUG */
