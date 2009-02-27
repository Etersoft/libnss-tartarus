#include <nss.h>
#include <pwd.h>

#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#include <Debug.h>
#include "ClientDBus.h"

/*static nss_status fill_user (struct passwd *ent, const Tartarus::UserRecord& user, char **buffer, size_t *buflen)
{
	debug (va("%s: %s", __FUNCTION__, "start"));
 
	ent->pw_name = fill_record (buffer, buflen, user.name);
	if (ent->pw_name == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_passwd = fill_record (buffer, buflen, user.passwd);
	if (ent->pw_passwd == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_gecos = fill_record (buffer, buflen, user.gecos);
	if (ent->pw_gecos == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_dir = fill_record (buffer, buflen, user.home);
	if (ent->pw_dir == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_shell = fill_record (buffer, buflen, user.shell);
	if (ent->pw_shell == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_uid = user.uid;
	ent->pw_gid = user.gid;

	debug (va("%s: %s", __FUNCTION__, "end"));
	return NSS_STATUS_SUCCESS;
}*/

nss_status _nss_tartarus_setpwent(void)
{
	nss_status ret = NSS_STATUS_UNAVAIL;
	debug (va("%s: %s", __FUNCTION__, "start"));
	{
//		Tartarus::UserReaderPrx prx = getUserReader();
//		ret = NSS_STATUS_SUCCESS;
	}
	debug (va("%s: %s", __FUNCTION__, "end"));
	return ret;
}

nss_status _nss_tartarus_endpwent(void)
{
	debug (va("%s: %s", __FUNCTION__, "start stop"));
	return NSS_STATUS_SUCCESS;
}

nss_status _nss_tartarus_getpwuid_r(uid_t uid, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_UNAVAIL;
	debug (va("%s: %s", __FUNCTION__, "start"));
	{
		ret = client_dbus_get_user_by_id (uid, result, buffer, buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
	}
	debug (va("%s: %s", __FUNCTION__, "end"));
	return ret;
}

nss_status _nss_tartarus_getpwnam_r(const char *name, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_UNAVAIL;
	debug (va("%s: %s", __FUNCTION__, "start"));
	{
		ret = client_dbus_get_user_by_name (name, result, buffer, buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
	}
	debug (va("%s: %s", __FUNCTION__, "end"));
	return ret;
}

nss_status _nss_tartarus_getpwent_r(struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
	debug (va("%s: %s", __FUNCTION__, "start stop"));
//	return NSS_STATUS_UNAVAIL;
	return NSS_STATUS_NOTFOUND;
}
