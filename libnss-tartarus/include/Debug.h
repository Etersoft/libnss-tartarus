#ifndef TARTARUS_DEBUG
#define TARTARUS_DEBUG

#ifdef DEBUG

#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/unistd.h>
#include <linux/unistd.h>
#include <unistd.h>

static inline void debug(const char * msg)
{
    const pid_t tid = syscall(__NR_gettid);
    const pid_t pid = getpid();
    fprintf (stderr, "%d: %d: %s\n", pid, tid, msg);
}

static inline const char * va(const char * format, ...)
{
    static char buf[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buf, 1024, format, args);
    va_end(args);
    return buf;
}

#else

static inline void debug(const char * msg)
{
}

static inline const char * va(const char * format, ...)
{
    return 0;
}

#endif /* DEBUG */

#endif /* TARTARUS_DEBUG */
