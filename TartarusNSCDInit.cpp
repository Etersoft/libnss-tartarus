
#include <Ice/Exception.h>
#include <TartarusNSCDInit.h>
#include <iostream>

namespace Tartarus {

Ice::InitializationData& NSCDInitialize(bool quiet)
{
	static Ice::InitializationData init;
	init.properties = Ice::createProperties();
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
	return init;
}

}
