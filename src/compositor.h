
#pragma once

#include "resource.h"
#include "surface.h"
#include "region.h"

namespace minic {

class Compositor
    : public Resource
{
public:
    Compositor();
    ~Compositor() override;

    const void* getImplementation() override;

private:
    static void createSurface(
        struct wl_client* client,
        struct wl_resource* compositor_resource,
        uint32_t id);

    static void createRegion(
        struct wl_client* client,
        struct wl_resource* compositor_resource,
        uint32_t id);

private:
    static struct wl_compositor_interface mImplementation;

    SurfaceBuilder mSurfaceBuilder;
    RegionBuilder mRegionBuilder;
};

class CompositorBuilder
    : public ResourceBuilder
{
public:
    CompositorBuilder();
    ~CompositorBuilder() override;

    const struct wl_interface* getInterface() override;
    uint32_t getVersion() override;

protected:
    Resource* onCreate(
        struct wl_client* client,
        uint32_t& version) override;
};

}
