file(GLOB sources "*.cpp" "../RPC/client.cpp")
add_library(nss_tartarus SHARED ${sources})
set_target_properties(nss_tartarus PROPERTIES SOVERSION 2)

install(TARGETS nss_tartarus LIBRARY DESTINATION lib${LIB_SUFFIX})
