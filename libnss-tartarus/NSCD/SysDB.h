// **********************************************************************
//
// Copyright (c) 2003-2007 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

// Ice version 3.2.1
// Generated from file `SysDB.ice'

#ifndef __SysDB_h__
#define __SysDB_h__

#include <Ice/LocalObjectF.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/Proxy.h>
#include <Ice/Object.h>
#include <Ice/Outgoing.h>
#include <Ice/Incoming.h>
#include <Ice/Direct.h>
#include <Ice/UserExceptionFactory.h>
#include <Ice/FactoryTable.h>
#include <Ice/StreamF.h>
#include <Ice/UndefSysMacros.h>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 302
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 > 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 1
#       error Ice patch level mismatch!
#   endif
#endif

namespace IceProxy
{

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReader;
bool operator==(const UserReader&, const UserReader&);
bool operator!=(const UserReader&, const UserReader&);
bool operator<(const UserReader&, const UserReader&);
bool operator<=(const UserReader&, const UserReader&);
bool operator>(const UserReader&, const UserReader&);
bool operator>=(const UserReader&, const UserReader&);

class UserManager;
bool operator==(const UserManager&, const UserManager&);
bool operator!=(const UserManager&, const UserManager&);
bool operator<(const UserManager&, const UserManager&);
bool operator<=(const UserManager&, const UserManager&);
bool operator>(const UserManager&, const UserManager&);
bool operator>=(const UserManager&, const UserManager&);

class GroupReader;
bool operator==(const GroupReader&, const GroupReader&);
bool operator!=(const GroupReader&, const GroupReader&);
bool operator<(const GroupReader&, const GroupReader&);
bool operator<=(const GroupReader&, const GroupReader&);
bool operator>(const GroupReader&, const GroupReader&);
bool operator>=(const GroupReader&, const GroupReader&);

class GroupManager;
bool operator==(const GroupManager&, const GroupManager&);
bool operator!=(const GroupManager&, const GroupManager&);
bool operator<(const GroupManager&, const GroupManager&);
bool operator<=(const GroupManager&, const GroupManager&);
bool operator>(const GroupManager&, const GroupManager&);
bool operator>=(const GroupManager&, const GroupManager&);

}

}

}

}

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReader;
bool operator==(const UserReader&, const UserReader&);
bool operator!=(const UserReader&, const UserReader&);
bool operator<(const UserReader&, const UserReader&);
bool operator<=(const UserReader&, const UserReader&);
bool operator>(const UserReader&, const UserReader&);
bool operator>=(const UserReader&, const UserReader&);

class UserManager;
bool operator==(const UserManager&, const UserManager&);
bool operator!=(const UserManager&, const UserManager&);
bool operator<(const UserManager&, const UserManager&);
bool operator<=(const UserManager&, const UserManager&);
bool operator>(const UserManager&, const UserManager&);
bool operator>=(const UserManager&, const UserManager&);

class GroupReader;
bool operator==(const GroupReader&, const GroupReader&);
bool operator!=(const GroupReader&, const GroupReader&);
bool operator<(const GroupReader&, const GroupReader&);
bool operator<=(const GroupReader&, const GroupReader&);
bool operator>(const GroupReader&, const GroupReader&);
bool operator>=(const GroupReader&, const GroupReader&);

class GroupManager;
bool operator==(const GroupManager&, const GroupManager&);
bool operator!=(const GroupManager&, const GroupManager&);
bool operator<(const GroupManager&, const GroupManager&);
bool operator<=(const GroupManager&, const GroupManager&);
bool operator>(const GroupManager&, const GroupManager&);
bool operator>=(const GroupManager&, const GroupManager&);

}

}

}

