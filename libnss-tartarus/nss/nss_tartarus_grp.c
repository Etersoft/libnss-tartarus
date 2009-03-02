#include <nss.h>
#include <grp.h>

#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <Debug.h>
#include "ClientDBus.h"

nss_status _nss_tartarus_setgrent (int none)
{
	nss_status ret = NSS_STATUS_UNAVAIL;
	{
		ret = NSS_STATUS_SUCCESS;
	}
	debug (va("%s: %s", __FUNCTION__, "end"));
	return ret;
}

nss_status _nss_tartarus_endgrent (void)
{
	debug(va("%s: %s", __FUNCTION__, "start stop"));
	return NSS_STATUS_SUCCESS;
}

nss_status _nss_tartarus_getgrgid_r (gid_t gid, struct group *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_UNAVAIL;
	debug (va("%s: %s: %d", __FUNCTION__, "start", gid));
	{
		ret = client_dbus_get_group_by_id (gid, result, buffer, buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
	}
	debug (va("%s: %s", __FUNCTION__, "end"));
	return ret;
}
nss_status _nss_tartarus_getgrnam_r (const char *name, struct group *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_UNAVAIL;

	debug (va("%s: %s: %s", __FUNCTION__, "start", name));

	{
		ret = client_dbus_get_group_by_name (name, result, buffer, buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
	}
	debug (va("%s: %s", __FUNCTION__, "end"));
	return ret;
}
nss_status _nss_tartarus_getgrent_r (struct group *result, char *buffer, size_t buflen, int *errnop)
{
	debug (va("%s: %s", __FUNCTION__, "start stop"));
//!//	return NSS_STATUS_UNAVAIL;
	return NSS_STATUS_NOTFOUND;
}
nss_status _nss_tartarus_initgroups_dyn (char *user, gid_t main_group, long int *start, long int *size, gid_t **groups, long int limit, int *errnop)
{
	nss_status ret = NSS_STATUS_UNAVAIL;
	debug (va("%s: %s: %s", __FUNCTION__, "start", user));
	{
		ret = client_dbus_init_groups_for_user(user, start, size, groups, limit);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
	}
	debug (va("%s: %s", __FUNCTION__, "end"));
	return ret;
}
