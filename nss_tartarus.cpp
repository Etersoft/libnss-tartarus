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

const SysDB::UserManagerPrx& getUserReader()
{
	static SysDB::UserManagerPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = getIceCommunicator()->propertyToProxy("Tartarus.NSCD.UserReaderPrx");
		if (!base)
			throw "Could not create proxy";
		prx = SysDB::UserManagerPrx::checkedCast(base);
		if (!prx)
			throw "Invalid proxy";
	}
	
	return prx;
}

const SysDB::GroupManagerPrx& getGroupReader()
{
	static SysDB::GroupManagerPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = getIceCommunicator()->propertyToProxy("Tartarus.NSCD.GroupReaderPrx");
		if (!base)
			throw "Could not create proxy";
		prx = SysDB::GroupManagerPrx::checkedCast(base);
		if (!prx)
			throw "Invalid proxy";
	}
	
	return prx;
}
