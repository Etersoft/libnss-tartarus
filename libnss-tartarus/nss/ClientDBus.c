#include <Config.h>
#include <Debug.h>
#include "ClientDBus.h"

#include <dbus/dbus.h>

#include <pthread.h>

#include <stdbool.h>
#include <stdlib.h>
#include <errno.h>

static const char* SERVER_NAME = TARTARUS_NSS_SERVER_NAME;
static const char* SERVER_PATH = TARTARUS_NSS_SERVER_PATH;

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static DBusConnection* connection = NULL;

nss_status client_dbus_init(void)
{
    DBusError err;
    nss_status ret = NSS_STATUS_UNAVAIL;

    dbus_error_init(&err);

    pthread_mutex_lock (&mutex);

    if (connection == NULL) {
        connection = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
        if (dbus_error_is_set(&err)) { 
            debug (va("%s: %s", __FUNCTION__, err.message));
            dbus_error_free(&err);
            connection = NULL;
        }
        dbus_error_free(&err);
    }

    if (connection != NULL)
        ret = NSS_STATUS_SUCCESS;

    pthread_mutex_unlock (&mutex);

    return ret;
}

void client_dbus_destroy(void)
{
    pthread_mutex_lock (&mutex);

    if (connection != NULL) {
        dbus_connection_unref(connection);
        connection = NULL;
    }

    pthread_mutex_unlock (&mutex);
}

static nss_status fill_user(
    DBusMessage* msg,
    struct passwd *pw,
    char *buffer,
    size_t buflen)
{
    DBusMessageIter args;

    if (!dbus_message_iter_init(msg, &args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no arguments"));
        return false;
    }
    else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "First argument is not uint32"));
        return false;
    }
    else
        dbus_message_iter_get_basic(&args, &pw->pw_uid);

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no second arguments"));
        return false;
    }
    else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Second argument is not uint32"));
        return false;
    }
    else
        dbus_message_iter_get_basic(&args, &pw->pw_gid);

    return NSS_STATUS_SUCCESS;
}

nss_status client_dbus_get_user_by_id(
    uid_t user_id,
    struct passwd *pw,
    char *buffer,
    size_t buflen,
    int *errnop)
{
    DBusMessage* msg;
    DBusMessageIter args;
    DBusPendingCall* pending;
    DBusConnection* tmp_connection = NULL;
    nss_status ret = NSS_STATUS_UNAVAIL;

    pthread_mutex_lock (&mutex);

    msg = dbus_message_new_method_call(TARTARUS_NSS_SERVER_NAME,
                                       TARTARUS_NSS_SERVER_PATH,
                                       TARTARUS_NSS_SERVER_IFACE,
                                       "getUserByName");
    if (NULL == msg) { 
        debug (va("%s: %s", __FUNCTION__, "Message Null"));
        goto err;
    }

    dbus_message_iter_init_append(msg, &args);
    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_UINT32, &user_id)) {
    //if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &user_name)) {
        debug (va("%s: %s", __FUNCTION__, "Out Of Memory"));
        dbus_message_unref(msg);
        goto err;
    }

    if (connection == NULL) {
        DBusError err;

        dbus_error_init(&err);

        tmp_connection = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
        if (dbus_error_is_set(&err)) { 
            debug (va("%s: %s", __FUNCTION__, err.message));
            dbus_error_free(&err);
            tmp_connection = NULL;
            goto err;
        }
        dbus_error_free(&err);
    }

    if (!dbus_connection_send_with_reply (tmp_connection ? tmp_connection : connection, msg, &pending, TARTARUS_NSS_CLIENT_TIMEOUT)) {
        debug (va("%s: %s", __FUNCTION__, "Problem with Send"));
        dbus_message_unref(msg);
        goto err;
    }

    if (pending == NULL) { 
        debug (va("%s: %s", __FUNCTION__, "Pending Call Null"));
        dbus_message_unref(msg);
        goto err;
    }
    dbus_connection_flush(connection);

    dbus_message_unref(msg);
    dbus_pending_call_block(pending);

    msg = dbus_pending_call_steal_reply(pending);
    dbus_pending_call_unref(pending);
    if (msg == NULL) {
        debug (va("%s: %s", __FUNCTION__, "Reply Null"));
        goto err;
    }

    ret = fill_user(msg, pw, buffer, buflen);

    if (ret == NSS_STATUS_TRYAGAIN)
        *errnop = errno = ERANGE;
    else
        *errnop = 0;

    dbus_message_unref(msg);

err:
    if (tmp_connection != NULL)
        dbus_connection_unref(connection);

    pthread_mutex_unlock (&mutex);

    return ret;
}

nss_status client_dbus_get_user_by_name(
    const char *user_name,
    struct passwd *pw,
    char *buffer,
    size_t buflen,
    int *errnop)
{
    nss_status ret = NSS_STATUS_UNAVAIL;

    return ret;
}

nss_status client_dbus_get_group_by_id(
    uid_t user_id,
    struct group *gr,
    char *buffer,
    size_t buflen,
    int *errnop)
{
    nss_status ret = NSS_STATUS_UNAVAIL;

    return ret;
}

nss_status client_dbus_get_group_by_name(
    const char *user_name,
    struct group *gr,
    char *buffer,
    size_t buflen,
    int *errnop)
{
    nss_status ret = NSS_STATUS_UNAVAIL;

    return ret;
}

nss_status client_dbus_init_groups_for_user(
    const char *user_name,
    long int *start,
    long int *size,
    gid_t **groups,
    long int limit,
    int *errnop)
{
    nss_status ret = NSS_STATUS_UNAVAIL;

    return ret;
}

