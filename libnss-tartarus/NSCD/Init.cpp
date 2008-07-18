
#include <Ice/Exception.h>
#include <Init.h>
#include <iostream>

namespace Tartarus {

Ice::InitializationData& NSCDInitialize()
{
	static Ice::InitializationData init;
	init.properties = Ice::createProperties();
#ifdef DEBUG
	std::cerr << "NSCDInitialize properties" << std::endl;
#endif
	init.properties->load("/etc/Tartarus/tnscd.conf");
#ifdef DEBUG
	std::cerr << "NSCDInitialize properties done" << std::endl;
#endif
	return init;
}

}
