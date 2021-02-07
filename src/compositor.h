
#pragma once

#include "resource.h"

namespace minic {

class Compositor
    : public Resource
{
public:
    Compositor();
    ~Compositor() override;

    const void* getImplementation() override;

protected:

private:
    static void createSurface(
        wl_client* client,
        wl_resource* compositor_resource,
        uint32_t id);

    static void createRegion(
        wl_client* client,
        wl_resource* compositor_resource,
        uint32_t id);

private:
    static struct wl_compositor_interface mImplementation;
};

class CompositorBuilder
    : public ResourceBuilder
{
public:
    CompositorBuilder();
    ~CompositorBuilder() override;

protected:
    Resource* onCreate(
        wl_client* client,
        uint32_t& version) override;

    const wl_interface* getInterface() override;
    uint32_t getVersion() override;
};

}