namespace IceInternal
{

void incRef(::Tartarus::iface::SysDB::UserReader*);
void decRef(::Tartarus::iface::SysDB::UserReader*);

void incRef(::IceProxy::Tartarus::iface::SysDB::UserReader*);
void decRef(::IceProxy::Tartarus::iface::SysDB::UserReader*);

void incRef(::Tartarus::iface::SysDB::UserManager*);
void decRef(::Tartarus::iface::SysDB::UserManager*);

void incRef(::IceProxy::Tartarus::iface::SysDB::UserManager*);
void decRef(::IceProxy::Tartarus::iface::SysDB::UserManager*);

void incRef(::Tartarus::iface::SysDB::GroupReader*);
void decRef(::Tartarus::iface::SysDB::GroupReader*);

void incRef(::IceProxy::Tartarus::iface::SysDB::GroupReader*);
void decRef(::IceProxy::Tartarus::iface::SysDB::GroupReader*);

void incRef(::Tartarus::iface::SysDB::GroupManager*);
void decRef(::Tartarus::iface::SysDB::GroupManager*);

void incRef(::IceProxy::Tartarus::iface::SysDB::GroupManager*);
void decRef(::IceProxy::Tartarus::iface::SysDB::GroupManager*);

}

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

typedef ::IceInternal::Handle< ::Tartarus::iface::SysDB::UserReader> UserReaderPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Tartarus::iface::SysDB::UserReader> UserReaderPrx;

void __write(::IceInternal::BasicStream*, const UserReaderPrx&);
void __read(::IceInternal::BasicStream*, UserReaderPrx&);
void __write(::IceInternal::BasicStream*, const UserReaderPtr&);
void __patch__UserReaderPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const UserReaderPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const UserReaderPtr&);
void __decRefUnsafe(const UserReaderPtr&);
void __clearHandleUnsafe(UserReaderPtr&);

typedef ::IceInternal::Handle< ::Tartarus::iface::SysDB::UserManager> UserManagerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Tartarus::iface::SysDB::UserManager> UserManagerPrx;

void __write(::IceInternal::BasicStream*, const UserManagerPrx&);
void __read(::IceInternal::BasicStream*, UserManagerPrx&);
void __write(::IceInternal::BasicStream*, const UserManagerPtr&);
void __patch__UserManagerPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const UserManagerPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const UserManagerPtr&);
void __decRefUnsafe(const UserManagerPtr&);
void __clearHandleUnsafe(UserManagerPtr&);

typedef ::IceInternal::Handle< ::Tartarus::iface::SysDB::GroupReader> GroupReaderPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Tartarus::iface::SysDB::GroupReader> GroupReaderPrx;

void __write(::IceInternal::BasicStream*, const GroupReaderPrx&);
void __read(::IceInternal::BasicStream*, GroupReaderPrx&);
void __write(::IceInternal::BasicStream*, const GroupReaderPtr&);
void __patch__GroupReaderPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const GroupReaderPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const GroupReaderPtr&);
void __decRefUnsafe(const GroupReaderPtr&);
void __clearHandleUnsafe(GroupReaderPtr&);

typedef ::IceInternal::Handle< ::Tartarus::iface::SysDB::GroupManager> GroupManagerPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Tartarus::iface::SysDB::GroupManager> GroupManagerPrx;

void __write(::IceInternal::BasicStream*, const GroupManagerPrx&);
void __read(::IceInternal::BasicStream*, GroupManagerPrx&);
void __write(::IceInternal::BasicStream*, const GroupManagerPtr&);
void __patch__GroupManagerPtr(void*, ::Ice::ObjectPtr&);

void __addObject(const GroupManagerPtr&, ::IceInternal::GCCountMap&);
bool __usesClasses(const GroupManagerPtr&);
void __decRefUnsafe(const GroupManagerPtr&);
void __clearHandleUnsafe(GroupManagerPtr&);

}

}

}

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

struct UserRecord
{
    ::Ice::Long uid;
    ::Ice::Long gid;
    ::std::string name;
    ::std::string fullName;
    ::std::string shell;

