include(FindPkgConfig)
pkg_check_modules(KRB5USER REQUIRED krb5user)

set(SLICE_DIR "/usr/share/Tartarus/slice")
set(SLICE_HEADER_DIR "./include")
include_directories(${SLICE_HEADER_DIR})

file(GLOB slices "${SLICE_DIR}/core/*.ice")
SLICE2CPP(core_sources core_headers ${slices})

file(GLOB slices "${SLICE_DIR}/SysDB/*.ice")
SLICE2CPP(sources headers ${slices})

file(GLOB sources "*.cpp")

add_object_dependency(${sources} ${core_headers})
add_executable(tnscd ${sources} ${core_sources})

target_link_libraries(tnscd Ice tartarus-rpc json_spirit boost_system-mt boost_filesystem-mt boost_thread-mt ${KRB5USER_LDFLAGS})
link_directories (${tartarus-rpc_BINARY_DIR}/tartarus-rpc)
include_directories (.)

install(TARGETS tnscd DESTINATION sbin)
