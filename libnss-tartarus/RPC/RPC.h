#ifndef Tartarus_RPC_h
#define Tartarus_RPC_h

#include <string>
#include <stdexcept>
#include <map>

#include <json_spirit/json_spirit.h>
#include <boost/asio.hpp>

#include "Config.h"

namespace Tartarus { namespace RPC {

class RPCError: public std::runtime_error
{
    public:
        explicit RPCError(const std::string & what): std::runtime_error(what)
        {}
};

class SystemError: public std::runtime_error
{
    public:
        explicit SystemError(const std::string & what): std::runtime_error(what)
        {}
};

class Object
{
    public:
        virtual json_spirit::Value call(const std::string & method, const json_spirit::Array & params) = 0;
        virtual ~Object(){};
};

typedef boost::shared_ptr<Object> ObjectPtr;

class Functions
{
    private:
        typedef std::map<std::string, ObjectPtr> callers_type;
    public:
        static Functions & get();
        void add_object(const std::string & name, const ObjectPtr & obj);
        json_spirit::Value call(const std::string & object, const std::string & method, const json_spirit::Array & params);
    private:
        Functions()
        {}
        callers_type callers;
};

class Server
{
    public:
        typedef boost::asio::local::stream_protocol::socket socket;
        typedef boost::asio::local::stream_protocol::acceptor acceptor;
        typedef boost::asio::local::stream_protocol::endpoint endpoint;

        Server(const std::string & socket_name): sock_name (socket_name)
        {}
        void init();
        void run();
        void stop();

    private:
        void async_accept();
        void handler(const boost::system::error_code& error);

        std::string sock_name;
        boost::asio::io_service io_service;
        boost::shared_ptr<acceptor> a;
        boost::shared_ptr<socket> s;
};

class Connection
{
    public:
        Connection(const std::string & socket_name);
        json_spirit::Value call(const std::string & object, const std::string & method, const json_spirit::Value & params);
    private:
        boost::asio::io_service io_service;
        boost::asio::local::stream_protocol::socket socket;
};

class ObjectPrx
{
    public:
        ObjectPrx(const std::string & name, Connection & connection):
            _name(name), _connection(connection)
        {}
/*        ObjectPrx(const ObjectPrx & prx):
            _name(prx._name), _connection(prx._connection)
        {}*/
        const std::string & name() const
        {
            return _name;
        }
        Connection & connection()
        {
            return _connection;
        }
    private:
        std::string _name;
        Connection & _connection;
};

}; };

#endif /* TARTARUS_RPC_RPC */
