#include <string.h>
#include <nss.h>

typedef enum nss_status nss_status;

char *allocate_mem (char **buf, size_t *buflen, size_t len);


static char *allocate_mem (char **buf, size_t *buflen, size_t len)
{
	char *next;

	if (!buf || !buflen || (*buflen < len))
		return NULL;

	next = *buf;
	*buf += len;
	*buflen -= len;
	return next;
}

static inline char *fill_record (char **buffer, size_t *buflen, const char *value)
{
	char *result = allocate_mem (buffer, buflen, strlen(value) + 1);
	if (result)
		strcpy(result, value);
	return result;
}

static bool realloc_groups (long int **size, gid_t ***groups, long int limit)
{
	long int new_size;
	gid_t *new_groups;

	new_size = 2 * (**size);
	if (limit > 0) {
		if (**size == limit)
			return false;

		if (new_size > limit)
			new_size = limit;
	}

	new_groups = (gid_t *)
		realloc((**groups),
			new_size * sizeof(***groups));
	if (!new_groups)
		return false;

	**groups = new_groups;
	**size = new_size;

	return true;
}
