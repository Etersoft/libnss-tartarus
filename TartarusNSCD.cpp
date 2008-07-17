#include <TartarusRPC.h>
#include <TartarusDebug.h>
#include <TartarusRPCTypes.h>

#include <TartarusServerI.h>
#include <TartarusNSCDInit.h>
#include <TartarusNSCDKinit.h>

int main()
{
    Ice::InitializationData &init = Tartarus::NSCDInitialize();
    Tartarus::NSCDKinit();

    Tartarus::RPC::Server s(12346);
    Tartarus::RPC::ObjectPtr ur(new Tartarus::UserReaderI());
    Tartarus::RPC::Functions::get().add_object("UserReader", ur);
    Tartarus::RPC::ObjectPtr gr(new Tartarus::GroupReaderI());
    Tartarus::RPC::Functions::get().add_object("GroupReader", gr);
    s.async_accept();
    s.run();

    return 0;
}

/*int main(int argc, char* argv[])
{
	TatarusNSCD svc;

	Ice::InitializationData &init = Tartarus::NSCDInitialize();
	Tartarus::NSCDKinit();

	return svc.main(argc,argv,init);
}*/
