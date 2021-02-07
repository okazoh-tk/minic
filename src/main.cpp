
#include "display.h"
#include "compositor.h"
#include "log.h"

using namespace minic;

int main(int argc, char* argv[])
{
    Display display;

    // setup global interfaces
    display.add(new CompositorBuilder());

    // start listening socket
    auto sock_name = display.addSocket();
    if (!sock_name) {
        __loge("error: wl_display_add_socket_auto");
        return 1;
    }

    __logi("wayland listen on %s", sock_name);

    // run event loop
    display.run();

    return 0;
}
