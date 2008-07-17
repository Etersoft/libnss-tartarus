#include <rpc.hpp>
#include <rpc_types.hpp>
#include <debug.hpp>

class UserReader: public Tartarus::RPC::Object
{
    public:
        json_spirit::Value call(const std::string & method, const json_spirit::Array & params)
        {
            if(method == "getUsers")
            {
                int gid = params[0].get_int();
                std::vector<int> v = getUsers(params[0].get_int());
                json_spirit::Array ret;
                for(std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i)
                {
                    ret.push_back(*i);
                }
                return ret;
            } else if(method == "getUser")
            {
        	debug("jopa1");
                const int uid = params[0].get_int();
                UserRecord user(getUser(uid));
                debug("jopa2");
                return user.toValue();
            } else
            {
                std::ostringstream oss;
                oss << "UserReader object has not " << method << " method";
                throw Tartarus::RPC::RPCError(oss.str());
            }
        }

        virtual std::vector<int> getUsers(int gid) = 0;
        virtual UserRecord getUser(int uid) = 0;
};

class UserReaderI: public UserReader
{
    std::vector<int> getUsers(int gid)
    {
        std::vector<int> ret;
        ret.push_back(1);
        ret.push_back(2);
        ret.push_back(3);
        return ret;
    }
    UserRecord getUser(int uid)
    {
	return UserRecord(uid, "rlz");
    }
};

int main()
{
    Tartarus::RPC::Server s(1111);
    Tartarus::RPC::ObjectPtr ur(new UserReaderI());
    Tartarus::RPC::Functions::get().add_object("UserReader", ur);
    s.async_accept();
    s.run();
    return 0;
}