    bool operator==(const UserRecord&) const;
    bool operator!=(const UserRecord&) const;
    bool operator<(const UserRecord&) const;
    bool operator<=(const UserRecord& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const UserRecord& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const UserRecord& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

struct GroupRecord
{
    ::Ice::Long gid;
    ::std::string name;
    ::std::string description;

    bool operator==(const GroupRecord&) const;
    bool operator!=(const GroupRecord&) const;
    bool operator<(const GroupRecord&) const;
    bool operator<=(const GroupRecord& __rhs) const
    {
        return operator<(__rhs) || operator==(__rhs);
    }
    bool operator>(const GroupRecord& __rhs) const
    {
        return !operator<(__rhs) && !operator==(__rhs);
    }
    bool operator>=(const GroupRecord& __rhs) const
    {
        return !operator<(__rhs);
    }

    void __write(::IceInternal::BasicStream*) const;
    void __read(::IceInternal::BasicStream*);
};

class Error : public ::Ice::UserException
{
public:

    Error() {}
    explicit Error(const ::std::string&);
    virtual ~Error() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string reason;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

static Error __Error_init;

class ConfigError : public ::Tartarus::iface::SysDB::Error
{
public:

    ConfigError() {}
    ConfigError(const ::std::string&, const ::std::string&);
    virtual ~ConfigError() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string property;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class NotFound : public ::Tartarus::iface::SysDB::Error
{
public:

    NotFound() {}
    explicit NotFound(const ::std::string&);
    virtual ~NotFound() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class UserNotFound : public ::Tartarus::iface::SysDB::NotFound
{
public:

    UserNotFound() {}
    UserNotFound(const ::std::string&, ::Ice::Long);
    virtual ~UserNotFound() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::Ice::Long id;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class GroupNotFound : public ::Tartarus::iface::SysDB::NotFound
{
public:

    GroupNotFound() {}
    GroupNotFound(const ::std::string&, ::Ice::Long);
    virtual ~GroupNotFound() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::Ice::Long id;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class PermissionDenied : public ::Tartarus::iface::SysDB::Error
{
public:

    PermissionDenied() {}
    explicit PermissionDenied(const ::std::string&);
    virtual ~PermissionDenied() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class AlreadyExists : public ::Tartarus::iface::SysDB::Error
{
public:

    AlreadyExists() {}
    explicit AlreadyExists(const ::std::string&);
    virtual ~AlreadyExists() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class UserAlreadyExists : public ::Tartarus::iface::SysDB::AlreadyExists
{
public:

    UserAlreadyExists() {}
    UserAlreadyExists(const ::std::string&, ::Ice::Long);
    virtual ~UserAlreadyExists() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::Ice::Long id;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class GroupAlreadyExists : public ::Tartarus::iface::SysDB::AlreadyExists
{
public:

    GroupAlreadyExists() {}
    GroupAlreadyExists(const ::std::string&, ::Ice::Long);
    virtual ~GroupAlreadyExists() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::Ice::Long id;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

class DBError : public ::Tartarus::iface::SysDB::Error
{
public:

    DBError() {}
    DBError(const ::std::string&, const ::std::string&);
    virtual ~DBError() throw();

    virtual ::std::string ice_name() const;
    virtual ::Ice::Exception* ice_clone() const;
    virtual void ice_throw() const;

    static const ::IceInternal::UserExceptionFactoryPtr& ice_factory();

    ::std::string message;

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);

    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

typedef ::std::vector< ::Tartarus::iface::SysDB::UserRecord> UserSeq;

class __U__UserSeq { };
void __write(::IceInternal::BasicStream*, const ::Tartarus::iface::SysDB::UserRecord*, const ::Tartarus::iface::SysDB::UserRecord*, __U__UserSeq);
void __read(::IceInternal::BasicStream*, UserSeq&, __U__UserSeq);

typedef ::std::vector< ::Tartarus::iface::SysDB::GroupRecord> GroupSeq;

class __U__GroupSeq { };
void __write(::IceInternal::BasicStream*, const ::Tartarus::iface::SysDB::GroupRecord*, const ::Tartarus::iface::SysDB::GroupRecord*, __U__GroupSeq);
void __read(::IceInternal::BasicStream*, GroupSeq&, __U__GroupSeq);

typedef ::std::vector< ::Ice::Long> IdSeq;

class __U__IdSeq { };

}

}

}

namespace IceProxy
{

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReader : virtual public ::IceProxy::Ice::Object
{
public:

    ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long uid)
    {
        return getById(uid, 0);
    }
    ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long uid, const ::Ice::Context& __ctx)
    {
        return getById(uid, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string& name)
    {
        return getByName(name, 0);
    }
    ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return getByName(name, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq& userIds)
    {
        return getUsers(userIds, 0);
    }
    ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context& __ctx)
    {
        return getUsers(userIds, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::UserSeq search(const ::std::string& factor, ::Ice::Long limit)
    {
        return search(factor, limit, 0);
    }
    ::Tartarus::iface::SysDB::UserSeq search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context& __ctx)
    {
        return search(factor, limit, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::UserSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*);
    
public:

    ::Ice::Long count()
    {
        return count(0);
    }
    ::Ice::Long count(const ::Ice::Context& __ctx)
    {
        return count(&__ctx);
    }
    
private:

    ::Ice::Long count(const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long limit, ::Ice::Long offset)
    {
        return get(limit, offset, 0);
    }
    ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context& __ctx)
    {
        return get(limit, offset, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class UserManager : virtual public ::IceProxy::Tartarus::iface::SysDB::UserReader
{
public:

    void modify(const ::Tartarus::iface::SysDB::UserRecord& user)
    {
        modify(user, 0);
    }
    void modify(const ::Tartarus::iface::SysDB::UserRecord& user, const ::Ice::Context& __ctx)
    {
        modify(user, &__ctx);
    }
    
private:

    void modify(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*);
    
public:

    ::Ice::Long create(const ::Tartarus::iface::SysDB::UserRecord& newUser)
    {
        return create(newUser, 0);
    }
    ::Ice::Long create(const ::Tartarus::iface::SysDB::UserRecord& newUser, const ::Ice::Context& __ctx)
    {
        return create(newUser, &__ctx);
    }
    
private:

    ::Ice::Long create(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*);
    
public:

    void _cpp_delete(::Ice::Long id)
    {
        _cpp_delete(id, 0);
    }
    void _cpp_delete(::Ice::Long id, const ::Ice::Context& __ctx)
    {
        _cpp_delete(id, &__ctx);
    }
    
private:

    void _cpp_delete(::Ice::Long, const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class GroupReader : virtual public ::IceProxy::Ice::Object
{
public:

    ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long gid)
    {
        return getById(gid, 0);
    }
    ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long gid, const ::Ice::Context& __ctx)
    {
        return getById(gid, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string& name)
    {
        return getByName(name, 0);
    }
    ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return getByName(name, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long uid)
    {
        return getGroupsForUserId(uid, 0);
    }
    ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long uid, const ::Ice::Context& __ctx)
    {
        return getGroupsForUserId(uid, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string& name)
    {
        return getGroupsForUserName(name, 0);
    }
    ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string& name, const ::Ice::Context& __ctx)
    {
        return getGroupsForUserName(name, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string&, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq& groupIds)
    {
        return getGroups(groupIds, 0);
    }
    ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq& groupIds, const ::Ice::Context& __ctx)
    {
        return getGroups(groupIds, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long gid)
    {
        return getUsers(gid, 0);
    }
    ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long gid, const ::Ice::Context& __ctx)
    {
        return getUsers(gid, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long, const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string& factor, ::Ice::Long limit)
    {
        return search(factor, limit, 0);
    }
    ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context& __ctx)
    {
        return search(factor, limit, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*);
    
public:

    ::Ice::Long count()
    {
        return count(0);
    }
    ::Ice::Long count(const ::Ice::Context& __ctx)
    {
        return count(&__ctx);
    }
    
private:

    ::Ice::Long count(const ::Ice::Context*);
    
public:

    ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long limit, ::Ice::Long offset)
    {
        return get(limit, offset, 0);
    }
    ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context& __ctx)
    {
        return get(limit, offset, &__ctx);
    }
    
private:

    ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

class GroupManager : virtual public ::IceProxy::Tartarus::iface::SysDB::GroupReader
{
public:

    void setUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds)
    {
        setUsers(gid, userIds, 0);
    }
    void setUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context& __ctx)
    {
        setUsers(gid, userIds, &__ctx);
    }
    
private:

    void setUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
    
public:

    void addUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds)
    {
        addUsers(gid, userIds, 0);
    }
    void addUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context& __ctx)
    {
        addUsers(gid, userIds, &__ctx);
    }
    
private:

    void addUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
    
public:

    void delUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds)
    {
        delUsers(gid, userIds, 0);
    }
    void delUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context& __ctx)
    {
        delUsers(gid, userIds, &__ctx);
    }
    
private:

    void delUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
    
public:

    void modify(const ::Tartarus::iface::SysDB::GroupRecord& group)
    {
        modify(group, 0);
    }
    void modify(const ::Tartarus::iface::SysDB::GroupRecord& group, const ::Ice::Context& __ctx)
    {
        modify(group, &__ctx);
    }
    
private:

    void modify(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*);
    
public:

    ::Ice::Long create(const ::Tartarus::iface::SysDB::GroupRecord& newGroup)
    {
        return create(newGroup, 0);
    }
    ::Ice::Long create(const ::Tartarus::iface::SysDB::GroupRecord& newGroup, const ::Ice::Context& __ctx)
    {
        return create(newGroup, &__ctx);
    }
    
private:

    ::Ice::Long create(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*);
    
public:

    void _cpp_delete(::Ice::Long id)
    {
        _cpp_delete(id, 0);
    }
    void _cpp_delete(::Ice::Long id, const ::Ice::Context& __ctx)
    {
        _cpp_delete(id, &__ctx);
    }
    
private:

    void _cpp_delete(::Ice::Long, const ::Ice::Context*);
    
public:

    void addUserToGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups)
    {
        addUserToGroups(uid, groups, 0);
    }
    void addUserToGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context& __ctx)
    {
        addUserToGroups(uid, groups, &__ctx);
    }
    
private:

    void addUserToGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
    
public:

    void delUserFromGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups)
    {
        delUserFromGroups(uid, groups, 0);
    }
    void delUserFromGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context& __ctx)
    {
        delUserFromGroups(uid, groups, &__ctx);
    }
    
private:

    void delUserFromGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
    
public:
    
    static const ::std::string& ice_staticId();

private: 

    virtual ::IceInternal::Handle< ::IceDelegateM::Ice::Object> __createDelegateM();
    virtual ::IceInternal::Handle< ::IceDelegateD::Ice::Object> __createDelegateD();
};

}

}

}

}

