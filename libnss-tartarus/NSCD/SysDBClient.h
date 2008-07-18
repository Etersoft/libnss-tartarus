#ifndef Tartarus_SysDB_h
#define Tartarus_SysDB_h

#include <Ice/Ice.h>
#include "SysDB.h"

namespace SysDB = Tartarus::iface::SysDB;

namespace Tartarus
{
	const SysDB::UserReaderPrx& getUserReader(Ice::CommunicatorPtr communicator = 0);
	const SysDB::GroupReaderPrx& getGroupReader(Ice::CommunicatorPtr communicator = 0);
}

#endif
