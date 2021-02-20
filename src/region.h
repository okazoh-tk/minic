
#pragma once

#include "resource.h"

namespace minic {

class Region
: public Resource
{
public:
    Region();
    ~Region() override;

    const void* getImplementation() override;

private:
    static void destroy(
        struct wl_client* client,
        struct wl_resource* resource);
    static void add(
        struct wl_client* client,
        struct wl_resource* resource,
        int32_t x, int32_t y,
        int32_t width, int32_t height);
    static void subtract(
        struct wl_client* client,
        struct wl_resource* resource,
        int32_t x, int32_t y,
        int32_t width, int32_t height);
private:
    static struct wl_region_interface mImplementation;
};

class RegionBuilder
: public ResourceBuilder
{
public:
    RegionBuilder();
    ~RegionBuilder() override;

    const wl_interface* getInterface() override;
    uint32_t getVersion() override;

protected:
    Resource* onCreate(
        wl_client* client,
        uint32_t& version) override;

};

}
