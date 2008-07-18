#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>

#include <debug.h>

#include "nss_tartarus.h"
#include <RPC/RPC.h>

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

//static Tartarus::RPC::Connection c(12346);
Tartarus::RPC::Connection& getConnection()
{
    typedef boost::shared_ptr<Tartarus::RPC::Connection> ConnectionPtr;
    typedef std::map<pid_t, ConnectionPtr> map;
    typedef map::iterator iterator;
    static map connections;
    const pid_t tid = syscall(__NR_gettid);
    iterator i = connections.find(tid);
    if(i == connections.end())
    {
        connections[tid] = ConnectionPtr(new Tartarus::RPC::Connection(12346));
    }
    return *connections[tid];
}

Tartarus::UserReaderPrx getUserReader()
{
    return Tartarus::UserReaderPrx("UserReader", getConnection());
}

Tartarus::GroupReaderPrx getGroupReader()
{
    return Tartarus::GroupReaderPrx("GroupReader", getConnection());
}
