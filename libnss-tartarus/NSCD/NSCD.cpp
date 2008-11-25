#include <RPC/RPC.h>
#include <debug.h>
#include "RPCTypes.h"

#include <stdexcept>
#include <iostream>

#include "ServerI.h"
#include "Signal.h"
#include "Prepare.h"


using namespace Tartarus;

static RPC::Server s(NSS_TARTARUS_SOCKET_PATH);

static void termination_handler(int signum)
{
        s.stop();
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
                CheckDirectories();

                RPC::ObjectPtr ur(new Tartarus::UserReaderI());
                RPC::Functions::get().add_object("UserReader", ur);
                RPC::ObjectPtr gr(new Tartarus::GroupReaderI());
                RPC::Functions::get().add_object("GroupReader", gr);

                {
                    Umask m;
                    s.init();
                }

                s.run();
        } catch (const std::exception &error)
        {
                std::cerr << error.what() << std::endl;
                error_code = 1;
        }

        return error_code;
}
