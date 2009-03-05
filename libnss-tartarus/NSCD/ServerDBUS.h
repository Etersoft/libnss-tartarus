#ifndef Tartarus_ServerDBUS_h
#define Tartarus_ServerDBUS_h

#include <dbus-c++/dbus.h>
#include "NSCDAdaptor.h"

namespace Tartarus {

class ServerDBUS
: public ru::tartarus::DBus::TNSCD_adaptor,
//  public DBus::IntrospectableAdaptor,
  public DBus::ObjectAdaptor
{
public:
    ServerDBUS(DBus::Connection& connection, const char* server_path):
        DBus::ObjectAdaptor(connection, server_path) {}

    void getUserById(
        const uint32_t& userid, 
        uint32_t& uid,
        uint32_t& gid,
        std::string& name,
        std::string& gecos,
        std::string& home,
        std::string& shell,
        std::string& passwd);
    void getUserByName(
        const std::string& username,
        uint32_t& uid,
        uint32_t& gid,
        std::string& name,
        std::string& gecos,
        std::string& home,
        std::string& shell,
        std::string& passwd);
    void getGroupById(
        const uint32_t& groupid,
        uint32_t& gid,
        std::string& name,
        std::string& passwd,
        uint32_t& users_size,
        std::vector< std::string >& users);
    void getGroupByName(
        const std::string& groupname,
        uint32_t& gid,
        std::string& name,
        std::string& passwd,
        uint32_t& users_size,
        std::vector< std::string >& users);
    std::vector< uint32_t > getUserGroups(const std::string& username);
};

}

#endif
