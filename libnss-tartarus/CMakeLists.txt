cmake_minimum_required(VERSION 2.6)

project (libnss-tartarus)

include(cmake/slice2cpp.cmake)
include(cmake/dbusxx-xml2cpp.cmake)

include_directories (${libnss-tartarus_SOURCE_DIR})
set(CMAKE_CXX_FLAGS "-O2")

add_subdirectory (RPC)
add_subdirectory (NSCD)
add_subdirectory (nss)
