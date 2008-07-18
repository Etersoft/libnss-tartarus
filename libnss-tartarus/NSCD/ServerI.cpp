#include "ServerI.h"
#include "SysDBClient.h"
#include <debug.h>

using namespace Tartarus;

UserRecord makeUserRecord(const SysDB::UserRecord & user)
{
    return UserRecord(user.uid, user.gid, user.name, user.fullName, std::string("/home/remote/") + user.name, user.shell);
}

GroupRecord makeGroupRecord(const SysDB::GroupRecord & group)
{
    return GroupRecord(group.gid, group.name);
}


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
        try {
                SysDB::UserRecord user = getUserReader()->getById(uid);
                return makeUserRecord(user);
        } catch (const SysDB::NotFound& error) {
                throw RPC::RPCError("NotFound");
        } catch (const Ice::Exception& error) {
                throw RPC::RPCError(error.ice_name());
        }
}

UserRecord UserReaderI::getUser(const std::string & name)
{
        try {
                SysDB::UserRecord user = getUserReader()->getByName(name);
                return makeUserRecord(user);
        } catch (const SysDB::NotFound& error) {
                throw RPC::RPCError("NotFound");
        } catch (const Ice::Exception& error) {
                throw RPC::RPCError(error.ice_name());
        }
}

GroupRecord GroupReaderI::getGroup(gid_t gid)
{
        try {
                SysDB::GroupRecord group = getGroupReader()->getById(gid);
                return makeGroupRecord(group);
        } catch (const SysDB::NotFound& error) {
                throw RPC::RPCError("NotFound");
        } catch (const Ice::Exception& error) {
                throw RPC::RPCError(error.ice_name());
        }
}

GroupRecord GroupReaderI::getGroup(const std::string & name)
{
        try {
                SysDB::GroupRecord group = getGroupReader()->getByName(name);
                return makeGroupRecord(group);
        } catch (const SysDB::NotFound& error) {
                throw RPC::RPCError("NotFound");
        } catch (const Ice::Exception& error) {
                throw RPC::RPCError(error.ice_name());
        }
}

std::vector<std::string> GroupReaderI::getUsers(gid_t gid)
{
        try {
                const SysDB::IdSeq ids = getGroupReader()->getUsers(gid);
                const SysDB::UserSeq users = getUserReader()->getUsers(ids);
                std::vector<std::string> ret;
                for(SysDB::UserSeq::const_iterator i = users.begin(); i != users.end(); ++i)
                        ret.push_back(i->name);
                return ret;
        } catch (const SysDB::NotFound& error) {
                throw RPC::RPCError("NotFound");
        } catch (const Ice::Exception& error) {
                throw RPC::RPCError(error.ice_name());
        }
}

std::vector<gid_t> GroupReaderI::getUserGroups(const std::string &name)
{
        try {
                SysDB::IdSeq ids = getGroupReader()->getGroupsForUserName(name);
                std::vector<gid_t> gids;
                for(SysDB::IdSeq::const_iterator i = ids.begin(); i != ids.end(); ++i)
                        gids.push_back(*i);
                return gids;
        } catch (const SysDB::NotFound& error) {
                throw RPC::RPCError("NotFound");
        } catch (const Ice::Exception& error) {
                throw RPC::RPCError(error.ice_name());
        }
}
