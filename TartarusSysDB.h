#ifndef Tartarus_SysDB_h
#define Tartarus_SysDB_h

#include <Ice/Ice.h>
#include <SysDB.h>

namespace SysDB = Tartarus::iface::SysDB;

namespace Tartarus
{
	const SysDB::UserReaderPrx& getUserReader(const Ice::CommunicatorPtr& communicator);
	const SysDB::GroupReaderPrx& getGroupReader(const Ice::CommunicatorPtr& communicator);

	inline const SysDB::UserReaderPrx& getUserReader(const Ice::Current& c)
	{
		return getUserReader(c.adapter->getCommunicator());
	}

	inline const SysDB::GroupReaderPrx& getGroupReader(const Ice::Current& c)
	{
		return getGroupReader(c.adapter->getCommunicator());
	}
}

#endif
