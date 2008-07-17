#include <rpc.hpp>
#include <rpc_types.hpp>

class UserReaderPrx: public Tartarus::RPC::ObjectPrx
{
    public:
        UserReaderPrx(const std::string & name, Tartarus::RPC::Connection & connection):
            ObjectPrx(name, connection)
        {
        }
        std::vector<int> getUsers(int gid)
        {
            json_spirit::Array params;
            params.push_back(gid);
            json_spirit::Value result(connection().call(name(), "getUsers", params));
            const json_spirit::Array & a = result.get_array();
            std::vector<int> ret;
            ret.reserve(a.size());
            for(json_spirit::Array::const_iterator i = a.begin(); i != a.end(); ++i)
            {
                    ret.push_back(i->get_int());
            }
            return ret;
        }
        UserRecord getUser(int uid)
        {
	    json_spirit::Array params;
	    params.push_back(uid);
	    return connection().call(name(), "getUser", params);
        }
};

int main(int argc, char ** argv)
{
    Tartarus::RPC::Connection con(1111);
    UserReaderPrx ur("UserReader", con);
/*    std::vector<int> users = ur.getUsers(10);
    for(std::vector<int>::const_iterator i = users.begin(); i != users.end(); ++i)
    {
        std::cout << *i << ' ';
    }
    std::cout << std::endl; */
    UserRecord user = ur.getUser(3);
    std::cout << user.name << ' ' << user.uid << std::endl;
    return 0;
}
