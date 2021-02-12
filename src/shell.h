
#pragma once

#include "resource.h"

namespace minic {

class Shell
    : public Resource
{
public:
    Shell();
    ~Shell() override;

    const void* getImplementation() override;

private:
    static void getShellSurface(
	struct wl_client* client,
	struct wl_resource* resource,
	uint32_t id,
	struct wl_resource* surface);

private:
    static struct wl_shell_interface mImplementation;
};

class ShellBuilder
    : public ResourceBuilder
{
public:
    ShellBuilder();
    ~ShellBuilder() override;

protected:
    Resource* onCreate(
        struct wl_client* client,
        uint32_t& version) override;

    const struct wl_interface* getInterface() override;
    uint32_t getVersion() override;
};

}
