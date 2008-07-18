#include <RPC/RPC.h>
#include <debug.h>
#include "RPCTypes.h"

#include "ServerI.h"
#include "Init.h"
#include "Kinit.h"

int main()
{
//    Ice::InitializationData &init = Tartarus::NSCDInitialize();
//    Tartarus::NSCDKinit();

    Tartarus::RPC::Server s(12346);
    Tartarus::RPC::ObjectPtr ur(new Tartarus::UserReaderI());
    Tartarus::RPC::Functions::get().add_object("UserReader", ur);
    Tartarus::RPC::ObjectPtr gr(new Tartarus::GroupReaderI());
    Tartarus::RPC::Functions::get().add_object("GroupReader", gr);
    s.async_accept();
    s.run();

    return 0;
}
