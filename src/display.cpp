
#include "display.h"
#include "log.h"

namespace minic {

Display::Display()
: mDisplay(wl_display_create())
{
    if (!mDisplay) {
        __loge("error: wl_display_create");
    }
}

Display::~Display()
{
    if (mDisplay) {
        wl_display_destroy(mDisplay);
    }
}

const char* Display::addSocket(const char* sock_name)
{
    if (sock_name) {
        if (0 == wl_display_add_socket(mDisplay, sock_name)) {
            return sock_name;
        } else {
            return nullptr;
        }
    } else {
        return wl_display_add_socket_auto(mDisplay);
    }
}

void Display::add(
    ResourceBuilder* builder)
{
    auto wlglobal = wl_global_create(
        mDisplay,
        builder->getInterface(),
        builder->getVersion(),
        builder,
        builder->bind);

    if (wlglobal == nullptr) {
        __loge("error: wl_global_create");
    }    
}

void Display::run()
{
    wl_display_run(mDisplay);
}

}
