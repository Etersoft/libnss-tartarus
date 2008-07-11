#include "nss_tartarus.h"
#include <TartarusNSCDInit.h>

char *allocate_mem (char **buf, size_t *buflen, size_t len)
{
	char *next;

	if (!buf || !buflen || (*buflen < len))
		return NULL;

	next = *buf;
	*buf += len;
	*buflen -= len;
	return next;
}

static const Ice::CommunicatorPtr& getIceCommunicator()
{
	static Ice::CommunicatorPtr ic = 0;
	
	if (!ic)
		ic = Ice::initialize(Tartarus::NSCDInitialize(false));
		
	return ic;
}

const SysDB::UserReaderPrx& getUserReader()
{
	static SysDB::UserReaderPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = getIceCommunicator()->propertyToProxy("Tartarus.NSCD.UserReaderPrx");
		if (!base)
			throw "Could not create TNSCD/Users proxy";
		prx = SysDB::UserReaderPrx::checkedCast(base);
		if (!prx)
			throw "Invalid TNSCD/Users proxy";
	}
	
	return prx;
}

const SysDB::GroupReaderPrx& getGroupReader()
{
	static SysDB::GroupReaderPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = getIceCommunicator()->propertyToProxy("Tartarus.NSCD.GroupReaderPrx");
		if (!base)
			throw "Could not create TNSCD/Groups proxy";
		prx = SysDB::GroupReaderPrx::checkedCast(base);
		if (!prx)
			throw "Invalid TNSCD/Groups proxy";
	}
	
	return prx;
}
