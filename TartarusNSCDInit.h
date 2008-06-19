#ifndef __Tartarus_NSCD_Initialaize_h__
#define __Tartarus_NSCD_Initialaize_h__

#include <Ice/Ice.h>

namespace Tartarus
{
	Ice::InitializationData& NSCDInitialize(bool quiet = true);
}

#endif
