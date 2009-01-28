#ifndef Tartarus_SysDB_h
#define Tartarus_SysDB_h

#include <Ice/Ice.h>
#include "SysDB/SysDB.h"

namespace SysDB = Tartarus::iface::SysDB;
namespace core = Tartarus::iface::core;

namespace Tartarus
{
	const SysDB::UserReaderPrx& getUserReader();
	const SysDB::GroupReaderPrx& getGroupReader();

	void setReaderReInit();
}

#endif
