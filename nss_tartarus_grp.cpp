#include <nss.h>
#include <grp.h>

#include <sys/types.h>
#include <errno.h>

#include <stdexcept>
#include <iterator>
#include <string>
#include <set>

#ifdef DEBUG
#include <iostream>
#endif

#include <Ice/Ice.h>
#include <SysDB.h>

#include "nss_tartarus.h"

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

/*static char *allocate_mem (char **buf, size_t *buflen, size_t len)
{
	char *next;

	if (!buf || !buflen || (*buflen < len))
		return NULL;

	next = *buf;
	*buf += len;
	*buflen -= len;
	return next;
}

static char *fill_record (char **buffer, size_t *buflen, const std::string &value)
{
	char *result = allocate_mem (buffer, buflen, value.size() + 1);
	if (result)
		std::strcpy(result, value.c_str());
	return result;
}*/

static nss_status fill_group (struct group *ent, const SysDB::GroupRecord& group, char **buffer, size_t *buflen)
{
	const std::string passwd("x");

	ent->gr_name = fill_record (buffer, buflen, group.name);
	if (ent->gr_name == NULL)
		return NSS_STATUS_TRYAGAIN;

	ent->gr_passwd = fill_record (buffer, buflen, passwd);
	if (ent->gr_passwd == NULL)
		return NSS_STATUS_TRYAGAIN;

	const SysDB::IdSeq ids = getGroupReader()->getUsers(group.gid);
	const SysDB::UserSeq users = getUserReader()->getUsers(ids);

	char *member_list_tst;
	size_t align = (unsigned long)(*buffer) % sizeof(char*);
	if (align != 0)
		align = sizeof(char*) - align;

	member_list_tst = allocate_mem (buffer, buflen, (users.size() + 1) * sizeof(char *) + align);
	if (member_list_tst == NULL)
		return NSS_STATUS_TRYAGAIN;

	ent->gr_mem = (char **)(member_list_tst + align);
	char **member_list = ent->gr_mem;

	for (SysDB::UserSeq::const_iterator i = users.begin(); i != users.end(); i++) {
		const std::string &username = i->name;
		size_t length, size = username.size();
		char *member = allocate_mem (buffer, buflen, size + 1);
		if (member == NULL)
			return NSS_STATUS_TRYAGAIN;

		*member_list++ = member;
		std::strcpy(member, username.c_str());
	}
	*member_list = 0;

	ent->gr_gid = group.gid;

	return NSS_STATUS_SUCCESS;
}


extern "C" {

nss_status _nss_tartarus_setgrent (int)
{
	nss_status ret = NSS_STATUS_SUCCESS;

#ifdef DEBUG
	std::cerr << __FUNCTION__ << " start" << std::endl;
#endif

	try {
		SysDB::GroupReaderPrx prx = getGroupReader();
	} catch (const Ice::Exception& error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setgrent Ice_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::bad_alloc error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setgrent memory_allocate_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setgrent runtime_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setgrent logic_error:" << error.what() << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setgrent message_error:" << msg << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_setgrent!!!\n"; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	}

#ifdef DEBUG
	std::cerr << __FUNCTION__ << " end" << std::endl;
#endif

	return ret;
}
nss_status _nss_tartarus_endgrent (void)
{
#ifdef DEBUG
	std::cerr << __FUNCTION__ << " start stop" << std::endl;
#endif

	return NSS_STATUS_SUCCESS;
}
nss_status _nss_tartarus_getgrgid_r (gid_t gid, struct group *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getgrgid_r start" << std::endl;
#endif

	try {
		ret = fill_group (result, getGroupReader()->getById(gid), &buffer, &buflen);

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
		std::cerr << "_nss_tartarus_getgrgid_r Ice_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::bad_alloc error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrgid_r memory_allocate_error: " << error.what() << std::endl;
#endif
		*errnop = ENOMEM;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrgid_r runtime_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrgid_r logic_error:" << error.what() << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrgid_r message_error:" << msg << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrgid_r!!!\n"; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	}

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getgrgid_r end" << std::endl;
#endif

	return ret;
}
nss_status _nss_tartarus_getgrnam_r (const char *name, struct group *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getgrnam_r start" << std::endl;
#endif

	try {
		ret = fill_group (result, getGroupReader()->getByName(name), &buffer, &buflen);

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
		std::cerr << "_nss_tartarus_getgrnam_r Ice_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::bad_alloc error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrnam_r memory_allocate_error: " << error.what() << std::endl;
#endif
		*errnop = ENOMEM;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::runtime_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrnam_r runtime_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrnam_r logic_error:" << error.what() << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrnam_r message_error:" << msg << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_getgrnam_r!!!\n"; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	}

#ifdef DEBUG
	std::cerr << "_nss_tartarus_getgrnam_r stop" << std::endl;
#endif

	return ret;
}
nss_status _nss_tartarus_getgrent_r (struct group *result, char *buffer, size_t buflen, int *errnop)
{
#ifdef DEBUG
	std::cerr << "_nss_tartarus_getgrent_r start stop" << std::endl;
#endif

//	return NSS_STATUS_UNAVAIL;
	return NSS_STATUS_NOTFOUND;
}
nss_status _nss_tartarus_initgroups_dyn (char *user, gid_t main_group, long int *start, long int *size, gid_t **groups, long int limit, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

#ifdef DEBUG
	std::cerr << "_nss_tartarus_initgroups_dyn start" << std::endl;
#endif

	try {
		SysDB::IdSeq ids = getGroupReader()->getGroupsForUserName(user);
//		SysDB::GroupSeq groupRecords = getGroupReader()->getGroups(ids);

//		for (SysDB::GroupSeq::iterator i = groupRecords.begin(); i != groupRecords.end(); i++) {
		for(SysDB::IdSeq::const_iterator i = ids.begin(); i != ids.end(); ++i) {
			if (*start == *size) {
				if (!realloc_groups (&size, &groups, limit))
					break;
			}
			(*groups)[(*start)++] = *i;
		}
	} catch (const Tartarus::iface::SysDB::NotFound& error) {
#ifdef DEBUG
		std::cerr << __FUNCTION__ <<" NotFound_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_NOTFOUND;
	} catch (const Ice::Exception& error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_initgroups Ice_error: " << error << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::bad_alloc error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_initgroups memory_allocate_error: " << error.what() << std::endl;
#endif
		*errnop = ENOMEM;
		ret = NSS_STATUS_NOTFOUND;
	} catch (std::runtime_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_initgroups runtime_error: " << error.what() << std::endl;
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_initgroups logic_error:" << error.what() << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (const char* msg) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_initgroups message_error:" << msg << std::endl;; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
#ifdef DEBUG
		std::cerr << "_nss_tartarus_initgroups!!!\n"; 
#endif
		ret = NSS_STATUS_UNAVAIL;
	}

#ifdef DEBUG
	std::cerr << "_nss_tartarus_initgroups_dyn stop" << std::endl;
#endif

	return ret;
}

} // extern "C"
