#ifndef Tartarus_DBUS_Config_h
#define Tartarus_DBUS_COnfig_h

#ifndef DBUS_SYSTEM_SOCKET_DIR
#define DBUS_SYSTEM_SOCKET_DIR "/var/run/dbus"
#endif
#ifndef DBUS_SYSTEM_SOCKET_PATH
#define DBUS_SYSTEM_SOCKET_PATH (DBUS_SYSTEM_SOCKET_DIR "/system_bus_socket")
#endif

#endif /* Tartarus_DBUS_Config_h */
