#include <Config.h>
#include <Debug.h>

#include <stdexcept>
#include <iostream>
#include <memory>
#include <boost/shared_ptr.hpp>

#include "SysDBClient.h"
#include "ServerDBUS.h"
#include "Signal.h"
//#include "Prepare.h"

using namespace Tartarus;

static const char* SERVER_NAME = TARTARUS_NSS_SERVER_NAME;
static const char* SERVER_PATH = TARTARUS_NSS_SERVER_PATH;
static const char* PEER_TO_PEER_PATH = TARTARUS_NSS_PEER_TO_PEER_PATH;
//static const char* PEER_TO_PEER_PATH = "unix:path=/tmp/tnscd_bus";

class Server: public DBus::Server
{
    typedef boost::shared_ptr<ServerDBUS> ServerDBUSPtr;
    typedef std::list<ServerDBUSPtr> ObjectList;

public:
    Server(const char* address): DBus::Server(address){}

    void clean_objects() {
//        std::cerr<<"clean_objects: " << objects.size() <<std::endl;
        for(ObjectList::iterator i = objects.begin(); i != objects.end();) {
            ObjectList::iterator n = i++;
            if (!(*n)->conn().connected())
                objects.erase(n);
        }
    }

protected:
    virtual void on_new_connection(DBus::Connection& c)
    {
//        std::cerr<<"on_new_connection: " << objects.size() <<std::endl;
        objects.push_back(ServerDBUSPtr(new ServerDBUS(c, SERVER_PATH)));
    }
//    virtual bool on_user_auth(unsigned long uid) {}

private:
    ObjectList objects;
};

class Termination
{
public:
    static void init(DBus::BusDispatcher &disp)
    {
        DBus::default_dispatcher = &disp;

        BlockSignals(false, SIGINT);
        BlockSignals(false, SIGQUIT);
        BlockSignals(false, SIGTERM);
        BlockSignals(false, SIGHUP);
        BlockSignals(false, SIGUSR1);

        CatchSignal(SIGINT, Termination::handler);
        CatchSignal(SIGQUIT, Termination::handler);
        CatchSignal(SIGTERM, Termination::handler);
        CatchSignal(SIGPIPE, SIG_IGN);
        CatchSignal(SIGUSR1, Termination::reinit);

        DBus::_init_threading();
    }

    static void handler(int signum)
    {
        if (DBus::default_dispatcher)
            DBus::default_dispatcher->leave();
//        std::cerr<<"handler "<<signum<<std::endl;
    }
    static void reinit(int signum)
    {
        setReaderReInit();
//        std::cerr<<"handler "<<signum<<std::endl;
    }
};

int main()
{
    int error_code = 0;

    try {
        DBus::BusDispatcher dispatcher;
        Termination::init(dispatcher);

        DBus::Connection conn = DBus::Connection::SystemBus();

        conn.request_name(SERVER_NAME);
        ServerDBUS iface(conn, SERVER_PATH);

//        {
//            Umask m;
//            s.init();
//        }
        Server server(PEER_TO_PEER_PATH);
        server.enable_anon(true);

//        dispatcher.enter();
        dispatcher.run();
        int i=0;
        do {
//            std::cerr<<"do interation "<<++i<<std::endl;
            try {
                dispatcher.do_iteration();
            }
            catch(DBus::Error error)
            {
                std::cerr << error;
            }
//            std::cerr<<"interation done"<<std::endl;
            server.clean_objects();
        } while (dispatcher.is_running());
//        std::cerr<<"interation end("<<dispatcher.is_running()<<")"<<std::endl;

    } catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
        error_code = 1;
    }

    return error_code;
}
