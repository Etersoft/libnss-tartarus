#include <RPC/RPC.h>
#include <debug.h>
#include "RPCTypes.h"

#include <stdexcept>
#include <iostream>

#include "ServerI.h"
#include "Kinit.h"

int main()
{
        try {
                Tartarus::NSCDKinit();

                Tartarus::RPC::Server s(12346);
                Tartarus::RPC::ObjectPtr ur(new Tartarus::UserReaderI());
                Tartarus::RPC::Functions::get().add_object("UserReader", ur);
                Tartarus::RPC::ObjectPtr gr(new Tartarus::GroupReaderI());
                Tartarus::RPC::Functions::get().add_object("GroupReader", gr);
                s.async_accept();

                s.run();
        } catch (const std::exception &error)
        {
                std::cerr << error.what() << std::endl;
        }

        return 0;
}
