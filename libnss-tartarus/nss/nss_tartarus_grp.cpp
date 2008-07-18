#include <nss.h>
#include <grp.h>

#include <sys/types.h>
#include <errno.h>

#include <stdexcept>
#include <iterator>
#include <string>
#include <set>

#include <debug.h>

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

static nss_status fill_group (struct group *ent, const Tartarus::GroupRecord& group, char **buffer, size_t *buflen)
{
	ent->gr_name = fill_record (buffer, buflen, group.name);
	if (ent->gr_name == NULL)
		return NSS_STATUS_TRYAGAIN;

	ent->gr_passwd = fill_record (buffer, buflen, group.passwd);
	if (ent->gr_passwd == NULL)
		return NSS_STATUS_TRYAGAIN;

	const std::vector<std::string> users = getGroupReader().getUsers(group.gid);

	char *member_list_tst;
	size_t align = (unsigned long)(*buffer) % sizeof(char*);
	if (align != 0)
		align = sizeof(char*) - align;

	member_list_tst = allocate_mem (buffer, buflen, (users.size() + 1) * sizeof(char *) + align);
	if (member_list_tst == NULL)
		return NSS_STATUS_TRYAGAIN;

	ent->gr_mem = (char **)(member_list_tst + align);
	char **member_list = ent->gr_mem;

	for (std::vector<std::string>::const_iterator i = users.begin(); i != users.end(); i++) {
		const std::string &username = *i;
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
	debug(va("%s: %s", __FUNCTION__, "start"));
	try {
		Tartarus::GroupReaderPrx prx = getGroupReader();
	} catch (std::exception error) {
		debug(va("%s: %s", __FUNCTION__, error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
		debug (va("%s: %s", __FUNCTION__, "unknown_error"));
		ret = NSS_STATUS_UNAVAIL;
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
	nss_status ret = NSS_STATUS_SUCCESS;

	debug (va("%s: %s", __FUNCTION__, "start"));

	try {
		ret = fill_group (result, getGroupReader().getGroup(gid), &buffer, &buflen);

		if (ret == NSS_STATUS_TRYAGAIN)
			*errnop = errno = ERANGE;
		else
			*errnop = 0;
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
nss_status _nss_tartarus_getgrnam_r (const char *name, struct group *result, char *buffer, size_t buflen, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

	debug (va("%s: %s", __FUNCTION__, "start"));

	try {
		ret = fill_group (result, getGroupReader().getGroup(name), &buffer, &buflen);

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
nss_status _nss_tartarus_getgrent_r (struct group *result, char *buffer, size_t buflen, int *errnop)
{
	debug (va("%s: %s", __FUNCTION__, "start stop"));

//	return NSS_STATUS_UNAVAIL;
	return NSS_STATUS_NOTFOUND;
}
nss_status _nss_tartarus_initgroups_dyn (char *user, gid_t main_group, long int *start, long int *size, gid_t **groups, long int limit, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

	debug (va("%s: %s", __FUNCTION__, "start"));

	try {
		std::vector<uid_t> ids = getGroupReader().getUserGroups(user);

		for(std::vector<uid_t>::const_iterator i = ids.begin(); i != ids.end(); ++i) {
			if (*start == *size) {
				if (!realloc_groups (&size, &groups, limit))
					break;
			}
			(*groups)[(*start)++] = *i;
		}
//	} catch (const Tartarus::iface::SysDB::NotFound& error) {
//		debug (va("%s: %s", __FUNCTION__, "NotFound_error", error));
//		ret = NSS_STATUS_NOTFOUND;
	} catch (std::bad_alloc error) {
		debug (va("%s: %s - %s", __FUNCTION__, "memory_allocate_error", error.what()));
		*errnop = ENOMEM;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::exception error) {
		debug (va("%s: %s", __FUNCTION__, error.what()));
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
		debug (va("%s: %s", __FUNCTION__, "unknown_error"));
		ret = NSS_STATUS_UNAVAIL;
	}

	debug (va("%s: %s", __FUNCTION__, "end"));

	return ret;
}

} // extern "C"
