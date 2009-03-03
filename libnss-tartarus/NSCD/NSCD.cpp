#include <Config.h>
#include <Debug.h>

#include <stdexcept>
#include <iostream>

#include "ServerDBUS.h"
#include "Signal.h"
//#include "Prepare.h"

using namespace Tartarus;

static const char* SERVER_NAME = TARTARUS_NSS_SERVER_NAME;
static const char* SERVER_PATH = TARTARUS_NSS_SERVER_PATH;
//static const char* PEER_TO_PEER_PATH = "unix:/var/run/tnscd/pipe";

static DBus::BusDispatcher dispatcher;

static void termination_handler(int signum)
{
    dispatcher.leave();
}

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
        DBus::Connection conn = DBus::Connection::SystemBus();
        conn.request_name(SERVER_NAME);

        ServerDBUS server(conn, SERVER_PATH);

//        {
//            Umask m;
//            s.init();
//        }

        do {
            dispatcher.do_iteration();
        } while (conn.connected());

    } catch (const std::exception &error)
    {
        std::cerr << error.what() << std::endl;
        error_code = 1;
    }

    return error_code;
}
