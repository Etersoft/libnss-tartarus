#ifndef Tartarus_RPC_h
#define Tartarus_RPC_h

#include <string>
#include <stdexcept>
#include <map>

#include "json_spirit/json_spirit.h"
#include <boost/asio.hpp>

namespace Tartarus { namespace RPC {

class RPCError: public std::runtime_error
{
    public:
        RPCError(const std::string & what): std::runtime_error(what)
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
        typedef boost::asio::ip::tcp::socket socket;
        Server(int port): acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
        {
        }
        void async_accept();
        void handler(const boost::system::error_code& error);
        void run();
    private:
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::acceptor acceptor;
        boost::shared_ptr<socket> s;
};

class Connection
{
    public:
        Connection(int port);
        json_spirit::Value call(const std::string & object, const std::string & method, const json_spirit::Value & params);
    private:
        boost::asio::io_service io_service;
        boost::asio::ip::tcp::socket socket;
};

class ObjectPrx
{
    public:
        ObjectPrx(const std::string & name, Connection & connection):
            _name(name), _connection(connection)
        {}
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
