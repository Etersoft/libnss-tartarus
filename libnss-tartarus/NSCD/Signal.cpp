#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "Signal.h"

namespace Tartarus {

//
// Block sigs.
//

void BlockSignals(bool block,int signum)
{
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,signum);
    sigprocmask(block?SIG_BLOCK:SIG_UNBLOCK,&set,0);
}

//
// Catch a signal. This should implement the following semantics:
//
// 1) The handler remains installed after being called.
// 2) The signal should be blocked during handler execution.
//

void (*CatchSignal(int signum,void (*handler)(int )))(int)
{
    struct sigaction act;
    struct sigaction oldact;

    memset(&act, 0, sizeof(act));

    act.sa_handler = handler;
    //
    // We *want* SIGALRM to interrupt a system call.
    //
    if(signum != SIGALRM)
        act.sa_flags = SA_RESTART;
    sigemptyset(&act.sa_mask);
    sigaddset(&act.sa_mask,signum);
    sigaction(signum,&act,&oldact);
    return oldact.sa_handler;
}

}
