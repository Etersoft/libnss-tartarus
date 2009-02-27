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

static char *allocate_mem (char **buf, size_t *buflen, size_t len)
{
    char *next;

    if (!buf || !buflen || (*buflen < len))
        return NULL;

    next = *buf;
    *buf += len;
    *buflen -= len;
    return next;
}

static inline char *fill_record (char **buffer, size_t *buflen, const char *value)
{
    char *result = allocate_mem (buffer, buflen, strlen(value) + 1);
    if (result)
        strcpy(result, value);
    return result;
}

static bool realloc_groups (long int **size, gid_t ***groups, long int limit)
{
    long int new_size;
    gid_t *new_groups;

    new_size = 2 * (**size);
    if (limit > 0) {
        if (**size == limit)
            return false;

        if (new_size > limit)
            new_size = limit;
    }

    new_groups = (gid_t *)
        realloc((**groups),
            new_size * sizeof(***groups));
    if (!new_groups)
        return false;

    **groups = new_groups;
    **size = new_size;

    return true;
}

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
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "First argument is not uint32"));
        return NSS_STATUS_UNAVAIL;
    }
    else
        dbus_message_iter_get_basic(&args, &pw->pw_uid);

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no second argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Second argument is not uint32"));
        return NSS_STATUS_UNAVAIL;
    }
    else
        dbus_message_iter_get_basic(&args, &pw->pw_gid);

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no third argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Third argument is not string"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        const char* value;
        dbus_message_iter_get_basic(&args, &value);
        debug (va("%s: %s: %s", __FUNCTION__, "Third argument", value));
        pw->pw_name = fill_record (&buffer, &buflen, value);
        if (pw->pw_name == NULL)
            return NSS_STATUS_TRYAGAIN;
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no fourth argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Fourth argument is not string"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        const char* value;
        dbus_message_iter_get_basic(&args, &value);
        pw->pw_gecos = fill_record (&buffer, &buflen, value);
        if (pw->pw_gecos == NULL)
            return NSS_STATUS_TRYAGAIN;
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no fifth argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Fifth argument is not string"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        const char* value;
        dbus_message_iter_get_basic(&args, &value);
        pw->pw_dir = fill_record (&buffer, &buflen, value);
        if (pw->pw_dir == NULL)
            return NSS_STATUS_TRYAGAIN;
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no sixth argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Sixth argument is not string"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        const char* value;
        dbus_message_iter_get_basic(&args, &value);
        pw->pw_shell = fill_record (&buffer, &buflen, value);
        if (pw->pw_shell == NULL)
            return NSS_STATUS_TRYAGAIN;
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no seventh argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Seventh argument is not string"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        const char* value;
        dbus_message_iter_get_basic(&args, &value);
        pw->pw_passwd = fill_record (&buffer, &buflen, value);
        if (pw->pw_passwd == NULL)
            return NSS_STATUS_TRYAGAIN;
    }

    return NSS_STATUS_SUCCESS;
}

#define MEMBERS_BUFFER_LEN 256

static nss_status fill_group(
    DBusMessage* msg,
    struct group *gr,
    char *buffer,
    size_t buflen)
{
    DBusMessageIter args;
    size_t users_size;

    if (!dbus_message_iter_init(msg, &args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no arguments"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "First argument is not uint32"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        dbus_message_iter_get_basic(&args, &gr->gr_gid);
        debug (va("%s: %s: %d", __FUNCTION__, "First argument", gr->gr_gid));
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no second argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Second argument is not string"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        const char* value;
        dbus_message_iter_get_basic(&args, &value);
        debug (va("%s: %s: %s", __FUNCTION__, "Second argument", value));
        gr->gr_name = fill_record (&buffer, &buflen, value);
        if (gr->gr_name == NULL)
            return NSS_STATUS_TRYAGAIN;
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no third argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_STRING != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Third argument is not string"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        const char* value;
        dbus_message_iter_get_basic(&args, &value);
        debug (va("%s: %s: %s", __FUNCTION__, "Third argument", value));
        gr->gr_passwd = fill_record (&buffer, &buflen, value);
        if (gr->gr_passwd == NULL)
            return NSS_STATUS_TRYAGAIN;
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no fourth argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_UINT32 != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Fourth argument is not uint32"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        dbus_message_iter_get_basic(&args, &users_size);
        debug (va("%s: %s: %d", __FUNCTION__, "Fourth argument", users_size));
    }

    if (!dbus_message_iter_next(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no fourth argument"));
        return NSS_STATUS_UNAVAIL;
    }
    else if (DBUS_TYPE_ARRAY != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "Fifth argument is not array"));
        return NSS_STATUS_UNAVAIL;
    }
    else {
        DBusMessageIter sub;
        char **member_list, *member_list_tst;
        size_t align, len = 0;

        align = (unsigned long)(*buffer) % sizeof(char*);
        if (align != 0)
            align = sizeof(char*) - align;
        member_list_tst = allocate_mem (&buffer, &buflen, (users_size + 1) * sizeof(char *) + align);
        if (member_list_tst == NULL)
            return NSS_STATUS_TRYAGAIN;

        gr->gr_mem = (char **)(member_list_tst + align);
        member_list = gr->gr_mem;

        dbus_message_iter_recurse(&args, &sub);
        while (DBUS_TYPE_STRING == dbus_message_iter_get_arg_type(&sub) && len++ < users_size) {
            char *member;
            const char* value;
            dbus_message_iter_get_basic(&sub, &value);
        debug (va("%s: %s, %d, %s", __FUNCTION__, "Cycle", len, value));
            member = fill_record (&buffer, &buflen, value);
            if (member == NULL)
                return NSS_STATUS_TRYAGAIN;

            *member_list++ = member;
            strcpy(member, value);

            if (!dbus_message_iter_has_next(&sub)) {
                break;
            }

            dbus_message_iter_next(&sub);
        }
        *member_list = 0;
    }

    return NSS_STATUS_SUCCESS;
}

