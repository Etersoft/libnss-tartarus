set(sources "nss_tartarus.c" "nss_tartarus_pwd.c" "nss_tartarus_grp.c")
add_library(nss_tartarus SHARED ${sources})
set_target_properties(nss_tartarus PROPERTIES SOVERSION 2)

install(TARGETS nss_tartarus LIBRARY DESTINATION lib${LIB_SUFFIX})
include_directories (${CMAKE_CURRENT_SOURCE_DIR}/../include)

#set(CMAKE_CXX_FLAGS "-O2")
