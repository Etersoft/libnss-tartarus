#include <sys/types.h>
#include <linux/unistd.h>
#include <sys/syscall.h>

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
