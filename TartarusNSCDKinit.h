#ifndef Tartarus_NSCD_Kinit_h
#define Tartarus_NSCD_Kinit_h

#include <stdexcept>

namespace Tartarus
{
	void NSCDKinit(const char *princname = "host", const char* ktname = 0, const char* ccname = "MEMORY:0");
}

#endif
