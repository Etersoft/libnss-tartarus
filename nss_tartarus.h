#ifndef LIBNSS_TARTARUS_H_
#define LIBNSS_TARTARUS_H_

#include <Ice/Ice.h>
#include <SysDB.h>

namespace SysDB = Tartarus::iface::SysDB;

char *allocate_mem (char **buf, size_t *buflen, size_t len);

inline char *fill_record (char **buffer, size_t *buflen, const std::string &value)
{
	char *result = allocate_mem (buffer, buflen, value.size() + 1);
	if (result)
		std::strcpy(result, value.c_str());
	return result;
}

const SysDB::UserManagerPrx& getUserManager();
const SysDB::GroupManagerPrx& getGroupManager();

#endif /*LIBNSS_TARTARUS_H_*/
