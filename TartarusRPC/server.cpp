#include <iostream>
#include <string>
//#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/read_until.hpp>
#include <json_spirit/json_spirit.h>

#include "debug.hpp"
#include "rpc.hpp"

namespace Tartarus { namespace RPC {

Functions & Functions::get()
{
    static Functions * instance;
    if(!instance)
        instance = new Functions();
    return *instance;
}

void Functions::add_object(const std::string & name, const ObjectPtr & instance)
{
    callers[name] = instance;
}

json_spirit::Value Functions::call(const std::string & object,
                                   const std::string & method,
                                   const json_spirit::Array & params)
{
    callers_type::const_iterator i(callers.find(object));
    if(i != callers.end())
    {
        return i->second->call(method, params);
    } else
    {
        std::ostringstream oss;
        oss << "Object " << object << " not found";
        throw RPCError(oss.str());
    }
}

class Caller
{
    public:
        Caller(const json_spirit::Value & v)
        {
            const json_spirit::Object & o = v.get_obj();
            for(json_spirit::Object::const_iterator i = o.begin(); i != o.end(); ++i)
            {
                if(i->name_ == "object")
                {
                    object = i->value_.get_str();
                } else if(i->name_ == "method")
                {
                    method = i->value_.get_str();
                } else if(i->name_ == "params")
                {
                    params = i->value_.get_array();
                }
            }
        }
        json_spirit::Value call()
        {
            return Functions::get().call(object, method, params);
        }
    private:
        std::string object, method;
        json_spirit::Array params;
};

template <typename T>
class Client
{
    public:
        static Client<T> * create(const boost::shared_ptr<T> & socket)
        {
            return new Client<T>(socket);
        }
        void async_read()
        {
            if(buf)
                delete buf;
            buf = new boost::asio::streambuf();
            boost::asio::async_read_until(*socket, *buf, '\0', boost::bind(&Client::handler, this, _1, _2));
        }
        void handler(const boost::system::error_code& error, std::size_t bytes_transferred)
        {
            if(error)
            {
                delete this;
            } else
            {
                debug("Message received");
                std::iostream in(buf);
                std::string str;
                std::getline(in, str, '\0');
                debug(va("Message: %s", str.c_str()));
                json_spirit::Value v;
                if(json_spirit::read(str, v))
                {
                    try
                    {
                        json_spirit::Array a;
                        a.push_back(1);
                        a.push_back(Caller(v).call());
                        std::string str = json_spirit::write(a);
                        debug(va("Reply: %s", str.c_str()));
                        str.push_back('\0');
                        boost::asio::write(*socket, boost::asio::buffer(str));
                    } catch(const std::exception & exc)
                    {
                        std::string what = exc.what();
                        std::cerr << "Error while call function; what: " << what << std::endl;
                        json_spirit::Array a;
                        a.push_back(0);
                        a.push_back(what);
                        boost::asio::write(*socket, boost::asio::buffer(json_spirit::write(a)));
                    }
                    async_read();
                } else
                {
                    delete this;
                }
            }
        }
        ~Client()
        {
            if(buf)
                delete buf;
            debug("Client destroied");
        }
    private:
        Client(const boost::shared_ptr<T> & socket): socket(socket), buf(0), stop(false)
        {}
        boost::shared_ptr<T> socket;
        boost::asio::streambuf * buf;
        bool stop;
};

void Server::async_accept()
{
    s.reset(new socket(io_service));
    acceptor.async_accept(*s, boost::bind(&Server::handler, this, _1));
}

void Server::handler(const boost::system::error_code& error)
{
    debug("Client connected");
    Client<socket> * c = Client<socket>::create(s);
    debug(va("Client: %p", c));
    debug("Client created");
    c->async_read();
    debug("Read requested");
    async_accept();
    debug("Accept requested");
}

void Server::run()
{
    io_service.run();
}

}; };
