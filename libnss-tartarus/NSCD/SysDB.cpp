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

#include <SysDB.h>
#include <Ice/LocalException.h>
#include <Ice/ObjectFactory.h>
#include <Ice/BasicStream.h>
#include <Ice/Object.h>
#include <IceUtil/Iterator.h>
#include <IceUtil/ScopedArray.h>

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

static const ::std::string __Tartarus__iface__SysDB__UserReader__getById_name = "getById";

static const ::std::string __Tartarus__iface__SysDB__UserReader__getByName_name = "getByName";

static const ::std::string __Tartarus__iface__SysDB__UserReader__getUsers_name = "getUsers";

static const ::std::string __Tartarus__iface__SysDB__UserReader__search_name = "search";

static const ::std::string __Tartarus__iface__SysDB__UserReader__count_name = "count";

static const ::std::string __Tartarus__iface__SysDB__UserReader__get_name = "get";

static const ::std::string __Tartarus__iface__SysDB__UserManager__modify_name = "modify";

static const ::std::string __Tartarus__iface__SysDB__UserManager__create_name = "create";

static const ::std::string __Tartarus__iface__SysDB__UserManager__delete_name = "delete";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__getById_name = "getById";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__getByName_name = "getByName";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__getGroupsForUserId_name = "getGroupsForUserId";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__getGroupsForUserName_name = "getGroupsForUserName";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__getGroups_name = "getGroups";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__getUsers_name = "getUsers";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__search_name = "search";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__count_name = "count";

static const ::std::string __Tartarus__iface__SysDB__GroupReader__get_name = "get";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__setUsers_name = "setUsers";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__addUsers_name = "addUsers";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__delUsers_name = "delUsers";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__modify_name = "modify";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__create_name = "create";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__delete_name = "delete";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__addUserToGroups_name = "addUserToGroups";

static const ::std::string __Tartarus__iface__SysDB__GroupManager__delUserFromGroups_name = "delUserFromGroups";

void
IceInternal::incRef(::Tartarus::iface::SysDB::UserReader* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Tartarus::iface::SysDB::UserReader* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Tartarus::iface::SysDB::UserReader* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Tartarus::iface::SysDB::UserReader* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::Tartarus::iface::SysDB::UserManager* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Tartarus::iface::SysDB::UserManager* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Tartarus::iface::SysDB::UserManager* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Tartarus::iface::SysDB::UserManager* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::Tartarus::iface::SysDB::GroupReader* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Tartarus::iface::SysDB::GroupReader* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Tartarus::iface::SysDB::GroupReader* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Tartarus::iface::SysDB::GroupReader* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::Tartarus::iface::SysDB::GroupManager* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::Tartarus::iface::SysDB::GroupManager* p)
{
    p->__decRef();
}

void
IceInternal::incRef(::IceProxy::Tartarus::iface::SysDB::GroupManager* p)
{
    p->__incRef();
}

void
IceInternal::decRef(::IceProxy::Tartarus::iface::SysDB::GroupManager* p)
{
    p->__decRef();
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::UserReaderPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Tartarus::iface::SysDB::__read(::IceInternal::BasicStream* __is, ::Tartarus::iface::SysDB::UserReaderPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Tartarus::iface::SysDB::UserReader;
        v->__copyFrom(proxy);
    }
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::UserReaderPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::UserManagerPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Tartarus::iface::SysDB::__read(::IceInternal::BasicStream* __is, ::Tartarus::iface::SysDB::UserManagerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Tartarus::iface::SysDB::UserManager;
        v->__copyFrom(proxy);
    }
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::UserManagerPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::GroupReaderPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Tartarus::iface::SysDB::__read(::IceInternal::BasicStream* __is, ::Tartarus::iface::SysDB::GroupReaderPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Tartarus::iface::SysDB::GroupReader;
        v->__copyFrom(proxy);
    }
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::GroupReaderPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::GroupManagerPrx& v)
{
    __os->write(::Ice::ObjectPrx(v));
}

void
Tartarus::iface::SysDB::__read(::IceInternal::BasicStream* __is, ::Tartarus::iface::SysDB::GroupManagerPrx& v)
{
    ::Ice::ObjectPrx proxy;
    __is->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new ::IceProxy::Tartarus::iface::SysDB::GroupManager;
        v->__copyFrom(proxy);
    }
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::GroupManagerPtr& v)
{
    __os->write(::Ice::ObjectPtr(v));
}

bool
Tartarus::iface::SysDB::UserRecord::operator==(const UserRecord& __rhs) const
{
    return !operator!=(__rhs);
}

bool
Tartarus::iface::SysDB::UserRecord::operator!=(const UserRecord& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(uid != __rhs.uid)
    {
        return true;
    }
    if(gid != __rhs.gid)
    {
        return true;
    }
    if(name != __rhs.name)
    {
        return true;
    }
    if(fullName != __rhs.fullName)
    {
        return true;
    }
    if(shell != __rhs.shell)
    {
        return true;
    }
    return false;
}

bool
Tartarus::iface::SysDB::UserRecord::operator<(const UserRecord& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(uid < __rhs.uid)
    {
        return true;
    }
    else if(__rhs.uid < uid)
    {
        return false;
    }
    if(gid < __rhs.gid)
    {
        return true;
    }
    else if(__rhs.gid < gid)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(fullName < __rhs.fullName)
    {
        return true;
    }
    else if(__rhs.fullName < fullName)
    {
        return false;
    }
    if(shell < __rhs.shell)
    {
        return true;
    }
    else if(__rhs.shell < shell)
    {
        return false;
    }
    return false;
}

void
Tartarus::iface::SysDB::UserRecord::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(uid);
    __os->write(gid);
    __os->write(name);
    __os->write(fullName);
    __os->write(shell);
}

void
Tartarus::iface::SysDB::UserRecord::__read(::IceInternal::BasicStream* __is)
{
    __is->read(uid);
    __is->read(gid);
    __is->read(name);
    __is->read(fullName);
    __is->read(shell);
}

bool
Tartarus::iface::SysDB::GroupRecord::operator==(const GroupRecord& __rhs) const
{
    return !operator!=(__rhs);
}

bool
Tartarus::iface::SysDB::GroupRecord::operator!=(const GroupRecord& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(gid != __rhs.gid)
    {
        return true;
    }
    if(name != __rhs.name)
    {
        return true;
    }
    if(description != __rhs.description)
    {
        return true;
    }
    return false;
}

bool
Tartarus::iface::SysDB::GroupRecord::operator<(const GroupRecord& __rhs) const
{
    if(this == &__rhs)
    {
        return false;
    }
    if(gid < __rhs.gid)
    {
        return true;
    }
    else if(__rhs.gid < gid)
    {
        return false;
    }
    if(name < __rhs.name)
    {
        return true;
    }
    else if(__rhs.name < name)
    {
        return false;
    }
    if(description < __rhs.description)
    {
        return true;
    }
    else if(__rhs.description < description)
    {
        return false;
    }
    return false;
}

void
Tartarus::iface::SysDB::GroupRecord::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(gid);
    __os->write(name);
    __os->write(description);
}

void
Tartarus::iface::SysDB::GroupRecord::__read(::IceInternal::BasicStream* __is)
{
    __is->read(gid);
    __is->read(name);
    __is->read(description);
}

Tartarus::iface::SysDB::Error::Error(const ::std::string& __ice_reason) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    UserException(),
#else
    ::Ice::UserException(),
#endif
    reason(__ice_reason)
{
}

Tartarus::iface::SysDB::Error::~Error() throw()
{
}

static const char* __Tartarus__iface__SysDB__Error_name = "Tartarus::iface::SysDB::Error";

::std::string
Tartarus::iface::SysDB::Error::ice_name() const
{
    return __Tartarus__iface__SysDB__Error_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::Error::ice_clone() const
{
    return new Error(*this);
}

void
Tartarus::iface::SysDB::Error::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::Error::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::Error"), false);
    __os->startWriteSlice();
    __os->write(reason);
    __os->endWriteSlice();
}

void
Tartarus::iface::SysDB::Error::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(reason);
    __is->endReadSlice();
}

void
Tartarus::iface::SysDB::Error::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::Error was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::Error::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::Error was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__Error : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::Error();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__Error__Ptr = new __F__Tartarus__iface__SysDB__Error;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::Error::ice_factory()
{
    return __F__Tartarus__iface__SysDB__Error__Ptr;
}

class __F__Tartarus__iface__SysDB__Error__Init
{
public:

    __F__Tartarus__iface__SysDB__Error__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::Error", ::Tartarus::iface::SysDB::Error::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__Error__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::Error");
    }
};

static __F__Tartarus__iface__SysDB__Error__Init __F__Tartarus__iface__SysDB__Error__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__Error__initializer() {} }
#endif

Tartarus::iface::SysDB::ConfigError::ConfigError(const ::std::string& __ice_reason, const ::std::string& __ice_property) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error(__ice_reason),
#else
    ::Tartarus::iface::SysDB::Error(__ice_reason),
#endif
    property(__ice_property)
{
}

Tartarus::iface::SysDB::ConfigError::~ConfigError() throw()
{
}

static const char* __Tartarus__iface__SysDB__ConfigError_name = "Tartarus::iface::SysDB::ConfigError";

::std::string
Tartarus::iface::SysDB::ConfigError::ice_name() const
{
    return __Tartarus__iface__SysDB__ConfigError_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::ConfigError::ice_clone() const
{
    return new ConfigError(*this);
}

void
Tartarus::iface::SysDB::ConfigError::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::ConfigError::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::ConfigError"), false);
    __os->startWriteSlice();
    __os->write(property);
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__write(__os);
#else
    ::Tartarus::iface::SysDB::Error::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::ConfigError::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(property);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::Error::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::ConfigError::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::ConfigError was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::ConfigError::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::ConfigError was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__ConfigError : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::ConfigError();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__ConfigError__Ptr = new __F__Tartarus__iface__SysDB__ConfigError;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::ConfigError::ice_factory()
{
    return __F__Tartarus__iface__SysDB__ConfigError__Ptr;
}

class __F__Tartarus__iface__SysDB__ConfigError__Init
{
public:

    __F__Tartarus__iface__SysDB__ConfigError__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::ConfigError", ::Tartarus::iface::SysDB::ConfigError::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__ConfigError__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::ConfigError");
    }
};

