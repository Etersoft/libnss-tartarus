#ifndef Tartarus_ServerDBUS_h
#define Tartarus_ServerDBUS_h

#include <dbus-c++/dbus.h>
#include "NSCDAdaptor.h"

namespace Tartarus {

class ServerDBUS
: public ru::tartarus::DBus::TNSCD,
//  public DBus::IntrospectableAdaptor,
  public DBus::ObjectAdaptor
{
public:
    ServerDBUS(DBus::Connection& connection, const char* server_path):
        DBus::ObjectAdaptor(connection, server_path) {}

    void getUserById(
        const ::DBus::UInt32& userid, 
        ::DBus::UInt32& uid,
        ::DBus::UInt32& gid,
        ::DBus::String& name,
        ::DBus::String& gecos,
        ::DBus::String& home,
        ::DBus::String& shell,
        ::DBus::String& passwd);
    void getUserByName(
        const ::DBus::String& username,
        ::DBus::UInt32& uid,
        ::DBus::UInt32& gid,
        ::DBus::String& name,
        ::DBus::String& gecos,
        ::DBus::String& home,
        ::DBus::String& shell,
        ::DBus::String& passwd);
    void getGroupById(
        const ::DBus::UInt32& groupid,
        ::DBus::UInt32& gid,
        ::DBus::String& name,
        ::DBus::String& passwd,
        std::vector< ::DBus::String >& users);
    void getGroupByName(
        const ::DBus::String& groupname,
        ::DBus::UInt32& gid,
        ::DBus::String& name,
        ::DBus::String& passwd,
        std::vector< ::DBus::String >& users);
    std::vector< ::DBus::UInt32 > getUserGroups(const ::DBus::String& username);
};

}

#endif
