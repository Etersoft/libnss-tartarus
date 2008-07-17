#include <TartarusDebug.h>

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

Tartarus::UserReaderPrx getUserReader()
{
    Tartarus::RPC::Connection con(12346);
    return Tartarus::UserReaderPrx ("UserReader", con);
}

Tartarus::GroupReaderPrx getGroupReader()
{
    Tartarus::RPC::Connection con(12346);
    return Tartarus::UserReaderPrx ("GroupReader", con);
}
