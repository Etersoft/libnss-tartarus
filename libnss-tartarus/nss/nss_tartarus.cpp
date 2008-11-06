#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>

#include <debug.h>

#include "nss_tartarus.h"
#include <RPC/RPC.h>
#include <stdexcept>

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

Tartarus::RPC::Connection& getConnection()
{
    static Tartarus::RPC::Connection *connection = 0;

    if (!connection) {
        connection = new Tartarus::RPC::Connection(NSS_TARTARUS_SOCKET_PATH);
        if (!connection)
            throw std::runtime_error("Can't establish connection");
    }
    return *connection;
}

Tartarus::UserReaderPrx getUserReader()
{
    return Tartarus::UserReaderPrx("UserReader", getConnection());
}

Tartarus::GroupReaderPrx getGroupReader()
{
    return Tartarus::GroupReaderPrx("GroupReader", getConnection());
}