static __F__Tartarus__iface__SysDB__ConfigError__Init __F__Tartarus__iface__SysDB__ConfigError__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__ConfigError__initializer() {} }
#endif

Tartarus::iface::SysDB::NotFound::NotFound(const ::std::string& __ice_reason) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error(__ice_reason)
#else
    ::Tartarus::iface::SysDB::Error(__ice_reason)
#endif
{
}

Tartarus::iface::SysDB::NotFound::~NotFound() throw()
{
}

static const char* __Tartarus__iface__SysDB__NotFound_name = "Tartarus::iface::SysDB::NotFound";

::std::string
Tartarus::iface::SysDB::NotFound::ice_name() const
{
    return __Tartarus__iface__SysDB__NotFound_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::NotFound::ice_clone() const
{
    return new NotFound(*this);
}

void
Tartarus::iface::SysDB::NotFound::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::NotFound::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::NotFound"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__write(__os);
#else
    ::Tartarus::iface::SysDB::Error::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::NotFound::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::Error::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::NotFound::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::NotFound was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::NotFound::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::NotFound was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__NotFound : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::NotFound();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__NotFound__Ptr = new __F__Tartarus__iface__SysDB__NotFound;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::NotFound::ice_factory()
{
    return __F__Tartarus__iface__SysDB__NotFound__Ptr;
}

class __F__Tartarus__iface__SysDB__NotFound__Init
{
public:

    __F__Tartarus__iface__SysDB__NotFound__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::NotFound", ::Tartarus::iface::SysDB::NotFound::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__NotFound__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::NotFound");
    }
};

static __F__Tartarus__iface__SysDB__NotFound__Init __F__Tartarus__iface__SysDB__NotFound__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__NotFound__initializer() {} }
#endif

Tartarus::iface::SysDB::UserNotFound::UserNotFound(const ::std::string& __ice_reason, ::Ice::Long __ice_id) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    NotFound(__ice_reason),
#else
    ::Tartarus::iface::SysDB::NotFound(__ice_reason),
#endif
    id(__ice_id)
{
}

Tartarus::iface::SysDB::UserNotFound::~UserNotFound() throw()
{
}

static const char* __Tartarus__iface__SysDB__UserNotFound_name = "Tartarus::iface::SysDB::UserNotFound";

::std::string
Tartarus::iface::SysDB::UserNotFound::ice_name() const
{
    return __Tartarus__iface__SysDB__UserNotFound_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::UserNotFound::ice_clone() const
{
    return new UserNotFound(*this);
}

void
Tartarus::iface::SysDB::UserNotFound::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::UserNotFound::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::UserNotFound"), false);
    __os->startWriteSlice();
    __os->write(id);
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    NotFound::__write(__os);
#else
    ::Tartarus::iface::SysDB::NotFound::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::UserNotFound::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(id);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    NotFound::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::NotFound::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::UserNotFound::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::UserNotFound was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::UserNotFound::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::UserNotFound was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__UserNotFound : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::UserNotFound();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__UserNotFound__Ptr = new __F__Tartarus__iface__SysDB__UserNotFound;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::UserNotFound::ice_factory()
{
    return __F__Tartarus__iface__SysDB__UserNotFound__Ptr;
}

class __F__Tartarus__iface__SysDB__UserNotFound__Init
{
public:

    __F__Tartarus__iface__SysDB__UserNotFound__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::UserNotFound", ::Tartarus::iface::SysDB::UserNotFound::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__UserNotFound__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::UserNotFound");
    }
};

static __F__Tartarus__iface__SysDB__UserNotFound__Init __F__Tartarus__iface__SysDB__UserNotFound__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__UserNotFound__initializer() {} }
#endif

Tartarus::iface::SysDB::GroupNotFound::GroupNotFound(const ::std::string& __ice_reason, ::Ice::Long __ice_id) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    NotFound(__ice_reason),
#else
    ::Tartarus::iface::SysDB::NotFound(__ice_reason),
#endif
    id(__ice_id)
{
}

Tartarus::iface::SysDB::GroupNotFound::~GroupNotFound() throw()
{
}

static const char* __Tartarus__iface__SysDB__GroupNotFound_name = "Tartarus::iface::SysDB::GroupNotFound";

::std::string
Tartarus::iface::SysDB::GroupNotFound::ice_name() const
{
    return __Tartarus__iface__SysDB__GroupNotFound_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::GroupNotFound::ice_clone() const
{
    return new GroupNotFound(*this);
}

void
Tartarus::iface::SysDB::GroupNotFound::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::GroupNotFound::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::GroupNotFound"), false);
    __os->startWriteSlice();
    __os->write(id);
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    NotFound::__write(__os);
#else
    ::Tartarus::iface::SysDB::NotFound::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::GroupNotFound::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(id);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    NotFound::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::NotFound::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::GroupNotFound::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::GroupNotFound was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::GroupNotFound::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::GroupNotFound was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__GroupNotFound : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::GroupNotFound();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__GroupNotFound__Ptr = new __F__Tartarus__iface__SysDB__GroupNotFound;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::GroupNotFound::ice_factory()
{
    return __F__Tartarus__iface__SysDB__GroupNotFound__Ptr;
}

class __F__Tartarus__iface__SysDB__GroupNotFound__Init
{
public:

    __F__Tartarus__iface__SysDB__GroupNotFound__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::GroupNotFound", ::Tartarus::iface::SysDB::GroupNotFound::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__GroupNotFound__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::GroupNotFound");
    }
};

static __F__Tartarus__iface__SysDB__GroupNotFound__Init __F__Tartarus__iface__SysDB__GroupNotFound__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__GroupNotFound__initializer() {} }
#endif

Tartarus::iface::SysDB::PermissionDenied::PermissionDenied(const ::std::string& __ice_reason) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error(__ice_reason)
#else
    ::Tartarus::iface::SysDB::Error(__ice_reason)
#endif
{
}

Tartarus::iface::SysDB::PermissionDenied::~PermissionDenied() throw()
{
}

static const char* __Tartarus__iface__SysDB__PermissionDenied_name = "Tartarus::iface::SysDB::PermissionDenied";

::std::string
Tartarus::iface::SysDB::PermissionDenied::ice_name() const
{
    return __Tartarus__iface__SysDB__PermissionDenied_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::PermissionDenied::ice_clone() const
{
    return new PermissionDenied(*this);
}

void
Tartarus::iface::SysDB::PermissionDenied::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::PermissionDenied::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::PermissionDenied"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__write(__os);
#else
    ::Tartarus::iface::SysDB::Error::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::PermissionDenied::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::Error::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::PermissionDenied::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::PermissionDenied was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::PermissionDenied::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::PermissionDenied was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__PermissionDenied : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::PermissionDenied();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__PermissionDenied__Ptr = new __F__Tartarus__iface__SysDB__PermissionDenied;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::PermissionDenied::ice_factory()
{
    return __F__Tartarus__iface__SysDB__PermissionDenied__Ptr;
}

class __F__Tartarus__iface__SysDB__PermissionDenied__Init
{
public:

    __F__Tartarus__iface__SysDB__PermissionDenied__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::PermissionDenied", ::Tartarus::iface::SysDB::PermissionDenied::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__PermissionDenied__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::PermissionDenied");
    }
};

static __F__Tartarus__iface__SysDB__PermissionDenied__Init __F__Tartarus__iface__SysDB__PermissionDenied__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__PermissionDenied__initializer() {} }
#endif

Tartarus::iface::SysDB::AlreadyExists::AlreadyExists(const ::std::string& __ice_reason) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error(__ice_reason)
#else
    ::Tartarus::iface::SysDB::Error(__ice_reason)
#endif
{
}

Tartarus::iface::SysDB::AlreadyExists::~AlreadyExists() throw()
{
}

static const char* __Tartarus__iface__SysDB__AlreadyExists_name = "Tartarus::iface::SysDB::AlreadyExists";

::std::string
Tartarus::iface::SysDB::AlreadyExists::ice_name() const
{
    return __Tartarus__iface__SysDB__AlreadyExists_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::AlreadyExists::ice_clone() const
{
    return new AlreadyExists(*this);
}

void
Tartarus::iface::SysDB::AlreadyExists::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::AlreadyExists::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::AlreadyExists"), false);
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__write(__os);
#else
    ::Tartarus::iface::SysDB::Error::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::AlreadyExists::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::Error::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::AlreadyExists::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::AlreadyExists was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::AlreadyExists::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::AlreadyExists was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__AlreadyExists : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::AlreadyExists();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__AlreadyExists__Ptr = new __F__Tartarus__iface__SysDB__AlreadyExists;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::AlreadyExists::ice_factory()
{
    return __F__Tartarus__iface__SysDB__AlreadyExists__Ptr;
}

class __F__Tartarus__iface__SysDB__AlreadyExists__Init
{
public:

    __F__Tartarus__iface__SysDB__AlreadyExists__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::AlreadyExists", ::Tartarus::iface::SysDB::AlreadyExists::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__AlreadyExists__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::AlreadyExists");
    }
};

static __F__Tartarus__iface__SysDB__AlreadyExists__Init __F__Tartarus__iface__SysDB__AlreadyExists__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__AlreadyExists__initializer() {} }
#endif

Tartarus::iface::SysDB::UserAlreadyExists::UserAlreadyExists(const ::std::string& __ice_reason, ::Ice::Long __ice_id) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    AlreadyExists(__ice_reason),
#else
    ::Tartarus::iface::SysDB::AlreadyExists(__ice_reason),
