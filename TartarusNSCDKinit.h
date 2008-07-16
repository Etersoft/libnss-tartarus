#ifndef __Tartarus_NSCD_Kinit_h__
#define __Tartarus_NSCD_Kinit_h__

#include <stdexcept>

namespace Tartarus
{
	void NSCDKinit(const char *princname = "host", const char* ktname = 0, const char* ccname = 0);
}

#endif
