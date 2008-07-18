#ifndef TARTARUS_DEBUG
#define TARTARUS_DEBUG

#ifdef DEBUG

#include <stdarg.h>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <sys/unistd.h>
#include <linux/unistd.h>
#include <unistd.h>

inline void debug(const char * msg)
{
    std::ofstream out("/tmp/debug_output", std::ios::app);
    const pid_t tid = syscall(__NR_gettid);
    const pid_t pid = getpid();
    out << pid << ':' << tid << ':' << msg << std::endl;
}

inline const char * va(const char * format, ...)
{
    static char buf[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, 1024, format, args);
    va_end(args);
    return buf;
}

#else

inline void debug(const char * msg)
{
}

inline const char * va(const char * format, ...)
{
    return 0;
}

#endif /* DEBUG */

#endif /* TARTARUS_DEBUG */
