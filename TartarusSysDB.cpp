
#include <TartarusSysDB.h>

namespace Tartarus {

static const Ice::CommunicatorPtr& getIceCommunicator()
{
	static Ice::CommunicatorPtr ic = 0;
	
	if (!ic)
		ic = Ice::initialize();
		
	return ic;
}

const SysDB::UserReaderPrx& getUserReader(const Ice::CommunicatorPtr& communicator)
{
	static SysDB::UserReaderPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = communicator->propertyToProxy("Tartarus.SysDB.UserReaderPrx");
		if (!base)
			throw "Could not create SysDB/Users proxy";
		prx = SysDB::UserReaderPrx::checkedCast(base);
		if (!prx)
			throw "Invalid SysDB/Users proxy";
	}
	
	return prx;
}

const SysDB::GroupReaderPrx& getGroupReader(const Ice::CommunicatorPtr& communicator)
{
	static SysDB::GroupReaderPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = communicator->propertyToProxy("Tartarus.SysDB.GroupReaderPrx");
		if (!base)
			throw "Could not create SysDB/Groups proxy";
		prx = SysDB::GroupReaderPrx::checkedCast(base);
		if (!prx)
			throw "Invalid SysDB/Groups proxy";
	}
	
	return prx;
}

}
