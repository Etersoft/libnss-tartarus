#include <nss.h>
#include <grp.h>

#include <sys/types.h>
#include <errno.h>

#include <stdexcept>
#include <iostream>

#include "lock.h"

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

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

extern "C" {

nss_status _nss_tartarus_setgrent (int)
{
	return NSS_STATUS_SUCCESS;
}
nss_status _nss_tartarus_endgrent (void)
{
	return NSS_STATUS_SUCCESS;
}
nss_status _nss_tartarus_getgrgid_r (gid_t gid, struct group *grp, char *buffer, size_t buflen, int *errnop)
{
	return NSS_STATUS_NOTFOUND;
}
nss_status _nss_tartarus_getgrnam_r (const char *name, struct group *grp, char *buffer, size_t buflen, int *errnop)
{
	return NSS_STATUS_NOTFOUND;
}
nss_status _nss_tartarus_getgrent_r (struct group *result, char *buffer, size_t buflen, int *errnop)
{
	return NSS_STATUS_NOTFOUND;
}
nss_status _nss_tartarus_initgroups_dyn (char *user, gid_t main_group, long int *start, long int *size, gid_t **groups, long int limit, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;
	
	Lock lock(&mutex);

	std::cerr << "_nss_tartarus_initgroups start" << std::endl;

	try {
//		for (Groups::iterator i = add_groups.begin(); i != add_groups.end(); i++) {
//			if (*start == *size) {
//				if (!realloc_groups (&size, &groups, limit))
//					break;
//			}
//			(*groups)[(*start)++] = *i;
//		}
	} catch (std::bad_alloc error) {
//		std::cerr << "_nss_tartarus_initgroups memory_allocate_error: " << error.what() << std::endl;
		*errnop = ENOMEM;
		ret = NSS_STATUS_NOTFOUND;
	} catch (std::runtime_error error) {
//		std::cerr << "_nss_tartarus_initgroups runtime_error: " << error.what() << std::endl;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
//		std::cerr << "_nss_tartarus_initgroups logic_error:" << error.what() << std::endl;; 
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
//		std::cerr << "_nss_tartarus_initgroups!!!\n"; 
		ret = NSS_STATUS_UNAVAIL;
	}

	std::cerr << "_nss_tartarus_initgroups end" << std::endl;

	return ret;
}

} // extern "C"
