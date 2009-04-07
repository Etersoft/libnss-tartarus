#include "SysDBClient.h"
#include "Kinit.h"
#include <stdexcept>

#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>

namespace Tartarus {

typedef boost::lock_guard<boost::mutex> locker;

static bool needsReInit = false;
static boost::mutex mutex;

static const Ice::CommunicatorPtr& getIceCommunicator()
{
	static Ice::CommunicatorPtr ic = 0;

	if (!ic || needsReInit)
	{
		NSCDKinit();
		Ice::InitializationData init;
		init.properties = Ice::createProperties();
		init.properties->load("/etc/Tartarus/clients/all.config");
		init.properties->load("/etc/Tartarus/clients/tnscd.config");

		if (ic)
			ic->destroy();

		ic = Ice::initialize(init);
	}

	return ic;
}

void setReaderReInit()
{
        locker(*mutex);
        needsReInit = true;
}

const SysDB::UserReaderPrx& getUserReader()
{
        locker(*mutex);
	static SysDB::UserReaderPrx prx;

	if (!prx || needsReInit) {
		Ice::CommunicatorPtr communicator = getIceCommunicator();
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
		needsReInit = false;
	}
	
	return prx;
}

const SysDB::GroupReaderPrx& getGroupReader()
{
        locker(*mutex);
	static SysDB::GroupReaderPrx prx;

	if (!prx || needsReInit) {
		Ice::CommunicatorPtr communicator = getIceCommunicator();
		Ice::ObjectPrx base = communicator->propertyToProxy("Tartarus.SysDB.GroupManagerPrx");
		if (!base)
			throw std::runtime_error("Could not create SysDB/Groups proxy");
		prx = SysDB::GroupReaderPrx::checkedCast(base);
		if (!prx)
			throw std::runtime_error("Invalid SysDB/Groups proxy");
		needsReInit = false;
	}
	
	return prx;
}

}
