
#include <TartarusNSCDKinit.h>

#include <string>
#include <stdexcept>

extern "C"
{
#include <krb5.h>
#include <et/com_err.h>
}

namespace Tartarus {

krb5_error_code
kinit_keytab(const char* princname, const char* ktname, const char* ccname, char** what)
{
    char *dummy = 0;
    if (!what)
        what = &dummy;

    krb5_error_code e = 0;
    krb5_context ctx = 0;
    krb5_keytab kt = 0;
    krb5_principal princ = 0;
    krb5_get_init_creds_opt *options = 0;
    krb5_ccache cc = 0;
    krb5_creds creds;

    memset(&creds, 0, sizeof(creds));

    *what = "initializing context";
    e = krb5_init_context(&ctx);
    if (e != 0) return e;

    if (ktname)
    {
        *what = "resolving keytab";
        e = krb5_kt_resolve(ctx, ktname, &kt);
        if (e != 0) goto out1;
    }

    *what = "parsing principal name";
    e = krb5_parse_name(ctx, princname, &princ);
    if (e != 0) goto out2;

    *what = "initalizing options structure";
    e = krb5_get_init_creds_opt_alloc(ctx, &options);
    if (e != 0) goto out3;

    //forwardable:
    //krb5_get_init_creds_opt_set_forwardable(options, 1);

    *what = "getting credentials";
    e = krb5_get_init_creds_keytab(ctx, &creds, princ, kt,
            0, //starttime
            0, //service name
            options);
    if (e != 0) goto out4;

    if (ccname)
    {
        *what = "locating credential cache";
        e = krb5_cc_resolve(ctx, ccname, &cc);
    }
    else
    {
        *what = "locating default credential cache";
        e = krb5_cc_default(ctx, &cc);
    }
    if (e != 0) goto out5;


    *what = "initializing credential cache";
    e = krb5_cc_initialize(ctx, cc, princ);
    if (e != 0) goto out6;

    *what = "storing credentials in cache";
    e = krb5_cc_store_cred(ctx, cc, &creds);
    if (e != 0) goto out6;

    *what = "OK";

out6:
    if (cc)
        krb5_cc_close(ctx, cc);

out5:
    //avoid freeing principal twice
    if (creds.client == princ)
        creds.client = 0;
    krb5_free_cred_contents(ctx, &creds);

out4:
    if (options)
        krb5_get_init_creds_opt_free(ctx, options);

out3:
    if (princ)
        krb5_free_principal(ctx, princ);

out2:
    if (kt)
        krb5_kt_close(ctx, kt);

out1:
    if (ctx)
        krb5_free_context(ctx);
    return e; // ok
}

void NSCDKinit(const char *princname, const char* ktname, const char* ccname)
{
    char* what = 0;
    krb5_error_code e = 0;

    e = kinit_keytab(princname, ktname, ccname, &what);
    if (e != 0)
    {
        std::string err(error_message(e));
        err += std::string(": ") + what;
        throw (std::runtime_error(err));
    }
}

}
