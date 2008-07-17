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
    Tartarus::debug ("getUserReader start");
    Tartarus::RPC::Connection con(12346);
    Tartarus::debug ("getUserReader con");
    Tartarus::UserReaderPrx prx ("UserReader", con);
    Tartarus::debug ("getUserReader end");
    return prx;
}

Tartarus::GroupReaderPrx getGroupReader()
{
    Tartarus::RPC::Connection con(12346);
    return Tartarus::GroupReaderPrx ("GroupReader", con);
}
