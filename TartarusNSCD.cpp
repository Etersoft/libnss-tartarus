#include <Ice/Service.h>
#include <Ice/LoggerUtil.h>

#include <Ice/Ice.h>
#include <SysDBI.h>
#include <TartarusNSCDInit.h>
#include <TartarusNSCDKinit.h>

#include <iostream>

namespace SysDB = Tartarus::iface::SysDB;

class TatarusNSCD: public Ice::Service
{
public:
	TatarusNSCD() {}

protected:
	virtual bool start(int, char*[]);

private:
	Ice::ObjectAdapterPtr adapter;

	TatarusNSCD(const TatarusNSCD&);
	const TatarusNSCD& operator=(const TatarusNSCD&); 
};


bool
TatarusNSCD::start(int argc, char* argv[])
{
	try
	{
		Ice::Identity identity;
		Ice::ObjectPtr reader;

		adapter = communicator()->createObjectAdapter("TartarusNSCD");

		identity = communicator()->stringToIdentity("UserReader");
		reader = new SysDB::UserReaderI();
		adapter->add(reader, identity);

		identity = communicator()->stringToIdentity("GroupReader");
		reader = new SysDB::GroupReaderI();
		adapter->add(reader, identity);

		adapter->activate();
	}
	catch (Ice::Exception& ex)
	{
		Ice::Error err(communicator()->getLogger());
		err << "Ice Exception: " << ex;
		return false;
	}
	catch (std::exception& ex)
	{
		Ice::Error err(communicator()->getLogger());
		err << "Exception: " << ex.what();
		return false;
	}
	catch (...)
	{
		Ice::Error err(communicator()->getLogger());
		err << "Unknown exception.";
		return false;
	}

	return true;
}

int main(int argc, char* argv[])
{
	TatarusNSCD svc;

	Ice::InitializationData &init = Tartarus::NSCDInitialize();
	Tartarus::NSCDKinit();

	return svc.main(argc,argv,init);
}
