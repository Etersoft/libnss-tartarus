#ifndef Tartarus_RPC_Types_h
#define Tartarus_RPC_Types_h

#include <json_spirit/json_spirit.h>

#include <grp.h>
#include <pwd.h>

namespace Tartarus {

struct UserRecord
{
    uid_t uid;
    gid_t gid;
    std::string name;
    std::string gecos;
    std::string home;
    std::string shell;
    std::string passwd;

    UserRecord(const UserRecord & u):
        uid(u.uid), gid(u.gid), name(u.name), gecos(u.gecos), home(u.home), shell(u.shell), passwd(u.passwd) {}
    UserRecord(uid_t uid, gid_t gid, const std::string &name, const std::string &gecos, const std::string &home,
               const std::string &shell = "/bin/bash", const std::string &passwd = "x"):
        uid(uid), gid(gid), name(name), gecos(gecos), home(home), shell(shell), passwd(passwd) {}
    UserRecord(const json_spirit::Value & v)
    {
        const json_spirit::Object & o = v.get_obj();
        for(json_spirit::Object::const_iterator i = o.begin(); i != o.end(); ++i)
        {
            if(i->name_ == "uid")
                uid = i->value_.get_int();
            else if (i->name_ == "gid")
                gid = i->value_.get_int();
            else if (i->name_ == "name")
                name = i->value_.get_str();
            else if (i->name_ == "gecos")
                gecos = i->value_.get_str();
            else if (i->name_ == "home")
                home = i->value_.get_str();
            else if (i->name_ == "shell")
                shell = i->value_.get_str();
            else if (i->name_ == "passwd")
                passwd = i->value_.get_str();
        }
    }
    json_spirit::Value toValue()
    {
        json_spirit::Object o;
        o.push_back(json_spirit::Pair("uid", (int) uid));
        o.push_back(json_spirit::Pair("gid", (int) gid));
        o.push_back(json_spirit::Pair("name", name));
        o.push_back(json_spirit::Pair("gecos", gecos));
        o.push_back(json_spirit::Pair("home", home));
        o.push_back(json_spirit::Pair("shell", shell));
        o.push_back(json_spirit::Pair("passwd", passwd));
        return o;
    }
};

struct GroupRecord
{
    gid_t gid;
    std::string name;
    std::string passwd;

    GroupRecord(const GroupRecord & g):
        gid(g.gid), name(g.name), passwd(g.passwd) {}
    GroupRecord(gid_t gid, const std::string &name, const std::string &passwd = "x"):
        gid(gid), name(name), passwd(passwd) {}
    GroupRecord(const json_spirit::Value & v)
    {
        const json_spirit::Object & o = v.get_obj();
        for(json_spirit::Object::const_iterator i = o.begin(); i != o.end(); ++i)
        {
            if(i->name_ == "gid")
                gid = i->value_.get_int();
            else if (i->name_ == "name")
                name = i->value_.get_str();
            else if (i->name_ == "passwd")
                passwd = i->value_.get_str();
        }
    }
    json_spirit::Value toValue()
    {
        json_spirit::Object o;
        o.push_back(json_spirit::Pair("gid", (int) gid));
        o.push_back(json_spirit::Pair("name", name));
        o.push_back(json_spirit::Pair("passwd", passwd));
        return o;
    }
};

}

#endif /* TARTARUS_RPC_TYPES */
