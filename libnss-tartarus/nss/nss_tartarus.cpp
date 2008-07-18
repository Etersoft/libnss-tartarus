#include <debug.h>

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
    debug ("getUserReader start");
    Tartarus::RPC::Connection con(12346);
    debug ("getUserReader con");
    Tartarus::UserReaderPrx prx ("UserReader", con);
    debug ("getUserReader end");
    return prx;
}

Tartarus::GroupReaderPrx getGroupReader()
{
    Tartarus::RPC::Connection con(12346);
    return Tartarus::GroupReaderPrx ("GroupReader", con);
}
