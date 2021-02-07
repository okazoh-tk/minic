
#include "compositor.h"

namespace minic {

Compositor::Compositor()
{
}

Compositor::~Compositor()
{
}

struct wl_compositor_interface Compositor::mImplementation = {
    Compositor::createSurface,
    Compositor::createRegion
};

const void* Compositor::getImplementation()
{
    return &mImplementation;
}

void Compositor::createSurface(
    wl_client* client,
    wl_resource* compositor_resource,
    uint32_t id)
{
}

void Compositor::createRegion(
    wl_client* client,
    wl_resource* compositor_resource,
    uint32_t id)
{
}


CompositorBuilder::CompositorBuilder()
{
}

CompositorBuilder::~CompositorBuilder()
{
}

Resource* CompositorBuilder::onCreate(
    wl_client* client,
    uint32_t& version)
{
    return new Compositor();
}

const wl_interface* CompositorBuilder::getInterface()
{
    return &wl_compositor_interface;
}

uint32_t CompositorBuilder::getVersion()
{
    return 4;
}

}
