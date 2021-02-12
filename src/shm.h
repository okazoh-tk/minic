
#pragma once

#include "resource.h"

namespace minic {

class Shm
    : public Resource {
public:
    Shm();
    ~Shm() override;

    const void* getImplementation() override;

protected:
    static void createPool(
        struct wl_client* client,
        struct wl_resource* resource,
	uint32_t id,
        int32_t fd,
        int32_t size);

private:
    static struct wl_shm_interface mImplementation;
};

class ShmBuilder
    : public ResourceBuilder {
public:
    ShmBuilder();
    ~ShmBuilder() override;

protected:
    Resource* onCreate(
        struct wl_client* client,
        uint32_t& version) override;

    const struct wl_interface* getInterface() override;
    uint32_t getVersion() override;
};

}