#endif
    id(__ice_id)
{
}

Tartarus::iface::SysDB::UserAlreadyExists::~UserAlreadyExists() throw()
{
}

static const char* __Tartarus__iface__SysDB__UserAlreadyExists_name = "Tartarus::iface::SysDB::UserAlreadyExists";

::std::string
Tartarus::iface::SysDB::UserAlreadyExists::ice_name() const
{
    return __Tartarus__iface__SysDB__UserAlreadyExists_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::UserAlreadyExists::ice_clone() const
{
    return new UserAlreadyExists(*this);
}

void
Tartarus::iface::SysDB::UserAlreadyExists::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::UserAlreadyExists::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::UserAlreadyExists"), false);
    __os->startWriteSlice();
    __os->write(id);
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    AlreadyExists::__write(__os);
#else
    ::Tartarus::iface::SysDB::AlreadyExists::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::UserAlreadyExists::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(id);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    AlreadyExists::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::AlreadyExists::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::UserAlreadyExists::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::UserAlreadyExists was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::UserAlreadyExists::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::UserAlreadyExists was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__UserAlreadyExists : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::UserAlreadyExists();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__UserAlreadyExists__Ptr = new __F__Tartarus__iface__SysDB__UserAlreadyExists;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::UserAlreadyExists::ice_factory()
{
    return __F__Tartarus__iface__SysDB__UserAlreadyExists__Ptr;
}

class __F__Tartarus__iface__SysDB__UserAlreadyExists__Init
{
public:

    __F__Tartarus__iface__SysDB__UserAlreadyExists__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::UserAlreadyExists", ::Tartarus::iface::SysDB::UserAlreadyExists::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__UserAlreadyExists__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::UserAlreadyExists");
    }
};

static __F__Tartarus__iface__SysDB__UserAlreadyExists__Init __F__Tartarus__iface__SysDB__UserAlreadyExists__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__UserAlreadyExists__initializer() {} }
#endif

Tartarus::iface::SysDB::GroupAlreadyExists::GroupAlreadyExists(const ::std::string& __ice_reason, ::Ice::Long __ice_id) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    AlreadyExists(__ice_reason),
#else
    ::Tartarus::iface::SysDB::AlreadyExists(__ice_reason),
#endif
    id(__ice_id)
{
}

Tartarus::iface::SysDB::GroupAlreadyExists::~GroupAlreadyExists() throw()
{
}

static const char* __Tartarus__iface__SysDB__GroupAlreadyExists_name = "Tartarus::iface::SysDB::GroupAlreadyExists";

::std::string
Tartarus::iface::SysDB::GroupAlreadyExists::ice_name() const
{
    return __Tartarus__iface__SysDB__GroupAlreadyExists_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::GroupAlreadyExists::ice_clone() const
{
    return new GroupAlreadyExists(*this);
}

void
Tartarus::iface::SysDB::GroupAlreadyExists::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::GroupAlreadyExists::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::GroupAlreadyExists"), false);
    __os->startWriteSlice();
    __os->write(id);
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    AlreadyExists::__write(__os);
#else
    ::Tartarus::iface::SysDB::AlreadyExists::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::GroupAlreadyExists::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(id);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    AlreadyExists::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::AlreadyExists::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::GroupAlreadyExists::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::GroupAlreadyExists was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::GroupAlreadyExists::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::GroupAlreadyExists was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__GroupAlreadyExists : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::GroupAlreadyExists();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__GroupAlreadyExists__Ptr = new __F__Tartarus__iface__SysDB__GroupAlreadyExists;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::GroupAlreadyExists::ice_factory()
{
    return __F__Tartarus__iface__SysDB__GroupAlreadyExists__Ptr;
}

class __F__Tartarus__iface__SysDB__GroupAlreadyExists__Init
{
public:

    __F__Tartarus__iface__SysDB__GroupAlreadyExists__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::GroupAlreadyExists", ::Tartarus::iface::SysDB::GroupAlreadyExists::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__GroupAlreadyExists__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::GroupAlreadyExists");
    }
};

static __F__Tartarus__iface__SysDB__GroupAlreadyExists__Init __F__Tartarus__iface__SysDB__GroupAlreadyExists__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__GroupAlreadyExists__initializer() {} }
#endif

Tartarus::iface::SysDB::DBError::DBError(const ::std::string& __ice_reason, const ::std::string& __ice_message) :
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error(__ice_reason),
#else
    ::Tartarus::iface::SysDB::Error(__ice_reason),
#endif
    message(__ice_message)
{
}

Tartarus::iface::SysDB::DBError::~DBError() throw()
{
}

static const char* __Tartarus__iface__SysDB__DBError_name = "Tartarus::iface::SysDB::DBError";

::std::string
Tartarus::iface::SysDB::DBError::ice_name() const
{
    return __Tartarus__iface__SysDB__DBError_name;
}

::Ice::Exception*
Tartarus::iface::SysDB::DBError::ice_clone() const
{
    return new DBError(*this);
}

void
Tartarus::iface::SysDB::DBError::ice_throw() const
{
    throw *this;
}

void
Tartarus::iface::SysDB::DBError::__write(::IceInternal::BasicStream* __os) const
{
    __os->write(::std::string("::Tartarus::iface::SysDB::DBError"), false);
    __os->startWriteSlice();
    __os->write(message);
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__write(__os);
#else
    ::Tartarus::iface::SysDB::Error::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::DBError::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->read(myId, false);
    }
    __is->startReadSlice();
    __is->read(message);
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Error::__read(__is, true);
#else
    ::Tartarus::iface::SysDB::Error::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::DBError::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::DBError was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::DBError::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "exception Tartarus::iface::SysDB::DBError was not generated with stream support";
    throw ex;
}

struct __F__Tartarus__iface__SysDB__DBError : public ::IceInternal::UserExceptionFactory
{
    virtual void
    createAndThrow()
    {
        throw ::Tartarus::iface::SysDB::DBError();
    }
};

static ::IceInternal::UserExceptionFactoryPtr __F__Tartarus__iface__SysDB__DBError__Ptr = new __F__Tartarus__iface__SysDB__DBError;

const ::IceInternal::UserExceptionFactoryPtr&
Tartarus::iface::SysDB::DBError::ice_factory()
{
    return __F__Tartarus__iface__SysDB__DBError__Ptr;
}

class __F__Tartarus__iface__SysDB__DBError__Init
{
public:

    __F__Tartarus__iface__SysDB__DBError__Init()
    {
        ::IceInternal::factoryTable->addExceptionFactory("::Tartarus::iface::SysDB::DBError", ::Tartarus::iface::SysDB::DBError::ice_factory());
    }

    ~__F__Tartarus__iface__SysDB__DBError__Init()
    {
        ::IceInternal::factoryTable->removeExceptionFactory("::Tartarus::iface::SysDB::DBError");
    }
};

static __F__Tartarus__iface__SysDB__DBError__Init __F__Tartarus__iface__SysDB__DBError__i;

#ifdef __APPLE__
extern "C" { void __F__Tartarus__iface__SysDB__DBError__initializer() {} }
#endif

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::UserRecord* begin, const ::Tartarus::iface::SysDB::UserRecord* end, ::Tartarus::iface::SysDB::__U__UserSeq)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Tartarus::iface::SysDB::__read(::IceInternal::BasicStream* __is, ::Tartarus::iface::SysDB::UserSeq& v, ::Tartarus::iface::SysDB::__U__UserSeq)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 19);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Tartarus::iface::SysDB::__write(::IceInternal::BasicStream* __os, const ::Tartarus::iface::SysDB::GroupRecord* begin, const ::Tartarus::iface::SysDB::GroupRecord* end, ::Tartarus::iface::SysDB::__U__GroupSeq)
{
    ::Ice::Int size = static_cast< ::Ice::Int>(end - begin);
    __os->writeSize(size);
    for(int i = 0; i < size; ++i)
    {
        begin[i].__write(__os);
    }
}

void
Tartarus::iface::SysDB::__read(::IceInternal::BasicStream* __is, ::Tartarus::iface::SysDB::GroupSeq& v, ::Tartarus::iface::SysDB::__U__GroupSeq)
{
    ::Ice::Int sz;
    __is->readSize(sz);
    __is->startSeq(sz, 10);
    v.resize(sz);
    for(int i = 0; i < sz; ++i)
    {
        v[i].__read(__is);
        __is->checkSeq();
        __is->endElement();
    }
    __is->endSeq(sz);
}

