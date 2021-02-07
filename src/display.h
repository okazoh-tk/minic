
#pragma once

#include <wayland-server.h>
#include "resource.h"

namespace minic {

class Display {
public:
    Display();
    ~Display();

    const char* addSocket(
        const char* sock_name = nullptr);

    void add(
        ResourceBuilder* builder);

    void run();

private:
    wl_display* mDisplay;
};

}
