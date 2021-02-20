
#include "surface.h"

namespace minic {

Surface::Surface()
{
}

Surface::~Surface()
{
}

struct wl_surface_interface Surface::mImplementation = {
    .destroy = Surface::destroy,
    .attach = Surface::attach,
    .damage = Surface::damage,
    .frame = Surface::frame,
    .set_opaque_region = Surface::setOpaqueRegion,
    .set_input_region = Surface::setInputRegion,
    .commit = Surface::commit,
    .set_buffer_transform = Surface::setBufferTransform,
    .set_buffer_scale = Surface::setBufferScale,
    .damage_buffer = Surface::damageBuffer
};

const void* Surface::getImplementation()
{
    return &mImplementation;
}

void Surface::destroy(
    struct wl_client* client,
    struct wl_resource* resource)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));

    delete thiz;
}

void Surface::attach(
    struct wl_client* client,
    struct wl_resource* resource,
    struct wl_resource* buffer,
    int32_t x, int32_t y)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::damage(
    struct wl_client* client,
    struct wl_resource* resource,
    int32_t x, int32_t y,
    int32_t width, int32_t height)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::frame(
    struct wl_client* client,
    struct wl_resource* resource,
    uint32_t callback)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::setOpaqueRegion(
    struct wl_client* client,
    struct wl_resource* resource,
    struct wl_resource* region)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::setInputRegion(
    struct wl_client* client,
    struct wl_resource* resource,
    struct wl_resource* region)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::commit(
    struct wl_client* client,
    struct wl_resource* resource)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::setBufferTransform(
    struct wl_client* client,
    struct wl_resource* resource,
    int32_t transform)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::setBufferScale(
    struct wl_client* client,
    struct wl_resource* resource,
    int32_t transform)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}

void Surface::damageBuffer(
    struct wl_client* client,
    struct wl_resource* resource,
    int32_t x, int32_t y,
    int32_t width, int32_t height)
{
    auto thiz = reinterpret_cast<Surface*>(
        wl_resource_get_user_data(resource));
}



SurfaceBuilder::SurfaceBuilder()
{
}

SurfaceBuilder::~SurfaceBuilder()
{
}

Resource* SurfaceBuilder::onCreate(
    struct wl_client* client,
    uint32_t& version)
{
    return new Surface();
}

const struct wl_interface* SurfaceBuilder::getInterface()
{
    return &wl_surface_interface;
}

uint32_t SurfaceBuilder::getVersion()
{
    return WL_SURFACE_DAMAGE_BUFFER_SINCE_VERSION;
}

}