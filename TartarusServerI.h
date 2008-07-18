#ifndef Tartarus_RPC_ServerI_h
#define Tartarus_RPC_ServerI_h

#include <TartarusRPC.h>
#include <TartarusRPCTypes.h>

namespace Tartarus {

class UserReader: public RPC::Object
{
public:
        json_spirit::Value call(const std::string & method, const json_spirit::Array & params);
        virtual UserRecord getUser(uid_t uid) = 0;
        virtual UserRecord getUser(const std::string &name) = 0;
};

class UserReaderI: public UserReader
{
        UserRecord getUser(uid_t uid);
        UserRecord getUser(const std::string &name);
};

class GroupReader: public RPC::Object
{
public:
        json_spirit::Value call(const std::string & method, const json_spirit::Array & params);
        virtual GroupRecord getGroup(gid_t gid) = 0;
        virtual GroupRecord getGroup(const std::string &groupname) = 0;
        virtual std::vector<std::string> getUsers(gid_t gid) = 0;
        virtual std::vector<gid_t> getUserGroups(const std::string &username) = 0;
};

class GroupReaderI: public GroupReader
{
        GroupRecord getGroup(gid_t gid);
        GroupRecord getGroup(const std::string &groupname);
        std::vector<std::string> getUsers(gid_t gid);
        std::vector<gid_t> getUserGroups(const std::string &username);
};

}

#endif
