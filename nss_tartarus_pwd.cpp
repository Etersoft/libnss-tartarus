#include <nss.h>
#include <pwd.h>

#include <sys/types.h>
#include <errno.h>

#include <stdexcept>
#include <iterator>
#include <string>

#ifdef DEBUG
#include <iostream>
#endif

#include <Ice/Ice.h>
#include <SysDB.h>

#include "nss_tartarus.h"

static nss_status fill_user (struct passwd *ent, const SysDB::UserRecord& user, char **buffer, size_t *buflen)
{
	const std::string passwd("x");
	std::string home("/home/");
	home.append(user.name);

#ifdef DEBUG
		std::cerr << __FUNCTION__ <<" start" << std::endl;
#endif
 
	ent->pw_name = fill_record (buffer, buflen, user.name);
	if (ent->pw_name == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_passwd = fill_record (buffer, buflen, passwd);
	if (ent->pw_passwd == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_gecos = fill_record (buffer, buflen, user.fullName);
	if (ent->pw_gecos == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_dir = fill_record (buffer, buflen, home);
	if (ent->pw_dir == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_shell = fill_record (buffer, buflen, user.shell);
	if (ent->pw_shell == NULL) {
		return NSS_STATUS_TRYAGAIN;
	}

	ent->pw_uid = user.uid;
	ent->pw_gid = user.gid;

#ifdef DEBUG
		std::cerr << __FUNCTION__ <<" end" << std::endl;
#endif

	return NSS_STATUS_SUCCESS;
}

extern "C" {

nss_status _nss_tartarus_setpwent(void)
{
	nss_status ret = NSS_STATUS_SUCCESS;

#ifdef DEBUG
	std::cerr << "_nss_tartarus_setpwent start" << std::endl;
#endif

	try {
		SysDB::UserReaderPrx prx = getUserReader();
	} catch (const Ice::Exception& error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setpwent Ice_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::bad_alloc error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setpwent memory_allocate_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setpwent runtime_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setpwent logic_error:" << error.what() << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setpwent message_error:" << msg << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setpwent!!!\n"; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	}

#ifdef DEBUG
	std::cerr << "_nss_tartarus_setpwent end" << std::endl;
#endif

	return ret;
}

nss_status _nss_tartarus_endpwent(void)
{
#ifdef DEBUG
	std::cerr << "_nss_tartarus_endpwent start stop" << std::endl;
#endif

	return NSS_STATUS_SUCCESS;
}

nss_status _nss_tartarus_getpwuid_r(uid_t uid, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getpwuid_r start" << std::endl;
#endif

	try {
		std::cerr << "_nss_tartarus_getpwuid_r try" << std::endl;
		ret = fill_user (result, getUserReader()->getById(uid), &buffer, &buflen);
		std::cerr << "_nss_tartarus_getpwuid_r filled" << std::endl;

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
	} catch (const Tartarus::iface::SysDB::NotFound& error) {
#ifdef DEBUG
		std::cerr << __FUNCTION__ <<" NotFound_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_NOTFOUND;
	} catch (const Ice::Exception& error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwuid_r Ice_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::bad_alloc error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwuid_r memory_allocate_error: " << error.what() << std::endl;
#endif
		*errnop = ENOMEM;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwuid_r runtime_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwuid_r logic_error:" << error.what() << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwuid_r message_error:" << msg << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwuid_r!!!\n"; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	}

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getpwuid_r end" << std::endl;
#endif

	return ret;
}

nss_status _nss_tartarus_getpwnam_r(const char *name, struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getpwnam_r start for: " << name << std::endl;
#endif

	try {
		SysDB::UserRecord user = getUserReader()->getByName(name);
#ifdef DEBUG
	std::cerr << "_nss_tartarus_getpwnam_r user id: " << user.uid << std::endl;
#endif
		ret = fill_user (result, user, &buffer, &buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
	} catch (const Tartarus::iface::SysDB::NotFound& error) {
#ifdef DEBUG
		std::cerr << __FUNCTION__ <<" NotFound_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_NOTFOUND;
	} catch (const Ice::Exception& error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwnam_r Ice_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::bad_alloc error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwnam_r memory_allocate_error: " << error.what() << std::endl;
#endif
		*errnop = ENOMEM;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwnam_r runtime_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwnam_r logic_error:" << error.what() << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwnam_r message_error:" << msg << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getpwnam_r!!!\n"; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	}

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getpwnam_r end" << std::endl;
#endif

	return ret;
}

nss_status _nss_tartarus_getpwent_r(struct passwd *result, char *buffer, size_t buflen, int *errnop)
{
#ifdef DEBUG
	std::cerr << "_nss_tartarus_getpwent_r start stop" << std::endl;
#endif

//	return NSS_STATUS_UNAVAIL;
	return NSS_STATUS_NOTFOUND;
}

} // extern "C"
