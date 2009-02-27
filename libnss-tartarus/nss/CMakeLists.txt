include(FindPkgConfig)
pkg_check_modules(DBUS REQUIRED dbus-1)

set(sources "nss_tartarus.c" "ClientDBus.c" "nss_tartarus_pwd.c" "nss_tartarus_grp.c")
add_library(nss_tartarus SHARED ${sources})

set_target_properties(nss_tartarus PROPERTIES SOVERSION 2)
target_link_libraries(nss_tartarus ${DBUS_LDFLAGS})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../include ${DBUS_INCLUDE_DIRS})

install(TARGETS nss_tartarus LIBRARY DESTINATION lib${LIB_SUFFIX})

set(CMAKE_C_FLAGS "-O2 -DDEBUG=1")