namespace IceDelegate
{

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReader : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::UserSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*) = 0;

    virtual ::Ice::Long count(const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*) = 0;
};

class UserManager : virtual public ::IceDelegate::Tartarus::iface::SysDB::UserReader
{
public:

    virtual void modify(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*) = 0;

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*) = 0;

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Context*) = 0;
};

class GroupReader : virtual public ::IceDelegate::Ice::Object
{
public:

    virtual ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string&, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long, const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*) = 0;

    virtual ::Ice::Long count(const ::Ice::Context*) = 0;

    virtual ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*) = 0;
};

class GroupManager : virtual public ::IceDelegate::Tartarus::iface::SysDB::GroupReader
{
public:

    virtual void setUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*) = 0;

    virtual void addUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*) = 0;

    virtual void delUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*) = 0;

    virtual void modify(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*) = 0;

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*) = 0;

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Context*) = 0;

    virtual void addUserToGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*) = 0;

    virtual void delUserFromGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*) = 0;
};

}

}

}

}

namespace IceDelegateM
{

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReader : virtual public ::IceDelegate::Tartarus::iface::SysDB::UserReader,
                   virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*);

    virtual ::Ice::Long count(const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*);
};

class UserManager : virtual public ::IceDelegate::Tartarus::iface::SysDB::UserManager,
                    virtual public ::IceDelegateM::Tartarus::iface::SysDB::UserReader
{
public:

    virtual void modify(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*);

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*);

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Context*);
};

