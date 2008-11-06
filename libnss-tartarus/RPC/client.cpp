#include <iostream>
#include <string>

#include <boost/asio.hpp>
#include <boost/asio/read_until.hpp>
#include <json_spirit/json_spirit.h>

#include <debug.h>
#include "RPC.h"

namespace Tartarus { namespace RPC {

Connection::Connection(const std::string & socket_name): socket(io_service)
{
    boost::system::error_code error;
    socket.connect(socket_name, error);
    if (error)
        throw boost::system::system_error(error);
}

json_spirit::Value Connection::call(const std::string & object, const std::string & method, const json_spirit::Value & params)
{
    json_spirit::Object o;
    o.push_back(json_spirit::Pair("object", object));
    o.push_back(json_spirit::Pair("method", method));
    o.push_back(json_spirit::Pair("params", params));

    debug("Connection::call write");

    std::string buf = json_spirit::write(o);
    debug("Connection::call buf.push_back");
    debug(buf.c_str());
    debug("Connection::call buf.push_back!");
    buf.push_back('\0');
    debug("Connection::call boost::asio::write");
    boost::asio::write(socket, boost::asio::buffer(buf), boost::asio::transfer_all());
    debug("Connection::call boost::asio::streambuf");
    boost::asio::streambuf recv_buf;
    debug("Connection::call boost::asio::read_until");
    boost::asio::read_until(socket, recv_buf, '\0');

    debug("Connection::call get recv");

    std::istream in(&recv_buf);
    std::string str;
    std::getline(in, str, '\0');
    json_spirit::Value res;

    debug("Connection::call read json");

    if(!json_spirit::read(str, res))
    {
        throw RPCError("Wrong reply");
    } else
    {
        debug("Connection::call get array");
        const json_spirit::Array & a = res.get_array();
        if(a[0].get_int())
            return a[1];
        else
            throw RPCError(a[1].get_str());
    }
}

}; };
