
#include "compositor.h"

namespace minic {

Compositor::Compositor()
{
}

Compositor::~Compositor()
{
}

struct wl_compositor_interface Compositor::mImplementation = {
    .create_surface = Compositor::createSurface,
    .create_region = Compositor::createRegion
};

const void* Compositor::getImplementation()
{
    return &mImplementation;
}

void Compositor::createSurface(
    struct wl_client* client,
    struct wl_resource* resource,
    uint32_t id)
{
    auto thiz = reinterpret_cast<Compositor*>(
        wl_resource_get_user_data(resource));

    thiz->mSurfaceBuilder.build(
        client,
        thiz->mSurfaceBuilder.getVersion(),
        id);
}

void Compositor::createRegion(
    struct wl_client* client,
    struct wl_resource* resource,
    uint32_t id)
{
    auto thiz = reinterpret_cast<Compositor*>(
        wl_resource_get_user_data(resource));

    thiz->mRegionBuilder.build(
        client,
        thiz->mRegionBuilder.getVersion(),
        id);
}


CompositorBuilder::CompositorBuilder()
{
}

CompositorBuilder::~CompositorBuilder()
{
}

Resource* CompositorBuilder::onCreate(
    struct wl_client* client,
    uint32_t& version)
{
    return new Compositor();
}

const struct wl_interface* CompositorBuilder::getInterface()
{
    return &wl_compositor_interface;
}

uint32_t CompositorBuilder::getVersion()
{
    return 4;
}

}