class GroupReader : virtual public ::IceDelegate::Tartarus::iface::SysDB::GroupReader,
                    virtual public ::IceDelegateM::Ice::Object
{
public:

    virtual ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*);

    virtual ::Ice::Long count(const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*);
};

class GroupManager : virtual public ::IceDelegate::Tartarus::iface::SysDB::GroupManager,
                     virtual public ::IceDelegateM::Tartarus::iface::SysDB::GroupReader
{
public:

    virtual void setUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void addUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void delUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void modify(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*);

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*);

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Context*);

    virtual void addUserToGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void delUserFromGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
};

}

}

}

}

namespace IceDelegateD
{

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReader : virtual public ::IceDelegate::Tartarus::iface::SysDB::UserReader,
                   virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*);

    virtual ::Ice::Long count(const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*);
};

class UserManager : virtual public ::IceDelegate::Tartarus::iface::SysDB::UserManager,
                    virtual public ::IceDelegateD::Tartarus::iface::SysDB::UserReader
{
public:

    virtual void modify(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*);

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Context*);

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Context*);
};

class GroupReader : virtual public ::IceDelegate::Tartarus::iface::SysDB::GroupReader,
                    virtual public ::IceDelegateD::Ice::Object
{
public:

    virtual ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long, const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Context*);

    virtual ::Ice::Long count(const ::Ice::Context*);

    virtual ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Context*);
};

