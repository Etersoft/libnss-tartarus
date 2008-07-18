#include <nss.h>
#include <pwd.h>

#include <sys/types.h>
#include <errno.h>

#include <stdexcept>
#include <iterator>
#include <string>

#include <debug.h>

#include "nss_tartarus.h"

static nss_status fill_user (struct passwd *ent, const Tartarus::UserRecord& user, char **buffer, size_t *buflen)
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
}

extern "C" {

nss_status _nss_tartarus_setpwent(void)
{
	nss_status ret = NSS_STATUS_SUCCESS;

	debug (va("%s: %s", __FUNCTION__, "start"));

	try {
		Tartarus::UserReaderPrx prx = getUserReader();
	} catch (std::bad_alloc error) {
		debug (va("%s: %s - %s", __FUNCTION__, "memory_allocate_error", error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
		debug (va("%s: %s - %s", __FUNCTION__, "runtime_error", error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
		debug (va("%s: %s - %s", __FUNCTION__, "logic_error", error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
		debug (va("%s: %s - %s", __FUNCTION__, "message_error", msg));
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
		debug (va("%s: %s", __FUNCTION__, "unknown_error"));
		ret = NSS_STATUS_UNAVAIL;
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
	nss_status ret = NSS_STATUS_SUCCESS;

	debug (va("%s: %s", __FUNCTION__, "start"));

	try {
		ret = fill_user (result, getUserReader().getUser(uid), &buffer, &buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
//	} catch (const Tartarus::iface::SysDB::NotFound& error) {
//		debug (va("%s: %s", __FUNCTION__, "NotFound_error", error));
//		ret = NSS_STATUS_NOTFOUND;
	} catch (std::bad_alloc error) {
		debug (va("%s: %s - %s", __FUNCTION__, "memory_allocate_error", error.what()));
		*errnop = ENOMEM;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
		debug (va("%s: %s - %s", __FUNCTION__, "runtime_error", error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
		debug (va("%s: %s - %s", __FUNCTION__, "logic_error", error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
		debug (va("%s: %s - %s", __FUNCTION__, "message_error", msg));
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
		debug (va("%s: %s", __FUNCTION__, "unknown_error"));
		ret = NSS_STATUS_UNAVAIL;
	}

	debug (va("%s: %s", __FUNCTION__, "end"));

	return ret;
}

nss_status _nss_tartarus_getpwnam_r(const char *name, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

	debug (va("%s: %s", __FUNCTION__, "start"));

	try {
		ret = fill_user (result, getUserReader().getUser(name), &buffer, &buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
//	} catch (const Tartarus::iface::SysDB::NotFound& error) {
//		debug (va("%s: %s", __FUNCTION__, "NotFound_error", error));
//		ret = NSS_STATUS_NOTFOUND;
	} catch (std::bad_alloc error) {
		debug (va("%s: %s - %s", __FUNCTION__, "memory_allocate_error", error.what()));
		*errnop = ENOMEM;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
		debug (va("%s: %s - %s", __FUNCTION__, "runtime_error", error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
		debug (va("%s: %s - %s", __FUNCTION__, "logic_error", error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
		debug (va("%s: %s - %s", __FUNCTION__, "message_error", msg));
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
		debug (va("%s: %s", __FUNCTION__, "unknown_error"));
		ret = NSS_STATUS_UNAVAIL;
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

} // extern "C"