static inline DBusMessage* client_dbus_message_start(const char *method)
{
    return dbus_message_new_method_call(
        TARTARUS_NSS_SERVER_NAME,
        TARTARUS_NSS_SERVER_PATH,
        TARTARUS_NSS_SERVER_IFACE,
        method);
}

static DBusMessage* client_dbus_send_message(DBusMessage* msg)
{
    DBusConnection* conn = connection;
    DBusConnection* tmp_connection = NULL;
    DBusPendingCall* pending;
    DBusMessage* ret;

    if (connection == NULL) {
        DBusError err;

        dbus_error_init(&err);

        tmp_connection = dbus_bus_get(DBUS_BUS_SYSTEM, &err);
        if (dbus_error_is_set(&err)) { 
            debug (va("%s: %s", __FUNCTION__, err.message));
            dbus_error_free(&err);
            tmp_connection = NULL;
            goto send_err;
        }
        conn = tmp_connection;
        dbus_error_free(&err);
    }

    if (!dbus_connection_send_with_reply (conn, msg, &pending, TARTARUS_NSS_CLIENT_TIMEOUT)) {
        debug (va("%s: %s", __FUNCTION__, "Problem with Send"));
        goto send_err;
    }

    if (pending == NULL) { 
        debug (va("%s: %s", __FUNCTION__, "Pending Call Null"));
        goto send_err;
    }
    dbus_connection_flush(conn);
    dbus_pending_call_block(pending);

    ret = dbus_pending_call_steal_reply(pending);
    dbus_pending_call_unref(pending);
    if (ret == NULL)
        debug (va("%s: %s", __FUNCTION__, "Reply Null"));

send_err:
    if (tmp_connection != NULL)
        dbus_connection_unref(tmp_connection);

    return ret;
}

nss_status client_dbus_get_user_by_name(
    const char *user_name,
    struct passwd *pw,
    char *buffer,
    size_t buflen)
{
    DBusMessage *msg, *reply;
    DBusMessageIter args;
    nss_status ret = NSS_STATUS_UNAVAIL;

    msg = client_dbus_message_start("getUserByName");
    if (msg == NULL) { 
        debug (va("%s: %s", __FUNCTION__, "Message Null"));
        return ret;
    }

    dbus_message_iter_init_append(msg, &args);
    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &user_name)) {
        debug (va("%s: %s", __FUNCTION__, "Out Of Memory"));
        dbus_message_unref(msg);
        return ret;
    }

    pthread_mutex_lock (&mutex);

    reply = client_dbus_send_message(msg);
    dbus_message_unref(msg);

    if (reply == NULL) {
        debug (va("%s: %s", __FUNCTION__, "Send Message"));
        goto err;
    }

    ret = fill_user(reply, pw, buffer, buflen);

    dbus_message_unref(reply);

err:
    pthread_mutex_unlock (&mutex);

    return ret;
}

nss_status client_dbus_get_user_by_id(
    uid_t user_id,
    struct passwd *pw,
    char *buffer,
    size_t buflen)
{
    DBusMessage *msg, *reply;
    DBusMessageIter args;
    nss_status ret = NSS_STATUS_UNAVAIL;

    msg = client_dbus_message_start("getUserById");
    if (msg == NULL) { 
        debug (va("%s: %s", __FUNCTION__, "Message Null"));
        return ret;
    }

    dbus_message_iter_init_append(msg, &args);
    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_UINT32, &user_id)) {
        debug (va("%s: %s", __FUNCTION__, "Out Of Memory"));
        dbus_message_unref(msg);
        return ret;
    }

    pthread_mutex_lock (&mutex);

    reply = client_dbus_send_message(msg);
    dbus_message_unref(msg);

    if (reply == NULL) {
        debug (va("%s: %s", __FUNCTION__, "Send Message"));
        goto err;
    }

    ret = fill_user(msg, pw, buffer, buflen);

    dbus_message_unref(reply);

