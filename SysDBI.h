#ifndef __SysDBI_h__
#define __SysDBI_h__

#include <SysDB.h>

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReaderI : virtual public UserReader
{
public:

    virtual ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long,
                                                         const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string&,
                                                           const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::Ids getGroupsById(::Ice::Long,
                                                        const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::Ids getGroupsByName(const ::std::string&,
                                                          const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::Users getUsers(const ::Tartarus::iface::SysDB::Ids&,
                                                     const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::Users search(const ::std::string&,
                                                   ::Ice::Long,
                                                   const Ice::Current&);
};

class GroupReaderI : virtual public GroupReader
{
public:

    virtual ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long,
                                                          const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string&,
                                                            const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::Groups getGroups(const ::Tartarus::iface::SysDB::Ids&,
                                                       const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::Ids getUsers(::Ice::Long,
                                                   const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::Groups search(const ::std::string&,
                                                    ::Ice::Long,
                                                    const Ice::Current&);
};

}

}

}

#endif
