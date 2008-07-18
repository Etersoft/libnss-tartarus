
#include <Ice/Exception.h>
#include <Init.h>
#include <iostream>

namespace Tartarus {

Ice::InitializationData& NSCDInitialize(bool quiet)
{
	static Ice::InitializationData init;
	init.properties = Ice::createProperties();
#ifdef DEBUG
	std::cerr << "NSCDInitialize properties" << std::endl;
#endif
	try
	{
		init.properties->load("/etc/Tartarus/tnscd.conf");
	}
	catch (Ice::FileException &error)
	{
		if (!quiet)
			throw error;
		std::cerr << error << std::endl;
	}
#ifdef DEBUG
	std::cerr << "NSCDInitialize properties done" << std::endl;
#endif
	return init;
}

}
