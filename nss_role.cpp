#include <nss.h>
#include <grp.h>

#include <sys/types.h>
#include <errno.h>

#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
//#include <iostream>

#include <boost/spirit/core.hpp>

typedef std::set<gid_t> Groups;
typedef std::vector<gid_t> Privs;
typedef std::map<gid_t, Privs> Roles;
typedef std::pair<gid_t, Privs> Role;

class RoleParser
{
protected:
	std::string filename;
	std::ifstream in;
	bool Parse(char const* str, gid_t &role_id, Privs &privs);
public:
	RoleParser (const std::string &filename = "/etc/role"):
		filename(filename) {}
	bool Update(Roles &roles);
};

using boost::spirit::parse;
using boost::spirit::uint_p;
using boost::spirit::space_p;
using boost::spirit::assign;
using boost::spirit::push_back_a;

bool RoleParser::Parse(char const* str, gid_t &role_id, Privs &privs)
{
	return parse(str,
	(
	 uint_p[assign(role_id)] >>
	 ':' >>
	 uint_p[push_back_a(privs)] >>
	 *(',' >> uint_p[push_back_a(privs)])),
	 space_p).full;
}

bool RoleParser::Update(Roles &roles)
{
	in.open(filename.c_str());
	if (!in)
		return false;

	roles.clear();
	while (in && !in.eof())
	{
		Privs privs;
		gid_t role_id;
		std::string rbuf;

		getline (in, rbuf);
		if (rbuf.length() == 0)
			continue;
		if (!Parse(rbuf.c_str(), role_id, privs))
			continue;

		roles.insert(Role(role_id, privs));
	}

	return true;
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

static void add_groups_insert (gid_t gid, const Roles &roles, Groups &groups)
{
	Roles::const_iterator iter = roles.find(gid);
	if (iter != roles.end()) {
		const Privs &privs = iter->second;
		groups.insert(privs.begin(), privs.end());
	}
}

extern "C" {

enum nss_status _nss_role_initgroups_dyn (char *user, gid_t main_group, long int *start, long int *size, gid_t **groups, long int limit, int *errnop)
{
	nss_status ret = NSS_STATUS_SUCCESS;

//	std::cerr << "_nss_role_initgroups start" << std::endl;

	try {
		Roles roles;
		Groups add_groups;
		long int last_start = *start;
		if (!RoleParser().Update(roles))
			return ret;

		add_groups_insert(main_group, roles, add_groups);
		for (long int i = 0; i < last_start; i++)
			add_groups_insert((*groups)[i], roles, add_groups);

		add_groups.erase(main_group);
		for (long int i = 0; i < last_start; i++)
			add_groups.erase((*groups)[i]);

		for (Groups::iterator i = add_groups.begin(); i != add_groups.end(); i++) {
			if (*start == *size) {
				if (!realloc_groups (&size, &groups, limit))
					break;
			}
			(*groups)[(*start)++] = *i;
		}
	} catch (std::bad_alloc error) {
//		std::cerr << "_nss_role_initgroups memory_allocate_error: " << error.what() << std::endl;
		*errnop = ENOMEM;
		ret = NSS_STATUS_NOTFOUND;
	} catch (std::runtime_error error) {
//		std::cerr << "_nss_role_initgroups runtime_error: " << error.what() << std::endl;
		ret = NSS_STATUS_UNAVAIL;
	} catch (std::logic_error error) {
//		std::cerr << "_nss_role_initgroups logic_error:" << error.what() << std::endl;; 
		ret = NSS_STATUS_UNAVAIL;
	} catch (...) {
//		std::cerr << "_nss_role_initgroups!!!\n"; 
		ret = NSS_STATUS_UNAVAIL;
	}

//	std::cerr << "_nss_role_initgroups end" << std::endl;

	return ret;
}

} // extern "C"
