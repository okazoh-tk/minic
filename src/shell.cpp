
#include "shell.h"


namespace minic {

Shell::Shell()
{
}

Shell::~Shell()
{
}

struct wl_shell_interface Shell::mImplementation = {
    .get_shell_surface = Shell::getShellSurface
};

const void* Shell::getImplementation()
{
    return &mImplementation;
}

void Shell::getShellSurface(
    struct wl_client* client,
    struct wl_resource* resource,
    uint32_t id,
    struct wl_resource* surface)
{
}


ShellBuilder::ShellBuilder()
{
}

ShellBuilder::~ShellBuilder()
{
}

Resource* ShellBuilder::onCreate(
    wl_client* client,
    uint32_t& version)
{
    return new Shell();
}
    
const wl_interface* ShellBuilder::getInterface()
{
    return &wl_shell_interface;
}

uint32_t ShellBuilder::getVersion()
{
    return 1;
}
    
}