err:
    pthread_mutex_unlock (&mutex);

    return ret;
}

nss_status client_dbus_get_group_by_id(
    uid_t group_id,
    struct group *gr,
    char *buffer,
    size_t buflen)
{
    DBusMessage *msg, *reply;
    DBusMessageIter args;
    nss_status ret = NSS_STATUS_UNAVAIL;

    msg = client_dbus_message_start("getGroupById");
    if (msg == NULL) { 
        debug (va("%s: %s", __FUNCTION__, "Message Null"));
        return ret;
    }

    dbus_message_iter_init_append(msg, &args);
    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_UINT32, &group_id)) {
        debug (va("%s: %s", __FUNCTION__, "Out Of Memory"));
        dbus_message_unref(msg);
        return ret;
    }

    pthread_mutex_lock (&mutex);

    reply = client_dbus_send_message(msg);
    dbus_message_unref(msg);

    if (reply == NULL) {
        debug (va("%s: %s", __FUNCTION__, "Send Message"));
        goto err;
    }

    ret = fill_group(reply, gr, buffer, buflen);

    dbus_message_unref(reply);

err:
    pthread_mutex_unlock (&mutex);

    return ret;
}

nss_status client_dbus_get_group_by_name(
    const char *group_name,
    struct group *gr,
    char *buffer,
    size_t buflen)
{
    DBusMessage *msg, *reply;
    DBusMessageIter args;
    nss_status ret = NSS_STATUS_UNAVAIL;

    msg = client_dbus_message_start("getGroupByName");
    if (msg == NULL) { 
        debug (va("%s: %s", __FUNCTION__, "Message Null"));
        return ret;
    }

    dbus_message_iter_init_append(msg, &args);
    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &group_name)) {
        debug (va("%s: %s", __FUNCTION__, "Out Of Memory"));
        dbus_message_unref(msg);
        return ret;
    }

    pthread_mutex_lock (&mutex);

    reply = client_dbus_send_message(msg);
    dbus_message_unref(msg);

    if (reply == NULL) {
        debug (va("%s: %s", __FUNCTION__, "Send Message"));
        goto err;
    }

    ret = fill_group(reply, gr, buffer, buflen);

    dbus_message_unref(reply);

err:
    pthread_mutex_unlock (&mutex);

    return ret;
}

nss_status client_dbus_init_groups_for_user(
    const char *user_name,
    long int *start,
    long int *size,
    gid_t **groups,
    long int limit)
{
    DBusMessage *msg, *reply;
    DBusMessageIter args;
    nss_status ret = NSS_STATUS_UNAVAIL;

    msg = client_dbus_message_start("getUserGroups");
    if (msg == NULL) { 
        debug (va("%s: %s", __FUNCTION__, "Message Null"));
        return ret;
    }

    dbus_message_iter_init_append(msg, &args);
    if (!dbus_message_iter_append_basic(&args, DBUS_TYPE_STRING, &user_name)) {
        debug (va("%s: %s", __FUNCTION__, "Out Of Memory"));
        dbus_message_unref(msg);
        return ret;
    }

    pthread_mutex_lock (&mutex);

    reply = client_dbus_send_message(msg);
    dbus_message_unref(msg);

    if (reply == NULL) {
        debug (va("%s: %s", __FUNCTION__, "Send Message"));
        goto err;
    }

    if (!dbus_message_iter_init(msg, &args)) {
        debug (va("%s: %s", __FUNCTION__, "Message has no arguments"));
    }
    else if (DBUS_TYPE_ARRAY != dbus_message_iter_get_arg_type(&args)) {
        debug (va("%s: %s", __FUNCTION__, "First argument is not array"));
    }
    else {
        DBusMessageIter sub;

        dbus_message_iter_recurse(&args, &sub);
        while (DBUS_TYPE_UINT32 == dbus_message_iter_get_arg_type(&sub)) {
            gid_t id;
            dbus_message_iter_get_basic(&sub, &id);
            if (*start == *size) {
                if (!realloc_groups (&size, &groups, limit))
                    break;
            }
            (*groups)[(*start)++] = id;

            if (!dbus_message_iter_has_next(&sub)) {
                break;
            }

            dbus_message_iter_next(&sub);
        }

        ret = NSS_STATUS_SUCCESS;
    }

    dbus_message_unref(reply);

err:
    pthread_mutex_unlock (&mutex);

    return ret;
}

