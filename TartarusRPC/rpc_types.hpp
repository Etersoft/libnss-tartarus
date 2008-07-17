#ifndef TARTARUS_RPC_TYPES
#define TARTARUS_RPC_TYPES

#include <json_spirit/json_spirit.h>

struct UserRecord
{
    int uid;
    std::string name;
    UserRecord(const UserRecord & u): uid(u.uid), name(u.name)
    {
    }
    UserRecord(int uid, const std::string & name):
	uid(uid), name(name)
    {
    }
    UserRecord(const json_spirit::Value & v)
    {
	const json_spirit::Object & o = v.get_obj();
	for(json_spirit::Object::const_iterator i = o.begin(); i != o.end(); ++i)
	{
	    if(i->name_ == "uid")
		uid = i->value_.get_int();
	    else if (i->name_ == "name")
		name = i->value_.get_str();
	}
    }
    json_spirit::Value toValue()
    {
	json_spirit::Object o;
	o.push_back(json_spirit::Pair("uid", uid));
	o.push_back(json_spirit::Pair("name", name));
	return o;
    }
};

#endif /* TARTARUS_RPC_TYPES */
