include(FindPkgConfig)
pkg_check_modules(KRB5USER REQUIRED krb5user)
pkg_check_modules(DBUSCXX REQUIRED dbus-c++-1)

set(SLICE_DIR "/usr/share/Tartarus/slice")
set(SLICE_HEADER_DIR ${CMAKE_CURRENT_BINARY_DIR})
include_directories(${SLICE_HEADER_DIR})

file(GLOB core_slices "${SLICE_DIR}/core/*.ice")
SLICE2CPP(core_sources core_headers ${core_slices})

file(GLOB sysdb_slices "${SLICE_DIR}/SysDB/*.ice")
SLICE2CPP(sysdb_sources sysdb_headers ${sysdb_slices})

add_objects_dependency(${sysdb_sources} ${core_headers})

DBUSXX_XML2CPP_ADAPTOR(adaptor_header "NSCDAdaptor.h" "ru.tartarus.DBus.TNSCD.xml")

file(GLOB sources "*.cpp")
set_source_files_properties(${sources} PROPERTIES OBJECT_DEPENDS ${adaptor_header})

add_executable(tnscd ${sources} ${core_sources} ${sysdb_sources})

target_link_libraries(tnscd Ice boost_system-mt boost_filesystem-mt boost_thread-mt ${KRB5USER_LDFLAGS} ${DBUSCXX_LDFLAGS})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../include ${CMAKE_CURRENT_BINARY_DIR} ${DBUSCXX_INCLUDE_DIRS})

install(TARGETS tnscd DESTINATION ${SBINDIR})
install(PROGRAMS "tnscd.runner" DESTINATION ${SBINDIR})
install(FILES "tnscd.config" DESTINATION ${TARTARUS_CONFIG_DIR})
install(FILES "ru.tartarus.DBus.TNSCD.conf" DESTINATION ${DBUS_CONFIG_DIR})
install(FILES "ru.tartarus.DBus.TNSCD.service" DESTINATION ${DBUS_SERVICES_DIR})
