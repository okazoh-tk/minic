
#include "region.h"

namespace minic {

Region::Region()
{
}

Region::~Region()
{
}

struct wl_region_interface Region::mImplementation = {
    .destroy = Region::destroy,
    .add = Region::add,
    .subtract = Region::subtract
};

const void* Region::getImplementation()
{
    return &mImplementation;
}

void Region::destroy(
    struct wl_client* client,
    struct wl_resource* resource)
{
    auto thiz = reinterpret_cast<Region*>(
        wl_resource_get_user_data(resource));

    delete thiz;
}

void Region::add(
    struct wl_client* client,
    struct wl_resource* resource,
    int32_t x, int32_t y,
    int32_t width, int32_t height)
{
    auto thiz = reinterpret_cast<Region*>(
        wl_resource_get_user_data(resource));
}

void Region::subtract(
    struct wl_client* client,
    struct wl_resource* resource,
    int32_t x, int32_t y,
    int32_t width, int32_t height)
{
    auto thiz = reinterpret_cast<Region*>(
        wl_resource_get_user_data(resource));
}


RegionBuilder::RegionBuilder()
{
}

RegionBuilder::~RegionBuilder()
{
}

Resource* RegionBuilder::onCreate(
    struct wl_client* client,
    uint32_t& version)
{
    return new Region();
}

const struct wl_interface* RegionBuilder::getInterface()
{
    return &wl_region_interface;
}

uint32_t RegionBuilder::getVersion()
{
    return WL_REGION_SUBTRACT_SINCE_VERSION;
}

}
