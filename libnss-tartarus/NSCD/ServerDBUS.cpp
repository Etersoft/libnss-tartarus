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
    ::DBus::UInt32& uid,
    ::DBus::UInt32& gid,
    ::DBus::String& name,
    ::DBus::String& gecos,
    ::DBus::String& home,
    ::DBus::String& shell,
    ::DBus::String& passwd)
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
    typedef std::vector< ::DBus::String > UserNames;
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
    ::DBus::UInt32& gid,
    ::DBus::String& name,
    ::DBus::String& passwd,
    std::vector< ::DBus::String >& users,
    const SysDB::UserSeq user_list)
{
    UserNamesInserter inserter(users);

    gid    = group.gid;
    name   = group.name;
    passwd = "x";

    users.reserve(user_list.size());
    for_each(user_list.begin(), user_list.end(), inserter);
}


void ServerDBUS::getUserById(
    const ::DBus::UInt32& userid, 
    ::DBus::UInt32& uid,
    ::DBus::UInt32& gid,
    ::DBus::String& name,
    ::DBus::String& gecos,
    ::DBus::String& home,
    ::DBus::String& shell,
    ::DBus::String& passwd)
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
    const ::DBus::String& username,
    ::DBus::UInt32& uid,
    ::DBus::UInt32& gid,
    ::DBus::String& name,
    ::DBus::String& gecos,
    ::DBus::String& home,
    ::DBus::String& shell,
    ::DBus::String& passwd)
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
    const ::DBus::UInt32& groupid,
    ::DBus::UInt32& gid,
    ::DBus::String& name,
    ::DBus::String& passwd,
    std::vector< ::DBus::String >& users)
{
    try {
        SysDB::GroupRecord group = getGroupReader()->getById(groupid);
        const SysDB::IdSeq ids = getGroupReader()->getUsers(groupid);
        const SysDB::UserSeq user_list = getUserReader()->getUsers(ids);
        fillGroup(group, gid, name, passwd, users, user_list);
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
    const ::DBus::String& groupname,
    ::DBus::UInt32& gid,
    ::DBus::String& name,
    ::DBus::String& passwd,
    std::vector< ::DBus::String >& users)
{
    try {
        SysDB::GroupRecord group = getGroupReader()->getByName(groupname);
        const SysDB::IdSeq ids = getGroupReader()->getUsers(group.gid);
        const SysDB::UserSeq user_list = getUserReader()->getUsers(ids);
        fillGroup(group, gid, name, passwd, users, user_list);
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

std::vector< ::DBus::UInt32 > ServerDBUS::getUserGroups(const ::DBus::String& username)
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
