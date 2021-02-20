
#include "shm.h"

namespace minic {

Shm::Shm()
{
}

Shm::~Shm()
{
}

struct wl_shm_interface Shm::mImplementation = {
    .create_pool = Shm::createPool
};

const void* Shm::getImplementation()
{
    return &mImplementation;
}

void Shm::createPool(
    struct wl_client* client,
    struct wl_resource* resource,
    uint32_t id,
    int32_t fd,
    int32_t size)
{
}


ShmBuilder::ShmBuilder()
{
}

ShmBuilder::~ShmBuilder()
{
}

Resource* ShmBuilder::onCreate(
    struct wl_client* client,
    uint32_t& version)
{
    return new Shm();
}

const struct wl_interface* ShmBuilder::getInterface()
{
    return &wl_shm_interface;
}

uint32_t ShmBuilder::getVersion()
{
    return WL_SHM_CREATE_POOL_SINCE_VERSION;
}

}
