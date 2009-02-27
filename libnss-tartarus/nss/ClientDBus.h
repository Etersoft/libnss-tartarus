#ifndef Tartarus_DBus_NSS_Client_h
#define Tartarus_DBus_NSS_Client_h

#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

#include "nss_tartarus.h"

nss_status client_dbus_init(void);
void client_dbus_destroy(void);
nss_status client_dbus_get_user_by_id(
    uid_t user_id,
    struct passwd *pw,
    char *buffer,
    size_t buflen);
nss_status client_dbus_get_user_by_name(
    const char *user_name,
    struct passwd *pw,
    char *buffer,
    size_t buflen);
nss_status client_dbus_get_group_by_id(
    uid_t group_id,
    struct group *gr,
    char *buffer,
    size_t buflen);
nss_status client_dbus_get_group_by_name(
    const char *group_name,
    struct group *gr,
    char *buffer,
    size_t buflen);
nss_status client_dbus_init_groups_for_user(
    const char *user_name,
    long int *start,
    long int *size,
    gid_t **groups,
    long int limit);

#endif
