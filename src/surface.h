
#pragma once

#include "resource.h"

namespace minic {

class Surface
    : public Resource
{
public:
    Surface();
    ~Surface() override;

    const void* getImplementation() override;

private:
    static void destroy(
        struct wl_client* client,
        struct wl_resource* resource);
    static void attach(
        struct wl_client* client,
        struct wl_resource* resource,
        struct wl_resource* buffer,
        int32_t x,
        int32_t y);
    static void damage(
        struct wl_client* client,
        struct wl_resource* resource,
        int32_t x, int32_t y,
        int32_t width, int32_t height);
    static void frame(
        struct wl_client* client,
        struct wl_resource* resource,
        uint32_t callback);
    static void setOpaqueRegion(
        struct wl_client* client,
        struct wl_resource* resource,
        struct wl_resource* region);
    static void setInputRegion(
        struct wl_client* client,
        struct wl_resource* resource,
        struct wl_resource* region);
    static void commit(
        struct wl_client* client,
        struct wl_resource* resource);
    static void setBufferTransform(
        struct wl_client* client,
        struct wl_resource* resource,
        int32_t transform);
    static void setBufferScale(
        struct wl_client* client,
        struct wl_resource* resource,
        int32_t transform);
    static void damageBuffer(
        struct wl_client* client,
        struct wl_resource* resource,
        int32_t x, int32_t y,
        int32_t width, int32_t height);
private:
    static struct wl_surface_interface mImplementation;
};

class SurfaceBuilder
    : public ResourceBuilder
{
public:
    SurfaceBuilder();
    ~SurfaceBuilder() override;

    const wl_interface* getInterface() override;
    uint32_t getVersion() override;

protected:
    Resource* onCreate(
        wl_client* client,
        uint32_t& version) override;
};

}
