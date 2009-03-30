#ifndef Tartarus_DBUS_Config_h
#define Tartarus_DBUS_COnfig_h

#ifndef TARTARUS_SYSTEM_SOCKET_DIR
#define TARTARUS_SYSTEM_SOCKET_DIR "/var/run/tartarus"
#endif
#ifndef TARTARUS_SYSTEM_SOCKET_PATH
#define TARTARUS_SYSTEM_SOCKET_PATH (TARTARUS_SYSTEM_SOCKET_DIR "/tnscd_socket")
#endif
#ifndef TARTARUS_NSS_SERVER_PATH
#define TARTARUS_NSS_SERVER_PATH "/ru/tartarus/DBus/TNSCD"
#endif
#ifndef TARTARUS_NSS_SERVER_NAME
#define TARTARUS_NSS_SERVER_NAME "ru.tartarus.DBus.TNSCD"
#endif
#ifndef TARTARUS_NSS_SERVER_IFACE
#define TARTARUS_NSS_SERVER_IFACE "ru.tartarus.DBus.TNSCD"
#endif
#ifndef TARTARUS_NSS_CLIENT_TIMEOUT
#define TARTARUS_NSS_CLIENT_TIMEOUT 500
#endif
#ifndef TARTARUS_NSS_PEER_TO_PEER_PATH
#define TARTARUS_NSS_PEER_TO_PEER_PATH "unix:path=/var/run/tnscd/pipe"
#endif

#endif /* Tartarus_DBUS_Config_h */
