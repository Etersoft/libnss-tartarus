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

    virtual ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long,
                                                  ::Ice::Long,
                                                  const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long,
                                                         const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string&,
                                                           const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq&,
                                                       const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserSeq search(const ::std::string&,
                                                     ::Ice::Long,
                                                     const Ice::Current&);
};

class GroupReaderI : virtual public GroupReader
{
public:

    virtual ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long,
                                                   ::Ice::Long,
                                                   const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long,
                                                          const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string&,
                                                            const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long,
                                                        const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string&,
                                                          const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq&,
                                                         const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long,
                                                   const Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string&,
                                                      ::Ice::Long,
                                                      const Ice::Current&);
};

}

}

}

#endif
