
#include <Kinit.h>

#include <krb5user.h>

namespace Tartarus {

void NSCDKinit(const char *princname, const char* ktname, const char* ccname)
{
	krb5user_error_code e = 0;
	char* what = 0;

//    if (ccname && setenv("KRB5CCNAME", ccname, 1) != 0)
//        throw (std::runtime_error("can't set KRB5CCNAME"));

	e = krb5user_kinit_keytab(princname, 0, ktname, ccname, &what);
	if (e) {
		std::string err(krb5user_error_message(e));
		err += std::string(": ") + what;
		throw (std::runtime_error(err));
	}
}

}