void
Tartarus::iface::SysDB::__addObject(const UserReaderPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Tartarus::iface::SysDB::__usesClasses(const UserReaderPtr& p)
{
    return p->__usesClasses();
}

void
Tartarus::iface::SysDB::__decRefUnsafe(const UserReaderPtr& p)
{
    p->__decRefUnsafe();
}

void
Tartarus::iface::SysDB::__clearHandleUnsafe(UserReaderPtr& p)
{
    p.__clearHandleUnsafe();
}

void
Tartarus::iface::SysDB::__addObject(const UserManagerPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Tartarus::iface::SysDB::__usesClasses(const UserManagerPtr& p)
{
    return p->__usesClasses();
}

void
Tartarus::iface::SysDB::__decRefUnsafe(const UserManagerPtr& p)
{
    p->__decRefUnsafe();
}

void
Tartarus::iface::SysDB::__clearHandleUnsafe(UserManagerPtr& p)
{
    p.__clearHandleUnsafe();
}

void
Tartarus::iface::SysDB::__addObject(const GroupReaderPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Tartarus::iface::SysDB::__usesClasses(const GroupReaderPtr& p)
{
    return p->__usesClasses();
}

void
Tartarus::iface::SysDB::__decRefUnsafe(const GroupReaderPtr& p)
{
    p->__decRefUnsafe();
}

void
Tartarus::iface::SysDB::__clearHandleUnsafe(GroupReaderPtr& p)
{
    p.__clearHandleUnsafe();
}

void
Tartarus::iface::SysDB::__addObject(const GroupManagerPtr& p, ::IceInternal::GCCountMap& c)
{
    p->__addObject(c);
}

bool
Tartarus::iface::SysDB::__usesClasses(const GroupManagerPtr& p)
{
    return p->__usesClasses();
}

void
Tartarus::iface::SysDB::__decRefUnsafe(const GroupManagerPtr& p)
{
    p->__decRefUnsafe();
}

void
Tartarus::iface::SysDB::__clearHandleUnsafe(GroupManagerPtr& p)
{
    p.__clearHandleUnsafe();
}

::Tartarus::iface::SysDB::UserRecord
IceProxy::Tartarus::iface::SysDB::UserReader::getById(::Ice::Long uid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserReader__getById_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserReader*>(__delBase.get());
            return __del->getById(uid, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::UserRecord
IceProxy::Tartarus::iface::SysDB::UserReader::getByName(const ::std::string& name, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserReader__getByName_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserReader*>(__delBase.get());
            return __del->getByName(name, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::UserSeq
IceProxy::Tartarus::iface::SysDB::UserReader::getUsers(const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserReader__getUsers_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserReader*>(__delBase.get());
            return __del->getUsers(userIds, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::UserSeq
IceProxy::Tartarus::iface::SysDB::UserReader::search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserReader__search_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserReader*>(__delBase.get());
            return __del->search(factor, limit, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Long
IceProxy::Tartarus::iface::SysDB::UserReader::count(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserReader__count_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserReader*>(__delBase.get());
            return __del->count(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::UserSeq
IceProxy::Tartarus::iface::SysDB::UserReader::get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserReader__get_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserReader*>(__delBase.get());
            return __del->get(limit, offset, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Tartarus::iface::SysDB::UserReader::ice_staticId()
{
    return ::Tartarus::iface::SysDB::UserReader::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Tartarus::iface::SysDB::UserReader::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Tartarus::iface::SysDB::UserReader);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Tartarus::iface::SysDB::UserReader::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Tartarus::iface::SysDB::UserReader);
}

bool
IceProxy::Tartarus::iface::SysDB::operator==(const ::IceProxy::Tartarus::iface::SysDB::UserReader& l, const ::IceProxy::Tartarus::iface::SysDB::UserReader& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator!=(const ::IceProxy::Tartarus::iface::SysDB::UserReader& l, const ::IceProxy::Tartarus::iface::SysDB::UserReader& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<(const ::IceProxy::Tartarus::iface::SysDB::UserReader& l, const ::IceProxy::Tartarus::iface::SysDB::UserReader& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<=(const ::IceProxy::Tartarus::iface::SysDB::UserReader& l, const ::IceProxy::Tartarus::iface::SysDB::UserReader& r)
{
    return l < r || l == r;
}

bool
IceProxy::Tartarus::iface::SysDB::operator>(const ::IceProxy::Tartarus::iface::SysDB::UserReader& l, const ::IceProxy::Tartarus::iface::SysDB::UserReader& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator>=(const ::IceProxy::Tartarus::iface::SysDB::UserReader& l, const ::IceProxy::Tartarus::iface::SysDB::UserReader& r)
{
    return !(l < r);
}

void
IceProxy::Tartarus::iface::SysDB::UserManager::modify(const ::Tartarus::iface::SysDB::UserRecord& user, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserManager__modify_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserManager*>(__delBase.get());
            __del->modify(user, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Long
IceProxy::Tartarus::iface::SysDB::UserManager::create(const ::Tartarus::iface::SysDB::UserRecord& newUser, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserManager__create_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserManager*>(__delBase.get());
            return __del->create(newUser, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Tartarus::iface::SysDB::UserManager::_cpp_delete(::Ice::Long id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__UserManager__delete_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::UserManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::UserManager*>(__delBase.get());
            __del->_cpp_delete(id, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Tartarus::iface::SysDB::UserManager::ice_staticId()
{
    return ::Tartarus::iface::SysDB::UserManager::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Tartarus::iface::SysDB::UserManager::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Tartarus::iface::SysDB::UserManager);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Tartarus::iface::SysDB::UserManager::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Tartarus::iface::SysDB::UserManager);
}

bool
IceProxy::Tartarus::iface::SysDB::operator==(const ::IceProxy::Tartarus::iface::SysDB::UserManager& l, const ::IceProxy::Tartarus::iface::SysDB::UserManager& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator!=(const ::IceProxy::Tartarus::iface::SysDB::UserManager& l, const ::IceProxy::Tartarus::iface::SysDB::UserManager& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<(const ::IceProxy::Tartarus::iface::SysDB::UserManager& l, const ::IceProxy::Tartarus::iface::SysDB::UserManager& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<=(const ::IceProxy::Tartarus::iface::SysDB::UserManager& l, const ::IceProxy::Tartarus::iface::SysDB::UserManager& r)
{
    return l < r || l == r;
}

bool
IceProxy::Tartarus::iface::SysDB::operator>(const ::IceProxy::Tartarus::iface::SysDB::UserManager& l, const ::IceProxy::Tartarus::iface::SysDB::UserManager& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator>=(const ::IceProxy::Tartarus::iface::SysDB::UserManager& l, const ::IceProxy::Tartarus::iface::SysDB::UserManager& r)
{
    return !(l < r);
}

::Tartarus::iface::SysDB::GroupRecord
IceProxy::Tartarus::iface::SysDB::GroupReader::getById(::Ice::Long gid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__getById_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->getById(gid, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::GroupRecord
IceProxy::Tartarus::iface::SysDB::GroupReader::getByName(const ::std::string& name, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__getByName_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->getByName(name, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::IdSeq
IceProxy::Tartarus::iface::SysDB::GroupReader::getGroupsForUserId(::Ice::Long uid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__getGroupsForUserId_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->getGroupsForUserId(uid, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::IdSeq
IceProxy::Tartarus::iface::SysDB::GroupReader::getGroupsForUserName(const ::std::string& name, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__getGroupsForUserName_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->getGroupsForUserName(name, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceProxy::Tartarus::iface::SysDB::GroupReader::getGroups(const ::Tartarus::iface::SysDB::IdSeq& groupIds, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__getGroups_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->getGroups(groupIds, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::IdSeq
IceProxy::Tartarus::iface::SysDB::GroupReader::getUsers(::Ice::Long gid, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__getUsers_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->getUsers(gid, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceProxy::Tartarus::iface::SysDB::GroupReader::search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__search_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->search(factor, limit, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Long
IceProxy::Tartarus::iface::SysDB::GroupReader::count(const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__count_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->count(__ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceProxy::Tartarus::iface::SysDB::GroupReader::get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupReader__get_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupReader* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupReader*>(__delBase.get());
            return __del->get(limit, offset, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Tartarus::iface::SysDB::GroupReader::ice_staticId()
{
    return ::Tartarus::iface::SysDB::GroupReader::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Tartarus::iface::SysDB::GroupReader::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Tartarus::iface::SysDB::GroupReader);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Tartarus::iface::SysDB::GroupReader::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Tartarus::iface::SysDB::GroupReader);
}

bool
IceProxy::Tartarus::iface::SysDB::operator==(const ::IceProxy::Tartarus::iface::SysDB::GroupReader& l, const ::IceProxy::Tartarus::iface::SysDB::GroupReader& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator!=(const ::IceProxy::Tartarus::iface::SysDB::GroupReader& l, const ::IceProxy::Tartarus::iface::SysDB::GroupReader& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<(const ::IceProxy::Tartarus::iface::SysDB::GroupReader& l, const ::IceProxy::Tartarus::iface::SysDB::GroupReader& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<=(const ::IceProxy::Tartarus::iface::SysDB::GroupReader& l, const ::IceProxy::Tartarus::iface::SysDB::GroupReader& r)
{
    return l < r || l == r;
}

bool
IceProxy::Tartarus::iface::SysDB::operator>(const ::IceProxy::Tartarus::iface::SysDB::GroupReader& l, const ::IceProxy::Tartarus::iface::SysDB::GroupReader& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator>=(const ::IceProxy::Tartarus::iface::SysDB::GroupReader& l, const ::IceProxy::Tartarus::iface::SysDB::GroupReader& r)
{
    return !(l < r);
}

void
IceProxy::Tartarus::iface::SysDB::GroupManager::setUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__setUsers_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            __del->setUsers(gid, userIds, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Tartarus::iface::SysDB::GroupManager::addUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__addUsers_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            __del->addUsers(gid, userIds, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Tartarus::iface::SysDB::GroupManager::delUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__delUsers_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            __del->delUsers(gid, userIds, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Tartarus::iface::SysDB::GroupManager::modify(const ::Tartarus::iface::SysDB::GroupRecord& group, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__modify_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            __del->modify(group, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapperRelaxed(__delBase, __ex, __cnt);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

::Ice::Long
IceProxy::Tartarus::iface::SysDB::GroupManager::create(const ::Tartarus::iface::SysDB::GroupRecord& newGroup, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__create_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            return __del->create(newGroup, __ctx);
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Tartarus::iface::SysDB::GroupManager::_cpp_delete(::Ice::Long id, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__delete_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            __del->_cpp_delete(id, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Tartarus::iface::SysDB::GroupManager::addUserToGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__addUserToGroups_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            __del->addUserToGroups(uid, groups, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

void
IceProxy::Tartarus::iface::SysDB::GroupManager::delUserFromGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context* __ctx)
{
    int __cnt = 0;
    while(true)
    {
        ::IceInternal::Handle< ::IceDelegate::Ice::Object> __delBase;
        try
        {
            __checkTwowayOnly(__Tartarus__iface__SysDB__GroupManager__delUserFromGroups_name);
            __delBase = __getDelegate();
            ::IceDelegate::Tartarus::iface::SysDB::GroupManager* __del = dynamic_cast< ::IceDelegate::Tartarus::iface::SysDB::GroupManager*>(__delBase.get());
            __del->delUserFromGroups(uid, groups, __ctx);
            return;
        }
        catch(const ::IceInternal::LocalExceptionWrapper& __ex)
        {
            __handleExceptionWrapper(__delBase, __ex);
        }
        catch(const ::Ice::LocalException& __ex)
        {
            __handleException(__delBase, __ex, __cnt);
        }
    }
}

const ::std::string&
IceProxy::Tartarus::iface::SysDB::GroupManager::ice_staticId()
{
    return ::Tartarus::iface::SysDB::GroupManager::ice_staticId();
}

::IceInternal::Handle< ::IceDelegateM::Ice::Object>
IceProxy::Tartarus::iface::SysDB::GroupManager::__createDelegateM()
{
    return ::IceInternal::Handle< ::IceDelegateM::Ice::Object>(new ::IceDelegateM::Tartarus::iface::SysDB::GroupManager);
}

::IceInternal::Handle< ::IceDelegateD::Ice::Object>
IceProxy::Tartarus::iface::SysDB::GroupManager::__createDelegateD()
{
    return ::IceInternal::Handle< ::IceDelegateD::Ice::Object>(new ::IceDelegateD::Tartarus::iface::SysDB::GroupManager);
}

bool
IceProxy::Tartarus::iface::SysDB::operator==(const ::IceProxy::Tartarus::iface::SysDB::GroupManager& l, const ::IceProxy::Tartarus::iface::SysDB::GroupManager& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) == static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator!=(const ::IceProxy::Tartarus::iface::SysDB::GroupManager& l, const ::IceProxy::Tartarus::iface::SysDB::GroupManager& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) != static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<(const ::IceProxy::Tartarus::iface::SysDB::GroupManager& l, const ::IceProxy::Tartarus::iface::SysDB::GroupManager& r)
{
    return static_cast<const ::IceProxy::Ice::Object&>(l) < static_cast<const ::IceProxy::Ice::Object&>(r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator<=(const ::IceProxy::Tartarus::iface::SysDB::GroupManager& l, const ::IceProxy::Tartarus::iface::SysDB::GroupManager& r)
{
    return l < r || l == r;
}

bool
IceProxy::Tartarus::iface::SysDB::operator>(const ::IceProxy::Tartarus::iface::SysDB::GroupManager& l, const ::IceProxy::Tartarus::iface::SysDB::GroupManager& r)
{
    return !(l < r) && !(l == r);
}

bool
IceProxy::Tartarus::iface::SysDB::operator>=(const ::IceProxy::Tartarus::iface::SysDB::GroupManager& l, const ::IceProxy::Tartarus::iface::SysDB::GroupManager& r)
{
    return !(l < r);
}

::Tartarus::iface::SysDB::UserRecord
IceDelegateM::Tartarus::iface::SysDB::UserReader::getById(::Ice::Long uid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserReader__getById_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(uid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::UserRecord __ret;
        __ret.__read(__is);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::UserRecord
IceDelegateM::Tartarus::iface::SysDB::UserReader::getByName(const ::std::string& name, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserReader__getByName_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::UserRecord __ret;
        __ret.__read(__is);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::UserSeq
IceDelegateM::Tartarus::iface::SysDB::UserReader::getUsers(const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserReader__getUsers_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        if(userIds.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&userIds[0], &userIds[0] + userIds.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::UserSeq __ret;
        ::Tartarus::iface::SysDB::__read(__is, __ret, ::Tartarus::iface::SysDB::__U__UserSeq());
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::UserSeq
IceDelegateM::Tartarus::iface::SysDB::UserReader::search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserReader__search_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(factor);
        __os->write(limit);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::UserSeq __ret;
        ::Tartarus::iface::SysDB::__read(__is, __ret, ::Tartarus::iface::SysDB::__U__UserSeq());
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Long
IceDelegateM::Tartarus::iface::SysDB::UserReader::count(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserReader__count_name, ::Ice::Idempotent, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Long __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::UserSeq
IceDelegateM::Tartarus::iface::SysDB::UserReader::get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserReader__get_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(limit);
        __os->write(offset);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::UserSeq __ret;
        ::Tartarus::iface::SysDB::__read(__is, __ret, ::Tartarus::iface::SysDB::__U__UserSeq());
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::UserManager::modify(const ::Tartarus::iface::SysDB::UserRecord& user, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserManager__modify_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        user.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Long
IceDelegateM::Tartarus::iface::SysDB::UserManager::create(const ::Tartarus::iface::SysDB::UserRecord& newUser, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserManager__create_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        newUser.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Long __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::UserManager::_cpp_delete(::Ice::Long id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__UserManager__delete_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::GroupRecord
IceDelegateM::Tartarus::iface::SysDB::GroupReader::getById(::Ice::Long gid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__getById_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(gid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::GroupRecord __ret;
        __ret.__read(__is);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::GroupRecord
IceDelegateM::Tartarus::iface::SysDB::GroupReader::getByName(const ::std::string& name, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__getByName_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::GroupRecord __ret;
        __ret.__read(__is);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::IdSeq
IceDelegateM::Tartarus::iface::SysDB::GroupReader::getGroupsForUserId(::Ice::Long uid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__getGroupsForUserId_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(uid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::IdSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::IdSeq
IceDelegateM::Tartarus::iface::SysDB::GroupReader::getGroupsForUserName(const ::std::string& name, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__getGroupsForUserName_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(name);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::IdSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceDelegateM::Tartarus::iface::SysDB::GroupReader::getGroups(const ::Tartarus::iface::SysDB::IdSeq& groupIds, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__getGroups_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        if(groupIds.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&groupIds[0], &groupIds[0] + groupIds.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::GroupSeq __ret;
        ::Tartarus::iface::SysDB::__read(__is, __ret, ::Tartarus::iface::SysDB::__U__GroupSeq());
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::IdSeq
IceDelegateM::Tartarus::iface::SysDB::GroupReader::getUsers(::Ice::Long gid, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__getUsers_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(gid);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::IdSeq __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceDelegateM::Tartarus::iface::SysDB::GroupReader::search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__search_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(factor);
        __os->write(limit);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::GroupSeq __ret;
        ::Tartarus::iface::SysDB::__read(__is, __ret, ::Tartarus::iface::SysDB::__U__GroupSeq());
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Long
IceDelegateM::Tartarus::iface::SysDB::GroupReader::count(const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__count_name, ::Ice::Idempotent, __context, __compress);
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Long __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceDelegateM::Tartarus::iface::SysDB::GroupReader::get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupReader__get_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(limit);
        __os->write(offset);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Tartarus::iface::SysDB::GroupSeq __ret;
        ::Tartarus::iface::SysDB::__read(__is, __ret, ::Tartarus::iface::SysDB::__U__GroupSeq());
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::GroupManager::setUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__setUsers_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(gid);
        if(userIds.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&userIds[0], &userIds[0] + userIds.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::GroupManager::addUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__addUsers_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(gid);
        if(userIds.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&userIds[0], &userIds[0] + userIds.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::GroupManager::delUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__delUsers_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(gid);
        if(userIds.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&userIds[0], &userIds[0] + userIds.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::GroupManager::modify(const ::Tartarus::iface::SysDB::GroupRecord& group, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__modify_name, ::Ice::Idempotent, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        group.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Ice::Long
IceDelegateM::Tartarus::iface::SysDB::GroupManager::create(const ::Tartarus::iface::SysDB::GroupRecord& newGroup, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__create_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        newGroup.__write(__os);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
        ::Ice::Long __ret;
        __is->read(__ret);
        return __ret;
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::GroupManager::_cpp_delete(::Ice::Long id, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__delete_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(id);
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::GroupManager::addUserToGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__addUserToGroups_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(uid);
        if(groups.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&groups[0], &groups[0] + groups.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

void
IceDelegateM::Tartarus::iface::SysDB::GroupManager::delUserFromGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context* __context)
{
    ::IceInternal::Outgoing __og(__connection.get(), __reference.get(), __Tartarus__iface__SysDB__GroupManager__delUserFromGroups_name, ::Ice::Normal, __context, __compress);
    try
    {
        ::IceInternal::BasicStream* __os = __og.os();
        __os->write(uid);
        if(groups.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&groups[0], &groups[0] + groups.size());
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        __og.abort(__ex);
    }
    bool __ok = __og.invoke();
    try
    {
        ::IceInternal::BasicStream* __is = __og.is();
        if(!__ok)
        {
            try
            {
                __is->throwException();
            }
            catch(const ::Tartarus::iface::SysDB::Error&)
            {
                throw;
            }
            catch(const ::Ice::UserException& __ex)
            {
                throw ::Ice::UnknownUserException(__FILE__, __LINE__, __ex.ice_name());
            }
        }
    }
    catch(const ::Ice::LocalException& __ex)
    {
        throw ::IceInternal::LocalExceptionWrapper(__ex, false);
    }
}

::Tartarus::iface::SysDB::UserRecord
IceDelegateD::Tartarus::iface::SysDB::UserReader::getById(::Ice::Long uid, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserReader__getById_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::UserRecord __ret;
        try
        {
            ::Tartarus::iface::SysDB::UserReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getById(uid, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::UserRecord
IceDelegateD::Tartarus::iface::SysDB::UserReader::getByName(const ::std::string& name, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserReader__getByName_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::UserRecord __ret;
        try
        {
            ::Tartarus::iface::SysDB::UserReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getByName(name, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::UserSeq
IceDelegateD::Tartarus::iface::SysDB::UserReader::getUsers(const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserReader__getUsers_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::UserSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::UserReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getUsers(userIds, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::UserSeq
IceDelegateD::Tartarus::iface::SysDB::UserReader::search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserReader__search_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::UserSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::UserReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->search(factor, limit, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Long
IceDelegateD::Tartarus::iface::SysDB::UserReader::count(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserReader__count_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Long __ret;
        try
        {
            ::Tartarus::iface::SysDB::UserReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->count(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::UserSeq
IceDelegateD::Tartarus::iface::SysDB::UserReader::get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserReader__get_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::UserSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::UserReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->get(limit, offset, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::UserManager::modify(const ::Tartarus::iface::SysDB::UserRecord& user, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserManager__modify_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::UserManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->modify(user, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::Ice::Long
IceDelegateD::Tartarus::iface::SysDB::UserManager::create(const ::Tartarus::iface::SysDB::UserRecord& newUser, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserManager__create_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Long __ret;
        try
        {
            ::Tartarus::iface::SysDB::UserManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->create(newUser, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::UserManager::_cpp_delete(::Ice::Long id, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__UserManager__delete_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::UserManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::UserManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->_cpp_delete(id, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::Tartarus::iface::SysDB::GroupRecord
IceDelegateD::Tartarus::iface::SysDB::GroupReader::getById(::Ice::Long gid, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__getById_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::GroupRecord __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getById(gid, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::GroupRecord
IceDelegateD::Tartarus::iface::SysDB::GroupReader::getByName(const ::std::string& name, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__getByName_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::GroupRecord __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getByName(name, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::IdSeq
IceDelegateD::Tartarus::iface::SysDB::GroupReader::getGroupsForUserId(::Ice::Long uid, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__getGroupsForUserId_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::IdSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getGroupsForUserId(uid, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::IdSeq
IceDelegateD::Tartarus::iface::SysDB::GroupReader::getGroupsForUserName(const ::std::string& name, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__getGroupsForUserName_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::IdSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getGroupsForUserName(name, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceDelegateD::Tartarus::iface::SysDB::GroupReader::getGroups(const ::Tartarus::iface::SysDB::IdSeq& groupIds, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__getGroups_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::GroupSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getGroups(groupIds, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::IdSeq
IceDelegateD::Tartarus::iface::SysDB::GroupReader::getUsers(::Ice::Long gid, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__getUsers_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::IdSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->getUsers(gid, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceDelegateD::Tartarus::iface::SysDB::GroupReader::search(const ::std::string& factor, ::Ice::Long limit, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__search_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::GroupSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->search(factor, limit, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Ice::Long
IceDelegateD::Tartarus::iface::SysDB::GroupReader::count(const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__count_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Long __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->count(__current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

::Tartarus::iface::SysDB::GroupSeq
IceDelegateD::Tartarus::iface::SysDB::GroupReader::get(::Ice::Long limit, ::Ice::Long offset, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupReader__get_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Tartarus::iface::SysDB::GroupSeq __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupReader* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupReader*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->get(limit, offset, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::GroupManager::setUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__setUsers_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->setUsers(gid, userIds, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::GroupManager::addUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__addUsers_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addUsers(gid, userIds, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::GroupManager::delUsers(::Ice::Long gid, const ::Tartarus::iface::SysDB::IdSeq& userIds, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__delUsers_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->delUsers(gid, userIds, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::GroupManager::modify(const ::Tartarus::iface::SysDB::GroupRecord& group, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__modify_name, ::Ice::Idempotent, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->modify(group, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::Ice::Long
IceDelegateD::Tartarus::iface::SysDB::GroupManager::create(const ::Tartarus::iface::SysDB::GroupRecord& newGroup, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__create_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        ::Ice::Long __ret;
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __ret = __servant->create(newGroup, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return __ret;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::GroupManager::_cpp_delete(::Ice::Long id, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__delete_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->_cpp_delete(id, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::GroupManager::addUserToGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__addUserToGroups_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->addUserToGroups(uid, groups, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

void
IceDelegateD::Tartarus::iface::SysDB::GroupManager::delUserFromGroups(::Ice::Long uid, const ::Tartarus::iface::SysDB::IdSeq& groups, const ::Ice::Context* __context)
{
    ::Ice::Current __current;
    __initCurrent(__current, __Tartarus__iface__SysDB__GroupManager__delUserFromGroups_name, ::Ice::Normal, __context);
    while(true)
    {
        ::IceInternal::Direct __direct(__current);
        try
        {
            ::Tartarus::iface::SysDB::GroupManager* __servant = dynamic_cast< ::Tartarus::iface::SysDB::GroupManager*>(__direct.servant().get());
            if(!__servant)
            {
                ::Ice::OperationNotExistException __opEx(__FILE__, __LINE__);
                __opEx.id = __current.id;
                __opEx.facet = __current.facet;
                __opEx.operation = __current.operation;
                throw __opEx;
            }
            try
            {
                __servant->delUserFromGroups(uid, groups, __current);
            }
            catch(const ::Ice::LocalException& __ex)
            {
                throw ::IceInternal::LocalExceptionWrapper(__ex, false);
            }
        }
        catch(...)
        {
            __direct.destroy();
            throw;
        }
        __direct.destroy();
        return;
    }
}

::Ice::ObjectPtr
Tartarus::iface::SysDB::UserReader::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Tartarus__iface__SysDB__UserReader_ids[2] =
{
    "::Ice::Object",
    "::Tartarus::iface::SysDB::UserReader"
};

bool
Tartarus::iface::SysDB::UserReader::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Tartarus__iface__SysDB__UserReader_ids, __Tartarus__iface__SysDB__UserReader_ids + 2, _s);
}

::std::vector< ::std::string>
Tartarus::iface::SysDB::UserReader::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Tartarus__iface__SysDB__UserReader_ids[0], &__Tartarus__iface__SysDB__UserReader_ids[2]);
}

const ::std::string&
Tartarus::iface::SysDB::UserReader::ice_id(const ::Ice::Current&) const
{
    return __Tartarus__iface__SysDB__UserReader_ids[1];
}

const ::std::string&
Tartarus::iface::SysDB::UserReader::ice_staticId()
{
    return __Tartarus__iface__SysDB__UserReader_ids[1];
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserReader::___getById(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long uid;
    __is->read(uid);
    try
    {
        ::Tartarus::iface::SysDB::UserRecord __ret = getById(uid, __current);
        __ret.__write(__os);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserReader::___getByName(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    __is->read(name);
    try
    {
        ::Tartarus::iface::SysDB::UserRecord __ret = getByName(name, __current);
        __ret.__write(__os);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserReader::___getUsers(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Tartarus::iface::SysDB::IdSeq userIds;
    __is->read(userIds);
    try
    {
        ::Tartarus::iface::SysDB::UserSeq __ret = getUsers(userIds, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Tartarus::iface::SysDB::__write(__os, &__ret[0], &__ret[0] + __ret.size(), ::Tartarus::iface::SysDB::__U__UserSeq());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserReader::___search(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string factor;
    ::Ice::Long limit;
    __is->read(factor);
    __is->read(limit);
    try
    {
        ::Tartarus::iface::SysDB::UserSeq __ret = search(factor, limit, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Tartarus::iface::SysDB::__write(__os, &__ret[0], &__ret[0] + __ret.size(), ::Tartarus::iface::SysDB::__U__UserSeq());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserReader::___count(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        ::Ice::Long __ret = count(__current);
        __os->write(__ret);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserReader::___get(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long limit;
    ::Ice::Long offset;
    __is->read(limit);
    __is->read(offset);
    try
    {
        ::Tartarus::iface::SysDB::UserSeq __ret = get(limit, offset, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Tartarus::iface::SysDB::__write(__os, &__ret[0], &__ret[0] + __ret.size(), ::Tartarus::iface::SysDB::__U__UserSeq());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

static ::std::string __Tartarus__iface__SysDB__UserReader_all[] =
{
    "count",
    "get",
    "getById",
    "getByName",
    "getUsers",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "search"
};

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserReader::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Tartarus__iface__SysDB__UserReader_all, __Tartarus__iface__SysDB__UserReader_all + 10, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Tartarus__iface__SysDB__UserReader_all)
    {
        case 0:
        {
            return ___count(in, current);
        }
        case 1:
        {
            return ___get(in, current);
        }
        case 2:
        {
            return ___getById(in, current);
        }
        case 3:
        {
            return ___getByName(in, current);
        }
        case 4:
        {
            return ___getUsers(in, current);
        }
        case 5:
        {
            return ___ice_id(in, current);
        }
        case 6:
        {
            return ___ice_ids(in, current);
        }
        case 7:
        {
            return ___ice_isA(in, current);
        }
        case 8:
        {
            return ___ice_ping(in, current);
        }
        case 9:
        {
            return ___search(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Tartarus::iface::SysDB::UserReader::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::UserReader::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::UserReader::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::UserReader was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::UserReader::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::UserReader was not generated with stream support";
    throw ex;
}

void 
Tartarus::iface::SysDB::__patch__UserReaderPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Tartarus::iface::SysDB::UserReaderPtr* p = static_cast< ::Tartarus::iface::SysDB::UserReaderPtr*>(__addr);
    assert(p);
    *p = ::Tartarus::iface::SysDB::UserReaderPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Tartarus::iface::SysDB::UserReader::ice_staticId();
        throw e;
    }
}

bool
Tartarus::iface::SysDB::operator==(const ::Tartarus::iface::SysDB::UserReader& l, const ::Tartarus::iface::SysDB::UserReader& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator!=(const ::Tartarus::iface::SysDB::UserReader& l, const ::Tartarus::iface::SysDB::UserReader& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<(const ::Tartarus::iface::SysDB::UserReader& l, const ::Tartarus::iface::SysDB::UserReader& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<=(const ::Tartarus::iface::SysDB::UserReader& l, const ::Tartarus::iface::SysDB::UserReader& r)
{
    return l < r || l == r;
}

bool
Tartarus::iface::SysDB::operator>(const ::Tartarus::iface::SysDB::UserReader& l, const ::Tartarus::iface::SysDB::UserReader& r)
{
    return !(l < r) && !(l == r);
}

bool
Tartarus::iface::SysDB::operator>=(const ::Tartarus::iface::SysDB::UserReader& l, const ::Tartarus::iface::SysDB::UserReader& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
Tartarus::iface::SysDB::UserManager::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Tartarus__iface__SysDB__UserManager_ids[3] =
{
    "::Ice::Object",
    "::Tartarus::iface::SysDB::UserManager",
    "::Tartarus::iface::SysDB::UserReader"
};

bool
Tartarus::iface::SysDB::UserManager::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Tartarus__iface__SysDB__UserManager_ids, __Tartarus__iface__SysDB__UserManager_ids + 3, _s);
}

::std::vector< ::std::string>
Tartarus::iface::SysDB::UserManager::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Tartarus__iface__SysDB__UserManager_ids[0], &__Tartarus__iface__SysDB__UserManager_ids[3]);
}

const ::std::string&
Tartarus::iface::SysDB::UserManager::ice_id(const ::Ice::Current&) const
{
    return __Tartarus__iface__SysDB__UserManager_ids[1];
}

const ::std::string&
Tartarus::iface::SysDB::UserManager::ice_staticId()
{
    return __Tartarus__iface__SysDB__UserManager_ids[1];
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserManager::___modify(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Tartarus::iface::SysDB::UserRecord user;
    user.__read(__is);
    try
    {
        modify(user, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserManager::___create(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Tartarus::iface::SysDB::UserRecord newUser;
    newUser.__read(__is);
    try
    {
        ::Ice::Long __ret = create(newUser, __current);
        __os->write(__ret);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserManager::___delete(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long id;
    __is->read(id);
    try
    {
        _cpp_delete(id, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

static ::std::string __Tartarus__iface__SysDB__UserManager_all[] =
{
    "count",
    "create",
    "delete",
    "get",
    "getById",
    "getByName",
    "getUsers",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "modify",
    "search"
};

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::UserManager::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Tartarus__iface__SysDB__UserManager_all, __Tartarus__iface__SysDB__UserManager_all + 13, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Tartarus__iface__SysDB__UserManager_all)
    {
        case 0:
        {
            return ___count(in, current);
        }
        case 1:
        {
            return ___create(in, current);
        }
        case 2:
        {
            return ___delete(in, current);
        }
        case 3:
        {
            return ___get(in, current);
        }
        case 4:
        {
            return ___getById(in, current);
        }
        case 5:
        {
            return ___getByName(in, current);
        }
        case 6:
        {
            return ___getUsers(in, current);
        }
        case 7:
        {
            return ___ice_id(in, current);
        }
        case 8:
        {
            return ___ice_ids(in, current);
        }
        case 9:
        {
            return ___ice_isA(in, current);
        }
        case 10:
        {
            return ___ice_ping(in, current);
        }
        case 11:
        {
            return ___modify(in, current);
        }
        case 12:
        {
            return ___search(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Tartarus::iface::SysDB::UserManager::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::UserManager::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::UserManager::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::UserManager was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::UserManager::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::UserManager was not generated with stream support";
    throw ex;
}

void 
Tartarus::iface::SysDB::__patch__UserManagerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Tartarus::iface::SysDB::UserManagerPtr* p = static_cast< ::Tartarus::iface::SysDB::UserManagerPtr*>(__addr);
    assert(p);
    *p = ::Tartarus::iface::SysDB::UserManagerPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Tartarus::iface::SysDB::UserManager::ice_staticId();
        throw e;
    }
}

bool
Tartarus::iface::SysDB::operator==(const ::Tartarus::iface::SysDB::UserManager& l, const ::Tartarus::iface::SysDB::UserManager& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator!=(const ::Tartarus::iface::SysDB::UserManager& l, const ::Tartarus::iface::SysDB::UserManager& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<(const ::Tartarus::iface::SysDB::UserManager& l, const ::Tartarus::iface::SysDB::UserManager& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<=(const ::Tartarus::iface::SysDB::UserManager& l, const ::Tartarus::iface::SysDB::UserManager& r)
{
    return l < r || l == r;
}

bool
Tartarus::iface::SysDB::operator>(const ::Tartarus::iface::SysDB::UserManager& l, const ::Tartarus::iface::SysDB::UserManager& r)
{
    return !(l < r) && !(l == r);
}

bool
Tartarus::iface::SysDB::operator>=(const ::Tartarus::iface::SysDB::UserManager& l, const ::Tartarus::iface::SysDB::UserManager& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
Tartarus::iface::SysDB::GroupReader::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Tartarus__iface__SysDB__GroupReader_ids[2] =
{
    "::Ice::Object",
    "::Tartarus::iface::SysDB::GroupReader"
};

bool
Tartarus::iface::SysDB::GroupReader::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Tartarus__iface__SysDB__GroupReader_ids, __Tartarus__iface__SysDB__GroupReader_ids + 2, _s);
}

::std::vector< ::std::string>
Tartarus::iface::SysDB::GroupReader::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Tartarus__iface__SysDB__GroupReader_ids[0], &__Tartarus__iface__SysDB__GroupReader_ids[2]);
}

const ::std::string&
Tartarus::iface::SysDB::GroupReader::ice_id(const ::Ice::Current&) const
{
    return __Tartarus__iface__SysDB__GroupReader_ids[1];
}

const ::std::string&
Tartarus::iface::SysDB::GroupReader::ice_staticId()
{
    return __Tartarus__iface__SysDB__GroupReader_ids[1];
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___getById(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long gid;
    __is->read(gid);
    try
    {
        ::Tartarus::iface::SysDB::GroupRecord __ret = getById(gid, __current);
        __ret.__write(__os);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___getByName(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    __is->read(name);
    try
    {
        ::Tartarus::iface::SysDB::GroupRecord __ret = getByName(name, __current);
        __ret.__write(__os);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___getGroupsForUserId(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long uid;
    __is->read(uid);
    try
    {
        ::Tartarus::iface::SysDB::IdSeq __ret = getGroupsForUserId(uid, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___getGroupsForUserName(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string name;
    __is->read(name);
    try
    {
        ::Tartarus::iface::SysDB::IdSeq __ret = getGroupsForUserName(name, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___getGroups(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Tartarus::iface::SysDB::IdSeq groupIds;
    __is->read(groupIds);
    try
    {
        ::Tartarus::iface::SysDB::GroupSeq __ret = getGroups(groupIds, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Tartarus::iface::SysDB::__write(__os, &__ret[0], &__ret[0] + __ret.size(), ::Tartarus::iface::SysDB::__U__GroupSeq());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___getUsers(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long gid;
    __is->read(gid);
    try
    {
        ::Tartarus::iface::SysDB::IdSeq __ret = getUsers(gid, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            __os->write(&__ret[0], &__ret[0] + __ret.size());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___search(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::std::string factor;
    ::Ice::Long limit;
    __is->read(factor);
    __is->read(limit);
    try
    {
        ::Tartarus::iface::SysDB::GroupSeq __ret = search(factor, limit, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Tartarus::iface::SysDB::__write(__os, &__ret[0], &__ret[0] + __ret.size(), ::Tartarus::iface::SysDB::__U__GroupSeq());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___count(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __os = __inS.os();
    try
    {
        ::Ice::Long __ret = count(__current);
        __os->write(__ret);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::___get(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long limit;
    ::Ice::Long offset;
    __is->read(limit);
    __is->read(offset);
    try
    {
        ::Tartarus::iface::SysDB::GroupSeq __ret = get(limit, offset, __current);
        if(__ret.size() == 0)
        {
            __os->writeSize(0);
        }
        else
        {
            ::Tartarus::iface::SysDB::__write(__os, &__ret[0], &__ret[0] + __ret.size(), ::Tartarus::iface::SysDB::__U__GroupSeq());
        }
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

static ::std::string __Tartarus__iface__SysDB__GroupReader_all[] =
{
    "count",
    "get",
    "getById",
    "getByName",
    "getGroups",
    "getGroupsForUserId",
    "getGroupsForUserName",
    "getUsers",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "search"
};

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupReader::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Tartarus__iface__SysDB__GroupReader_all, __Tartarus__iface__SysDB__GroupReader_all + 13, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Tartarus__iface__SysDB__GroupReader_all)
    {
        case 0:
        {
            return ___count(in, current);
        }
        case 1:
        {
            return ___get(in, current);
        }
        case 2:
        {
            return ___getById(in, current);
        }
        case 3:
        {
            return ___getByName(in, current);
        }
        case 4:
        {
            return ___getGroups(in, current);
        }
        case 5:
        {
            return ___getGroupsForUserId(in, current);
        }
        case 6:
        {
            return ___getGroupsForUserName(in, current);
        }
        case 7:
        {
            return ___getUsers(in, current);
        }
        case 8:
        {
            return ___ice_id(in, current);
        }
        case 9:
        {
            return ___ice_ids(in, current);
        }
        case 10:
        {
            return ___ice_isA(in, current);
        }
        case 11:
        {
            return ___ice_ping(in, current);
        }
        case 12:
        {
            return ___search(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Tartarus::iface::SysDB::GroupReader::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::GroupReader::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::GroupReader::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::GroupReader was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::GroupReader::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::GroupReader was not generated with stream support";
    throw ex;
}

void 
Tartarus::iface::SysDB::__patch__GroupReaderPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Tartarus::iface::SysDB::GroupReaderPtr* p = static_cast< ::Tartarus::iface::SysDB::GroupReaderPtr*>(__addr);
    assert(p);
    *p = ::Tartarus::iface::SysDB::GroupReaderPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Tartarus::iface::SysDB::GroupReader::ice_staticId();
        throw e;
    }
}

bool
Tartarus::iface::SysDB::operator==(const ::Tartarus::iface::SysDB::GroupReader& l, const ::Tartarus::iface::SysDB::GroupReader& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator!=(const ::Tartarus::iface::SysDB::GroupReader& l, const ::Tartarus::iface::SysDB::GroupReader& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<(const ::Tartarus::iface::SysDB::GroupReader& l, const ::Tartarus::iface::SysDB::GroupReader& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<=(const ::Tartarus::iface::SysDB::GroupReader& l, const ::Tartarus::iface::SysDB::GroupReader& r)
{
    return l < r || l == r;
}

bool
Tartarus::iface::SysDB::operator>(const ::Tartarus::iface::SysDB::GroupReader& l, const ::Tartarus::iface::SysDB::GroupReader& r)
{
    return !(l < r) && !(l == r);
}

bool
Tartarus::iface::SysDB::operator>=(const ::Tartarus::iface::SysDB::GroupReader& l, const ::Tartarus::iface::SysDB::GroupReader& r)
{
    return !(l < r);
}

::Ice::ObjectPtr
Tartarus::iface::SysDB::GroupManager::ice_clone() const
{
    throw ::Ice::CloneNotImplementedException(__FILE__, __LINE__);
    return 0; // to avoid a warning with some compilers
}

static const ::std::string __Tartarus__iface__SysDB__GroupManager_ids[3] =
{
    "::Ice::Object",
    "::Tartarus::iface::SysDB::GroupManager",
    "::Tartarus::iface::SysDB::GroupReader"
};

bool
Tartarus::iface::SysDB::GroupManager::ice_isA(const ::std::string& _s, const ::Ice::Current&) const
{
    return ::std::binary_search(__Tartarus__iface__SysDB__GroupManager_ids, __Tartarus__iface__SysDB__GroupManager_ids + 3, _s);
}

::std::vector< ::std::string>
Tartarus::iface::SysDB::GroupManager::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&__Tartarus__iface__SysDB__GroupManager_ids[0], &__Tartarus__iface__SysDB__GroupManager_ids[3]);
}

const ::std::string&
Tartarus::iface::SysDB::GroupManager::ice_id(const ::Ice::Current&) const
{
    return __Tartarus__iface__SysDB__GroupManager_ids[1];
}

const ::std::string&
Tartarus::iface::SysDB::GroupManager::ice_staticId()
{
    return __Tartarus__iface__SysDB__GroupManager_ids[1];
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___setUsers(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long gid;
    ::Tartarus::iface::SysDB::IdSeq userIds;
    __is->read(gid);
    __is->read(userIds);
    try
    {
        setUsers(gid, userIds, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___addUsers(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long gid;
    ::Tartarus::iface::SysDB::IdSeq userIds;
    __is->read(gid);
    __is->read(userIds);
    try
    {
        addUsers(gid, userIds, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___delUsers(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long gid;
    ::Tartarus::iface::SysDB::IdSeq userIds;
    __is->read(gid);
    __is->read(userIds);
    try
    {
        delUsers(gid, userIds, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___modify(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Idempotent, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Tartarus::iface::SysDB::GroupRecord group;
    group.__read(__is);
    try
    {
        modify(group, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___create(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Tartarus::iface::SysDB::GroupRecord newGroup;
    newGroup.__read(__is);
    try
    {
        ::Ice::Long __ret = create(newGroup, __current);
        __os->write(__ret);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___delete(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long id;
    __is->read(id);
    try
    {
        _cpp_delete(id, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___addUserToGroups(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long uid;
    ::Tartarus::iface::SysDB::IdSeq groups;
    __is->read(uid);
    __is->read(groups);
    try
    {
        addUserToGroups(uid, groups, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::___delUserFromGroups(::IceInternal::Incoming&__inS, const ::Ice::Current& __current)
{
    __checkMode(::Ice::Normal, __current.mode);
    ::IceInternal::BasicStream* __is = __inS.is();
    ::IceInternal::BasicStream* __os = __inS.os();
    ::Ice::Long uid;
    ::Tartarus::iface::SysDB::IdSeq groups;
    __is->read(uid);
    __is->read(groups);
    try
    {
        delUserFromGroups(uid, groups, __current);
    }
    catch(const ::Tartarus::iface::SysDB::Error& __ex)
    {
        __os->write(__ex);
        return ::IceInternal::DispatchUserException;
    }
    return ::IceInternal::DispatchOK;
}

static ::std::string __Tartarus__iface__SysDB__GroupManager_all[] =
{
    "addUserToGroups",
    "addUsers",
    "count",
    "create",
    "delUserFromGroups",
    "delUsers",
    "delete",
    "get",
    "getById",
    "getByName",
    "getGroups",
    "getGroupsForUserId",
    "getGroupsForUserName",
    "getUsers",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "modify",
    "search",
    "setUsers"
};

::IceInternal::DispatchStatus
Tartarus::iface::SysDB::GroupManager::__dispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair< ::std::string*, ::std::string*> r = ::std::equal_range(__Tartarus__iface__SysDB__GroupManager_all, __Tartarus__iface__SysDB__GroupManager_all + 21, current.operation);
    if(r.first == r.second)
    {
        return ::IceInternal::DispatchOperationNotExist;
    }

    switch(r.first - __Tartarus__iface__SysDB__GroupManager_all)
    {
        case 0:
        {
            return ___addUserToGroups(in, current);
        }
        case 1:
        {
            return ___addUsers(in, current);
        }
        case 2:
        {
            return ___count(in, current);
        }
        case 3:
        {
            return ___create(in, current);
        }
        case 4:
        {
            return ___delUserFromGroups(in, current);
        }
        case 5:
        {
            return ___delUsers(in, current);
        }
        case 6:
        {
            return ___delete(in, current);
        }
        case 7:
        {
            return ___get(in, current);
        }
        case 8:
        {
            return ___getById(in, current);
        }
        case 9:
        {
            return ___getByName(in, current);
        }
        case 10:
        {
            return ___getGroups(in, current);
        }
        case 11:
        {
            return ___getGroupsForUserId(in, current);
        }
        case 12:
        {
            return ___getGroupsForUserName(in, current);
        }
        case 13:
        {
            return ___getUsers(in, current);
        }
        case 14:
        {
            return ___ice_id(in, current);
        }
        case 15:
        {
            return ___ice_ids(in, current);
        }
        case 16:
        {
            return ___ice_isA(in, current);
        }
        case 17:
        {
            return ___ice_ping(in, current);
        }
        case 18:
        {
            return ___modify(in, current);
        }
        case 19:
        {
            return ___search(in, current);
        }
        case 20:
        {
            return ___setUsers(in, current);
        }
    }

    assert(false);
    return ::IceInternal::DispatchOperationNotExist;
}

void
Tartarus::iface::SysDB::GroupManager::__write(::IceInternal::BasicStream* __os) const
{
    __os->writeTypeId(ice_staticId());
    __os->startWriteSlice();
    __os->endWriteSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__write(__os);
#else
    ::Ice::Object::__write(__os);
#endif
}

void
Tartarus::iface::SysDB::GroupManager::__read(::IceInternal::BasicStream* __is, bool __rid)
{
    if(__rid)
    {
        ::std::string myId;
        __is->readTypeId(myId);
    }
    __is->startReadSlice();
    __is->endReadSlice();
#if defined(_MSC_VER) && (_MSC_VER < 1300) // VC++ 6 compiler bug
    Object::__read(__is, true);
#else
    ::Ice::Object::__read(__is, true);
#endif
}

void
Tartarus::iface::SysDB::GroupManager::__write(const ::Ice::OutputStreamPtr&) const
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::GroupManager was not generated with stream support";
    throw ex;
}

void
Tartarus::iface::SysDB::GroupManager::__read(const ::Ice::InputStreamPtr&, bool)
{
    Ice::MarshalException ex(__FILE__, __LINE__);
    ex.reason = "type Tartarus::iface::SysDB::GroupManager was not generated with stream support";
    throw ex;
}

void 
Tartarus::iface::SysDB::__patch__GroupManagerPtr(void* __addr, ::Ice::ObjectPtr& v)
{
    ::Tartarus::iface::SysDB::GroupManagerPtr* p = static_cast< ::Tartarus::iface::SysDB::GroupManagerPtr*>(__addr);
    assert(p);
    *p = ::Tartarus::iface::SysDB::GroupManagerPtr::dynamicCast(v);
    if(v && !*p)
    {
        ::Ice::UnexpectedObjectException e(__FILE__, __LINE__);
        e.type = v->ice_id();
        e.expectedType = ::Tartarus::iface::SysDB::GroupManager::ice_staticId();
        throw e;
    }
}

bool
Tartarus::iface::SysDB::operator==(const ::Tartarus::iface::SysDB::GroupManager& l, const ::Tartarus::iface::SysDB::GroupManager& r)
{
    return static_cast<const ::Ice::Object&>(l) == static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator!=(const ::Tartarus::iface::SysDB::GroupManager& l, const ::Tartarus::iface::SysDB::GroupManager& r)
{
    return static_cast<const ::Ice::Object&>(l) != static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<(const ::Tartarus::iface::SysDB::GroupManager& l, const ::Tartarus::iface::SysDB::GroupManager& r)
{
    return static_cast<const ::Ice::Object&>(l) < static_cast<const ::Ice::Object&>(r);
}

bool
Tartarus::iface::SysDB::operator<=(const ::Tartarus::iface::SysDB::GroupManager& l, const ::Tartarus::iface::SysDB::GroupManager& r)
{
    return l < r || l == r;
}

bool
Tartarus::iface::SysDB::operator>(const ::Tartarus::iface::SysDB::GroupManager& l, const ::Tartarus::iface::SysDB::GroupManager& r)
{
    return !(l < r) && !(l == r);
}

bool
Tartarus::iface::SysDB::operator>=(const ::Tartarus::iface::SysDB::GroupManager& l, const ::Tartarus::iface::SysDB::GroupManager& r)
{
    return !(l < r);
}
