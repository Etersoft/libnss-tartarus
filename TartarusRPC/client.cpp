#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/asio/read_until.hpp>
#include <json_spirit/json_spirit.h>

#include "debug.hpp"
#include "rpc.hpp"

namespace Tartarus { namespace RPC {

Connection::Connection(int port): socket(io_service)
{
    std::ostringstream oss;
    oss << port;
    boost::asio::ip::tcp::resolver resolver(io_service);
    boost::asio::ip::tcp::resolver::query query("localhost", oss.str());
    
    boost::asio::ip::tcp::resolver::iterator i = resolver.resolve(query);
    boost::asio::ip::tcp::resolver::iterator end;
    boost::system::error_code error = boost::asio::error::host_not_found;
    while (error && i != end)
    {
        socket.close();
        socket.connect(*i++, error);
    }
    if (error)
        throw boost::system::system_error(error);
}

json_spirit::Value Connection::call(const std::string & object, const std::string & method, const json_spirit::Value & params)
{
    json_spirit::Object o;
    o.push_back(json_spirit::Pair("object", object));
    o.push_back(json_spirit::Pair("method", method));
    o.push_back(json_spirit::Pair("params", params));

    std::string buf = json_spirit::write(o);
    buf.push_back('\0');
    boost::asio::write(socket, boost::asio::buffer(buf), boost::asio::transfer_all());
    boost::asio::streambuf recv_buf;
    boost::asio::read_until(socket, recv_buf, '\0');
    std::istream in(&recv_buf);
    std::string str;
    std::getline(in, str, '\0');
    json_spirit::Value res;
    if(!json_spirit::read(str, res))
    {
        throw RPCError("Wrong reply");
    } else
    {
        const json_spirit::Array & a = res.get_array();
        if(a[0].get_int())
            return a[1];
        else
            throw RPCError(a[1].get_str());
    }
}

}; };
