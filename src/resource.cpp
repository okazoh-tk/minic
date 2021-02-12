
#include "resource.h"
#include "log.h"

namespace minic {

Resource::Resource()
{
}

Resource::~Resource()
{
}

const void* Resource::getImplementation()
{
    return nullptr;
}

ResourceBuilder::ResourceBuilder()
{
}

ResourceBuilder::~ResourceBuilder()
{
}


Resource* ResourceBuilder::build(
    wl_client* client,
    uint32_t version,
    uint32_t id)
{
    auto resource = onCreate(client, version);
    if (!resource) {
        return nullptr;
    }

    auto wlres = wl_resource_create(
        client, getInterface(), version, id);

    wl_resource_set_implementation(
        wlres, resource->getImplementation(), resource, destroy);

    return resource;
}

void ResourceBuilder::bind(
    wl_client* client,
    void* data,
    uint32_t version,
    uint32_t id)
{
    auto thiz = reinterpret_cast<ResourceBuilder*>(data);
    thiz->build(client, version, id);
}

void ResourceBuilder::destroy(
    wl_resource* resource)
{
    auto res = reinterpret_cast<Resource*>(wl_resource_get_user_data(resource));
    delete res;
}

}
