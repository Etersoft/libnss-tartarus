#include "ServerDBUS.h"
#include "SysDBClient.h"
#include <Debug.h>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace Tartarus;

static const char* notFoundError = "ru.tartarus.DBus.TNSCD.ErrorNotFound";
static const char* tartarusError = "ru.tartarus.DBus.TNSCD.ErrorTartarus";
static const char* iceError      = "ru.tartarus.DBus.TNSCD.ErrorIce";
static const char* internalError = "ru.tartarus.DBus.TNSCD.ErrorInternal";

static inline void fillUser(
    const SysDB::UserRecord & user,
    uint32_t& uid,
    uint32_t& gid,
    std::string& name,
    std::string& gecos,
    std::string& home,
    std::string& shell,
    std::string& passwd)
{
    uid    = user.uid;
    gid    = user.gid;
    name   = user.name;
    gecos  = user.fullName;
    home   = std::string("/home/remote/") + user.name;
    shell  = user.shell;
    passwd = "x";
}

class UserNamesInserter
{
    typedef std::vector< std::string > UserNames;
    UserNames& userNames;
public:
    UserNamesInserter(UserNames& userNamesRef):
        userNames(userNamesRef) {
        userNames.clear();
    }
    void operator() (const SysDB::UserRecord &user) {
        userNames.push_back(user.name);
    }
};

static inline void fillGroup(
    const SysDB::GroupRecord & group,
    uint32_t& gid,
    std::string& name,
    std::string& passwd,
    uint32_t& users_size,
    std::vector< std::string >& users,
    const SysDB::UserSeq user_list)
{
    UserNamesInserter inserter(users);

    gid    = group.gid;
    name   = group.name;
    passwd = "x";
    users_size = user_list.size();

    users.reserve(user_list.size());
    for_each(user_list.begin(), user_list.end(), inserter);
}


void ServerDBUS::getUserById(
    const uint32_t& userid, 
    uint32_t& uid,
    uint32_t& gid,
    std::string& name,
    std::string& gecos,
    std::string& home,
    std::string& shell,
    std::string& passwd)
{
    try {
        SysDB::UserRecord user = getUserReader()->getById(userid);
        fillUser(user, uid, gid, name, gecos, home, shell, passwd);
    } catch (const core::NotFoundError& error) {
        throw DBus::Error(notFoundError, (error.reason + " (" + error.response + ")").c_str());
    } catch (const core::Error& error) {
        throw DBus::Error(tartarusError, error.reason.c_str());
    } catch (const Ice::Exception& error) {
        setReaderReInit();
        throw DBus::Error(iceError, error.ice_name().c_str());
    } catch (const std::runtime_error& error) {
        setReaderReInit();
        throw DBus::Error(internalError, error.what());
    }
}

void ServerDBUS::getUserByName(
    const std::string& username,
    uint32_t& uid,
    uint32_t& gid,
    std::string& name,
    std::string& gecos,
    std::string& home,
    std::string& shell,
    std::string& passwd)
{
    std::cerr << "getUserByName " << username << std::endl;
    try {
        SysDB::UserRecord user = getUserReader()->getByName(username);
        fillUser(user, uid, gid, name, gecos, home, shell, passwd);
    } catch (const core::NotFoundError& error) {
        throw DBus::Error(notFoundError, (error.reason + " (" + error.response + ")").c_str());
    } catch (const core::Error& error) {
        throw DBus::Error(tartarusError, error.reason.c_str());
    } catch (const Ice::Exception& error) {
        setReaderReInit();
        throw DBus::Error(iceError, error.ice_name().c_str());
    } catch (const std::runtime_error& error) {
        setReaderReInit();
        throw DBus::Error(internalError, error.what());
    }
}

void ServerDBUS::getGroupById(
    const uint32_t& groupid,
    uint32_t& gid,
    std::string& name,
    std::string& passwd,
    uint32_t& users_size,
    std::vector< std::string >& users)
{
    try {
        SysDB::GroupRecord group = getGroupReader()->getById(groupid);
        const SysDB::IdSeq ids = getGroupReader()->getUsers(groupid);
        const SysDB::UserSeq user_list = getUserReader()->getUsers(ids);
        fillGroup(group, gid, name, passwd, users_size, users, user_list);
    } catch (const core::NotFoundError& error) {
        throw DBus::Error(notFoundError, (error.reason + " (" + error.response + ")").c_str());
    } catch (const core::Error& error) {
        throw DBus::Error(tartarusError, error.reason.c_str());
    } catch (const Ice::Exception& error) {
        setReaderReInit();
        throw DBus::Error(iceError, error.ice_name().c_str());
    } catch (const std::runtime_error& error) {
        setReaderReInit();
        throw DBus::Error(internalError, error.what());
    }
}

void ServerDBUS::getGroupByName(
    const std::string& groupname,
    uint32_t& gid,
    std::string& name,
    std::string& passwd,
    uint32_t& users_size,
    std::vector< std::string >& users)
{
    try {
        SysDB::GroupRecord group = getGroupReader()->getByName(groupname);
        const SysDB::IdSeq ids = getGroupReader()->getUsers(group.gid);
        const SysDB::UserSeq user_list = getUserReader()->getUsers(ids);
        fillGroup(group, gid, name, passwd, users_size, users, user_list);
    } catch (const core::NotFoundError& error) {
        throw DBus::Error(notFoundError, (error.reason + " (" + error.response + ")").c_str());
    } catch (const core::Error& error) {
        throw DBus::Error(tartarusError, error.reason.c_str());
    } catch (const Ice::Exception& error) {
        setReaderReInit();
        throw DBus::Error(iceError, error.ice_name().c_str());
    } catch (const std::runtime_error& error) {
        setReaderReInit();
        throw DBus::Error(internalError, error.what());
    }
}

std::vector< uint32_t > ServerDBUS::getUserGroups(const std::string& username)
{
    try {
        SysDB::IdSeq ids = getGroupReader()->getGroupsForUserName(username);
        std::vector<gid_t> gids;
        for(SysDB::IdSeq::const_iterator i = ids.begin(); i != ids.end(); ++i)
            gids.push_back(*i);
        return gids;
    } catch (const core::NotFoundError& error) {
        throw DBus::Error(notFoundError, (error.reason + " (" + error.response + ")").c_str());
    } catch (const core::Error& error) {
        throw DBus::Error(tartarusError, error.reason.c_str());
    } catch (const Ice::Exception& error) {
        setReaderReInit();
        throw DBus::Error(iceError, error.ice_name().c_str());
    } catch (const std::runtime_error& error) {
        setReaderReInit();
        throw DBus::Error(internalError, error.what());
    }
}
