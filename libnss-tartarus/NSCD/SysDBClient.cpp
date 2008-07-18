#include "SysDBClient.h"
#include <stdexcept>

namespace Tartarus {

static const Ice::CommunicatorPtr& getIceCommunicator()
{
	static Ice::CommunicatorPtr ic = 0;
	

	if (!ic)
	{
		Ice::InitializationData init;
		init.properties = Ice::createProperties();
		init.properties->load("/etc/Tartarus/tnscd.conf");
		ic = Ice::initialize(init);
	}
		
	return ic;
}

const SysDB::UserReaderPrx& getUserReader(Ice::CommunicatorPtr communicator)
{
	static SysDB::UserReaderPrx prx;

	if (!communicator)
		communicator = getIceCommunicator();

	if (!prx) {
		Ice::ObjectPrx base = communicator->propertyToProxy("Tartarus.SysDB.UserManagerPrx");
		if (!base)
		{
			std::ostringstream oss;
			oss << "Could not create SysDB/Users proxy from ";
			oss << communicator->getProperties()->getPropertyWithDefault("Tartarus.SysDB.UserManagerPrx","Tartarus.SysDB.UserManagerPrx");
			throw std::runtime_error(oss.str());
		}
		prx = SysDB::UserReaderPrx::checkedCast(base);
		if (!prx)
			throw std::runtime_error("Invalid SysDB/Users proxy");
	}
	
	return prx;
}

const SysDB::GroupReaderPrx& getGroupReader(Ice::CommunicatorPtr communicator)
{
	static SysDB::GroupReaderPrx prx;

	if (!communicator)
		communicator = getIceCommunicator();

	if (!prx) {
		Ice::ObjectPrx base = communicator->propertyToProxy("Tartarus.SysDB.GroupManagerPrx");
		if (!base)
			throw std::runtime_error("Could not create SysDB/Groups proxy");
		prx = SysDB::GroupReaderPrx::checkedCast(base);
		if (!prx)
			throw std::runtime_error("Invalid SysDB/Groups proxy");
	}
	
	return prx;
}

}