class GroupManager : virtual public ::IceDelegate::Tartarus::iface::SysDB::GroupManager,
                     virtual public ::IceDelegateD::Tartarus::iface::SysDB::GroupReader
{
public:

    virtual void setUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void addUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void delUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void modify(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*);

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Context*);

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Context*);

    virtual void addUserToGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);

    virtual void delUserFromGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Context*);
};

}

}

}

}

namespace Tartarus
{

namespace iface
{

namespace SysDB
{

class UserReader : virtual public ::Ice::Object
{
public:

    typedef UserReaderPrx ProxyType;
    typedef UserReaderPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Tartarus::iface::SysDB::UserRecord getById(::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getById(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserRecord getByName(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getByName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserSeq getUsers(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___search(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Long count(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___count(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::UserSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___get(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__UserReaderPtr(void*, ::Ice::ObjectPtr&);

class UserManager : virtual public ::Tartarus::iface::SysDB::UserReader
{
public:

    typedef UserManagerPrx ProxyType;
    typedef UserManagerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void modify(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___modify(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::UserRecord&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___create(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___delete(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__UserManagerPtr(void*, ::Ice::ObjectPtr&);

class GroupReader : virtual public ::Ice::Object
{
public:

    typedef GroupReaderPrx ProxyType;
    typedef GroupReaderPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual ::Tartarus::iface::SysDB::GroupRecord getById(::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getById(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupRecord getByName(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getByName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserId(::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getGroupsForUserId(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::IdSeq getGroupsForUserName(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getGroupsForUserName(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupSeq getGroups(const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getGroups(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::IdSeq getUsers(::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___getUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupSeq search(const ::std::string&, ::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___search(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Long count(const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___count(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Tartarus::iface::SysDB::GroupSeq get(::Ice::Long, ::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___get(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__GroupReaderPtr(void*, ::Ice::ObjectPtr&);

class GroupManager : virtual public ::Tartarus::iface::SysDB::GroupReader
{
public:

    typedef GroupManagerPrx ProxyType;
    typedef GroupManagerPtr PointerType;
    
    virtual ::Ice::ObjectPtr ice_clone() const;

    virtual bool ice_isA(const ::std::string&, const ::Ice::Current& = ::Ice::Current()) const;
    virtual ::std::vector< ::std::string> ice_ids(const ::Ice::Current& = ::Ice::Current()) const;
    virtual const ::std::string& ice_id(const ::Ice::Current& = ::Ice::Current()) const;
    static const ::std::string& ice_staticId();

    virtual void setUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___setUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void delUsers(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___delUsers(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void modify(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___modify(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::Ice::Long create(const ::Tartarus::iface::SysDB::GroupRecord&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___create(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void _cpp_delete(::Ice::Long, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___delete(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void addUserToGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___addUserToGroups(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void delUserFromGroups(::Ice::Long, const ::Tartarus::iface::SysDB::IdSeq&, const ::Ice::Current& = ::Ice::Current()) = 0;
    ::IceInternal::DispatchStatus ___delUserFromGroups(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual ::IceInternal::DispatchStatus __dispatch(::IceInternal::Incoming&, const ::Ice::Current&);

    virtual void __write(::IceInternal::BasicStream*) const;
    virtual void __read(::IceInternal::BasicStream*, bool);
    virtual void __write(const ::Ice::OutputStreamPtr&) const;
    virtual void __read(const ::Ice::InputStreamPtr&, bool);
};

void __patch__GroupManagerPtr(void*, ::Ice::ObjectPtr&);

}

}

}

#endif
