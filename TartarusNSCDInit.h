#ifndef Tartarus_NSCD_Initialaize_h
#define Tartarus_NSCD_Initialaize_h

#include <Ice/Ice.h>

namespace Tartarus
{
	Ice::InitializationData& NSCDInitialize(bool quiet = true);
}

#endif
