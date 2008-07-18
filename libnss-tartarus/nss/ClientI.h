#ifndef __Tartarus_RPC_ClientI_h__
#define __Tartarus_RPC_ClientI_h__

#include <RPC/RPC.h>
#include <NSCD/RPCTypes.h>

namespace Tartarus
{

class UserReaderPrx: public RPC::ObjectPrx
{
public:
        UserReaderPrx(const std::string & name, RPC::Connection & connection):
            ObjectPrx(name, connection) {}
        UserRecord getUser(uid_t uid);
        UserRecord getUser(const std::string &username);
};

class GroupReaderPrx: public RPC::ObjectPrx
{
public:
        GroupReaderPrx(const std::string & name, RPC::Connection & connection):
            ObjectPrx(name, connection) {}
        GroupRecord getGroup(gid_t gid);
        GroupRecord getGroup(const std::string &groupname);

        std::vector<std::string> getUsers(gid_t gid);
        std::vector<gid_t> getUserGroups(const std::string &username);
};

}

#endif
