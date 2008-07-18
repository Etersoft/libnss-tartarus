#ifndef LIBNSS_TARTARUS_H_
#define LIBNSS_TARTARUS_H_

#include "ClientI.h"

char *allocate_mem (char **buf, size_t *buflen, size_t len);

inline char *fill_record (char **buffer, size_t *buflen, const std::string &value)
{
	char *result = allocate_mem (buffer, buflen, value.size() + 1);
	if (result)
		std::strcpy(result, value.c_str());
	return result;
}

Tartarus::UserReaderPrx getUserReader();
Tartarus::GroupReaderPrx getGroupReader();

#endif /*LIBNSS_TARTARUS_H_*/