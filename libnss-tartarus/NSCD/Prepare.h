#ifndef Tartarus_NSCD_Prepare_h
#define Tartarus_NSCD_Prepare_h

//#include "RPC/Config.h"

#include <sys/types.h>
#include <sys/stat.h>

namespace Tartarus
{

class Umask
{
    mode_t oldmask;

public:
    Umask(mode_t newmask = 0000)
    {
        oldmask = umask(newmask);
    }
    ~Umask()
    {
        umask(oldmask);
    }
};

//void CheckDirectories();

}

#endif
