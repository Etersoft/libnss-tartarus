#include <TartarusDebug.h>
#include <TartarusClientI.h>

using namespace Tartarus;

UserRecord UserReaderPrx::getUser(uid_t uid)
{
    json_spirit::Array params;
    params.push_back((int)uid);
    json_spirit::Value result(connection().call(name(), "getUserById", params));
    const json_spirit::Object &o = result.get_obj();
    return UserRecord(o);
}

UserRecord UserReaderPrx::getUser(const std::string &username)
{
    debug("getUser start");
    json_spirit::Array params;
    params.push_back(username);
    debug("getUser call");
    json_spirit::Value result(connection().call(name(), "getUserByName", params));
    debug("getUser result");
    const json_spirit::Object &o = result.get_obj();
    debug("getUser construct");
    return UserRecord(o);
}

GroupRecord GroupReaderPrx::getGroup(gid_t gid)
{
    json_spirit::Array params;
    params.push_back((int)gid);
    json_spirit::Value result(connection().call(name(), "getGroupById", params));
    const json_spirit::Object &o = result.get_obj();
    return GroupRecord(o);
}

GroupRecord GroupReaderPrx::getGroup(const std::string &groupname)
{
    json_spirit::Array params;
    params.push_back(groupname);
    json_spirit::Value result(connection().call(name(), "getGroupByName", params));
    const json_spirit::Object &o = result.get_obj();
    return GroupRecord(o);
}

std::vector<std::string> GroupReaderPrx::getUsers(gid_t gid)
{
    json_spirit::Array params;
    params.push_back((int)gid);
    json_spirit::Value result(connection().call(name(), "getUsers", params));
    const json_spirit::Array & a = result.get_array();
    std::vector<std::string> ret;
    ret.reserve(a.size());
    for(json_spirit::Array::const_iterator i = a.begin(); i != a.end(); ++i)
        ret.push_back(i->get_str());
    return ret;
}

std::vector<gid_t> GroupReaderPrx::getUserGroups(const std::string &username)
{
    json_spirit::Array params;
    params.push_back(username);
    json_spirit::Value result(connection().call(name(), "getUserGroups", params));
    const json_spirit::Array & a = result.get_array();
    std::vector<gid_t> ret;
    ret.reserve(a.size());
    for(json_spirit::Array::const_iterator i = a.begin(); i != a.end(); ++i)
        ret.push_back(i->get_int());
    return ret;
}
