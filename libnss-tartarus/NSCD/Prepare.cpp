#include <boost/filesystem.hpp>

#include "Prepare.h"
#include <debug.h>

namespace Tartarus {

void CheckDirectories()
{
    debug("CheckDirectories");

    if (!boost::filesystem::exists(NSS_TARTARUS_SOCKET_DIR))
        throw std::runtime_error("socket directory not exist");

    if (boost::filesystem::exists(NSS_TARTARUS_SOCKET_PATH))
        boost::filesystem::remove(NSS_TARTARUS_SOCKET_PATH);
}

}
