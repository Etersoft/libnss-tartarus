#ifndef LIBNSS_ROLE_ROLE_H_
#define LIBNSS_ROLE_ROLE_H_

#include <map>
#include <set>
#include <vector>
#include <string>
#include <fstream>

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

#endif /*LIBNSS_ROLE_ROLE_H_*/
