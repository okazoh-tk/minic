
#pragma once

#include <wayland-server.h>

namespace minic {

class Display;

class Resource {
public:
    Resource();
    virtual ~Resource() = 0;

    virtual const void* getImplementation();
};

class ResourceBuilder
{
public:
    ResourceBuilder();
    virtual ~ResourceBuilder() = 0;

    Resource* build(
        wl_client* client,
        uint32_t version,
        uint32_t id);

protected:
    virtual Resource* onCreate(
        wl_client* client,
        uint32_t& version) = 0;

    virtual const wl_interface* getInterface() = 0;
    virtual uint32_t getVersion() = 0;

private:
    static void bind(
        wl_client* client,
        void* data,
        uint32_t version,
        uint32_t id);

    static void destroy(
        wl_resource* resource);

    friend class Display;
};

}
