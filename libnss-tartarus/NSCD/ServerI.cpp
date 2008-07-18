#include "ServerI.h"
#include <debug.h>

using namespace Tartarus;

json_spirit::Value UserReader::call(const std::string & method, const json_spirit::Array & params)
{
    if(method == "getUserById")
    {
        uid_t uid = params[0].get_int();
        return getUser(uid).toValue();
    }
    else if(method == "getUserByName")
    {
        const std::string &username = params[0].get_str();
        return getUser(username).toValue();
    }
    else
    {
        std::ostringstream oss;
        oss << "UserReader object has not " << method << " method";
        throw Tartarus::RPC::RPCError(oss.str());
    }
}

json_spirit::Value GroupReader::call(const std::string & method, const json_spirit::Array & params)
{
    if(method == "getGroupById")
    {
        gid_t gid = params[0].get_int();
        return getGroup(gid).toValue();
    }
    else if(method == "getGroupByName")
    {
        const std::string &groupname = params[0].get_str();
        return getGroup(groupname).toValue();
    }
    else if(method == "getUsers")
    {
        gid_t gid = params[0].get_int();
        std::vector<std::string> v = getUsers(gid);
        json_spirit::Array ret;
        for(std::vector<std::string>::const_iterator i = v.begin(); i != v.end(); ++i)
            ret.push_back(*i);
        return ret;
    }
    else if(method == "getUserGroups")
    {
        const std::string &username = params[0].get_str();
        std::vector<gid_t> v = getUserGroups(username);
        json_spirit::Array ret;
        for(std::vector<gid_t>::const_iterator i = v.begin(); i != v.end(); ++i)
            ret.push_back((int)(*i));
        return ret;
    }
    else
    {
        std::ostringstream oss;
        oss << "UserReader object has not " << method << " method";
        throw Tartarus::RPC::RPCError(oss.str());
    }
}

UserRecord UserReaderI::getUser(uid_t uid)
{
        return UserRecord(uid, 100, "rlz", "Test", std::string("/home/rlz"));
}

UserRecord UserReaderI::getUser(const std::string &username)
{
        return UserRecord(666, 100, username, "Test", std::string("/home/") + username);
}

GroupRecord GroupReaderI::getGroup(gid_t gid)
{
        return GroupRecord(gid, "grpx");
}

GroupRecord GroupReaderI::getGroup(const std::string &groupname)
{
        return GroupRecord(666, groupname);
}

std::vector<std::string> GroupReaderI::getUsers(gid_t gid)
{
        std::vector<std::string> ret;
        ret.push_back("one");
        ret.push_back("two");
        ret.push_back("three");
        return ret;
}

std::vector<gid_t> GroupReaderI::getUserGroups(const std::string &username)
{
        std::vector<gid_t> ret;
        ret.push_back(5);
        ret.push_back(6);
        ret.push_back(7);
        return ret;
}
