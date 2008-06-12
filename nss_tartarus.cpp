#include "nss_tartarus.h"

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

const Ice::CommunicatorPtr& getIceCommunicator()
{
	static Ice::CommunicatorPtr ic = 0;
	
	if (!ic)
		ic = Ice::initialize();
		
	return ic;
}

const SysDB::UserManagerPrx& getUserManager()
{
	static SysDB::UserManagerPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = getIceCommunicator()->stringToProxy("UserManager:ssl -p 12345");
		if (!base)
			throw "Could not create proxy";
		prx = SysDB::UserManagerPrx::checkedCast(base);
		if (!prx)
			throw "Invalid proxy";
	}
	
	return prx;
}

const SysDB::GroupManagerPrx& getGroupManager()
{
	static SysDB::GroupManagerPrx prx;

	if (!prx) {
		Ice::ObjectPrx base = getIceCommunicator()->stringToProxy("GroupManager:ssl -p 12345");
		if (!base)
			throw "Could not create proxy";
		prx = SysDB::GroupManagerPrx::checkedCast(base);
		if (!prx)
			throw "Invalid proxy";
	}
	
	return prx;
}
