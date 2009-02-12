#ifndef Tartarus_NSCD_Signal_h
#define Tartarus_NSCD_Signal_h

#include <signal.h>

namespace Tartarus
{
    void BlockSignals(bool block,int signum);
    void (*CatchSignal(int signum,void (*handler)(int)))(int);
}

#endif
