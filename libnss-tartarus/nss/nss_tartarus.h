#ifndef LIBNSS_TARTARUS_H_
#define LIBNSS_TARTARUS_H_

#include <string.h>
#include <nss.h>

typedef enum nss_status nss_status;

char *allocate_mem (char **buf, size_t *buflen, size_t len);

/*static inline char *fill_record (char **buffer, size_t *buflen, const char *value)
{
	char *result = allocate_mem (buffer, buflen, strlen(value) + 1);
	if (result)
		strcpy(result, value);
	return result;
}*/

#endif /*LIBNSS_TARTARUS_H_*/
