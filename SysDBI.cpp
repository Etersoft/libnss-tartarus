
#include <SysDBI.h>
#include <TartarusSysDB.h>
#include <stdexcept>

using namespace Tartarus;

::Tartarus::iface::SysDB::UserRecord
Tartarus::iface::SysDB::UserReaderI::getById(::Ice::Long uid,
                                              const Ice::Current& current)
{
    return getUserReader(current)->getById(uid);
}

::Tartarus::iface::SysDB::UserRecord
Tartarus::iface::SysDB::UserReaderI::getByName(const ::std::string& name,
                                                const Ice::Current& current)
{
    return getUserReader(current)->getByName(name);
}

::Tartarus::iface::SysDB::Ids
Tartarus::iface::SysDB::UserReaderI::getGroupsById(::Ice::Long uid,
                                                    const Ice::Current& current)
{
    return getUserReader(current)->getGroupsById(uid);
}

::Tartarus::iface::SysDB::Ids
Tartarus::iface::SysDB::UserReaderI::getGroupsByName(const ::std::string& name,
                                                      const Ice::Current& current)
{
    return getUserReader(current)->getGroupsByName(name);
}

::Tartarus::iface::SysDB::Users
Tartarus::iface::SysDB::UserReaderI::getUsers(const ::Tartarus::iface::SysDB::Ids& userIds,
                                               const Ice::Current& current)
{
    return getUserReader(current)->getUsers(userIds);
}

::Tartarus::iface::SysDB::Users
Tartarus::iface::SysDB::UserReaderI::search(const ::std::string& factor,
                                             ::Ice::Long maximum,
                                             const Ice::Current& current)
{
/*    SysDB::Users users;
    try {
        const SysDB::UserReaderPrx &prx = getUserReader(current);
        //users = getUserReader(current)->search(factor, maximum);
    } catch (const Ice::Exception& error) {
        current.adapter->getCommunicator()->getLogger()->error(error.ice_name());
    } catch (std::bad_alloc error) {
        current.adapter->getCommunicator()->getLogger()->error(error.what());
    } catch (std::runtime_error error) {
        current.adapter->getCommunicator()->getLogger()->error(error.what());
    } catch (std::logic_error error) {
        current.adapter->getCommunicator()->getLogger()->error(error.what());
    } catch (const char* msg) {
        current.adapter->getCommunicator()->getLogger()->error(msg);
    } catch (...) {
        current.adapter->getCommunicator()->getLogger()->error("wrong user www");
    }*/
//    return SysDB::Users();
    return getUserReader(current)->search(factor, maximum);
//    return users;
}

::Tartarus::iface::SysDB::GroupRecord
Tartarus::iface::SysDB::GroupReaderI::getById(::Ice::Long gid,
                                               const Ice::Current& current)
{
    return getGroupReader(current)->getById(gid);
}

::Tartarus::iface::SysDB::GroupRecord
Tartarus::iface::SysDB::GroupReaderI::getByName(const ::std::string& name,
                                                 const Ice::Current& current)
{
    return getGroupReader(current)->getByName(name);
}

::Tartarus::iface::SysDB::Groups
Tartarus::iface::SysDB::GroupReaderI::getGroups(const ::Tartarus::iface::SysDB::Ids& groupIds,
                                                 const Ice::Current& current)
{
    return getGroupReader(current)->getGroups(groupIds);
}

::Tartarus::iface::SysDB::Ids
Tartarus::iface::SysDB::GroupReaderI::getUsers(::Ice::Long gid,
                                                const Ice::Current& current)
{
    return getGroupReader(current)->getUsers(gid);
}

::Tartarus::iface::SysDB::Groups
Tartarus::iface::SysDB::GroupReaderI::search(const ::std::string& factor,
                                              ::Ice::Long maximum,
                                              const Ice::Current& current)
{
    SysDB::Groups groups;
    try {
        groups = getGroupReader(current)->search(factor, maximum);
    } catch (...) {
        current.adapter->getCommunicator()->getLogger()->error("wrong www");
    }
    return groups;
}
