
#include <Kinit.h>

#include <krb5user.h>

namespace Tartarus {

void NSCDKinit(const char *princname, const char* ktname, const char* ccname)
{
	krb5user_error_code e = 0;
	const char* what = 0;

	try {
		e = krb5user_set_ccname(ccname, &what);
		if (e)
			throw e;

		e = krb5user_kinit_keytab(princname, 0, ktname, 0, &what);
		if (e)
			throw e;

	} catch (krb5user_error_code e) {
		std::string err(krb5user_error_message(e));
		err += std::string(": ") + what;
		throw (std::runtime_error(err));
	}
}

}
