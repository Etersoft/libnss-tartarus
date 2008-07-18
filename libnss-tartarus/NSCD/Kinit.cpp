
#include <Kinit.h>

#include <string>
#include <stdexcept>
#include <cstring>

#include <errno.h>
#include <sys/socket.h>
#include <netdb.h>

extern "C"
{
#include <krb5.h>
#include <et/com_err.h>
}

namespace Tartarus {

#ifndef AI_CANONIDN
#define FQDN_R_AI_FLAGS (AI_CANONNAME)
#else
#define FQDN_R_AI_FLAGS (AI_CANONNAME | AI_CANONIDN)
#endif

static int fqdn_r(char* buf, int len)
{
    char data[HOST_NAME_MAX + 1];
    struct addrinfo hints;
    struct addrinfo *result = 0;
    char* x = 0;
    int l = 0, e = 0;

    std::memset(&hints, 0, sizeof(struct addrinfo));

    e = gethostname(data, HOST_NAME_MAX + 1);
    if (e < 0) return EAI_SYSTEM;

    data[HOST_NAME_MAX] = 0;

    hints.ai_flags = FQDN_R_AI_FLAGS;
    hints.ai_family = AF_INET;

    e = getaddrinfo(data, 0, &hints, &result);
    if (e != 0) return e;

    x = result->ai_canonname;
    l = std::strlen(x);
    if (l > len)
    {
        errno = EINVAL;
        return EAI_SYSTEM;
    }
    std::strncpy(buf, x, len);

    freeaddrinfo(result);

    return 0;
}

static krb5_error_code
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
    char host[HOST_NAME_MAX+1];
    krb5_error_code e = 0;
    char* what = 0;
    int ret;

    ret = fqdn_r(host, HOST_NAME_MAX);
    if (ret) {
        std::string err("getting host name: ");
        err += std::strerror(errno);
        throw (std::runtime_error(err));
    }

    if (ccname && setenv("KRB5CCNAME", ccname, 1) != 0)
        throw (std::runtime_error("can't set KRB5CCNAME"));

    std::string princ(princname);
    princ += std::string("/") + host;
    ret = kinit_keytab(princ.c_str(), ktname, ccname, &what);
    if (ret) {
        std::string err(error_message(e));
        err += std::string(": ") + what;
        throw (std::runtime_error(err));
    }
}

}
