#include <Config.h>
#include <Debug.h>

#include <stdexcept>
#include <iostream>
#include <memory>
//#include <pthread.h>

#include "ServerDBUS.h"
#include "Signal.h"
//#include "Prepare.h"

using namespace Tartarus;

static const char* SERVER_NAME = TARTARUS_NSS_SERVER_NAME;
static const char* SERVER_PATH = TARTARUS_NSS_SERVER_PATH;
//static const char* PEER_TO_PEER_PATH = "unix:/var/run/tnscd/pipe";
static const char* PEER_TO_PEER_PATH = "unix:path=tnscd_bus";

static bool running = true;
static DBus::BusDispatcher dispatcher;

static void termination_handler(int signum)
{
    dispatcher.leave();
    running = false;
}

//void* connection_thread (void* x)
//{
//}

class Server: public DBus::Server
{
public:
    Server(const char* address): DBus::Server(address){}

protected:
    virtual void on_new_connection(DBus::Connection& c)
    {
        std::cerr << "on_new_connection" << std::endl;
        ServerDBUS *x = new ServerDBUS(c, SERVER_PATH);
//        DBus::ObjectAdaptor *o = new DBus::ObjectAdaptor(c, SERVER_PATH);
        std::cerr << "on_new_connection end" << std::endl;
    }
};

int main()
{
    int error_code = 0;

    BlockSignals(false, SIGINT);
    BlockSignals(false, SIGQUIT);
    BlockSignals(false, SIGTERM);
    BlockSignals(false, SIGHUP);

    CatchSignal(SIGINT, termination_handler);
    CatchSignal(SIGQUIT, termination_handler);
    CatchSignal(SIGTERM, termination_handler);
    CatchSignal(SIGPIPE, SIG_IGN);

    try {
//        CheckDirectories();

        DBus::default_dispatcher = &dispatcher;

//        DBus::Connection conn = DBus::Connection::SessionBus();
//        DBus::Connection conn = DBus::Connection::SystemBus();
//        DBus::Connection conn = DBus::Connection(PEER_TO_PEER_PATH);
//        conn.register_bus();
//        conn.request_name(SERVER_NAME);

//        ServerDBUS server(conn, SERVER_PATH);

//        {
//            Umask m;
//            s.init();
//        }
        Server server(PEER_TO_PEER_PATH);

        dispatcher.enter();
//        do {
//            dispatcher.do_iteration();
//        } while (dispatcher.is_running() && conn.connected());


    } catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
        error_code = 1;
    }

    return error_code;
}
