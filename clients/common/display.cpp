
#include "display.h"
#include <cstring>

Display::Display(const char* name)
    : mDisplay(nullptr)
    , mRegistry(nullptr)
    , mCompositor(nullptr)
    , mShm(nullptr)
    , mShell(nullptr)
    , mSeat(nullptr)
    , mOutput(nullptr)
{
    mDisplay = wl_display_connect(name);

    if (!mDisplay) {
	return ;
    }

    auto registry = wl_display_get_registry(
	mDisplay);

    mListener.global = onGlobal;
    mListener.global_remove = onGlobalRemove;

    wl_registry_add_listener(
	registry,
	&mListener,
	this);

    wl_display_dispatch(mDisplay);
    wl_display_roundtrip(mDisplay);
}

Display::~Display()
{
    if (mDisplay) {
	wl_registry_destroy(mRegistry);
	wl_display_disconnect(mDisplay);
    }
}

wl_display* Display::getWlDisplay() const
{
    return mDisplay;
}

wl_compositor* Display::getWlCompositor() const
{
    return mCompositor;
}

wl_shm* Display::getWlShm() const
{
    return mShm;
}

wl_shell* Display::getWlShell() const
{
    return mShell;
}

wl_seat* Display::getWlSeat() const
{
    return mSeat;
}

wl_output* Display::getWlOutput() const
{
    return mOutput;
}


int Display::dispatch()
{
    if (!mDisplay) {
	return -1;
    }

    return wl_display_dispatch(mDisplay);
}

int Display::dispatchPending()
{
    if (!mDisplay) {
	return -1;
    }

    return wl_display_dispatch_pending(mDisplay);
}


void Display::onGlobal(
    void* data,
    wl_registry* registry,
    uint32_t name,
    const char* interface,
    uint32_t version)
{
    auto thiz = reinterpret_cast<Display*>(data);

    if (!thiz->initInterface(
	    registry,
	    name,
	    interface,
	    version))
    {
	thiz->onGlobal(
	    registry,
	    name,
	    interface,
	    version);
    }
}

void Display::onGlobalRemove(
    void* data,
    wl_registry* registry,
    uint32_t name)
{
    auto thiz = reinterpret_cast<Display*>(data);

    thiz->onGlobalRemove(
	registry, name);
}

void Display::onGlobal(
    wl_registry* wl_registry,
    uint32_t name,
    const char* interface,
    uint32_t version)
{
}

void Display::onGlobalRemove(
    wl_registry* wl_registry,
    uint32_t name)
{
}

bool Display::initInterface(
    wl_registry* registry,
    uint32_t name,
    const char* interface,
    uint32_t version)
{
    if (0 == strcmp(interface, "wl_compositor")) {
	mCompositor = (wl_compositor*)wl_registry_bind(
	    registry,
	    name,
	    &wl_compositor_interface,
	    version);
    } else if (0 == strcmp(interface, "wl_shm")) {
	mShm = (wl_shm*)wl_registry_bind(
	    registry,
	    name,
	    &wl_shm_interface,
	    version);
    } else if (0 == strcmp(interface, "wl_shell")) {
	mShell = (wl_shell*)wl_registry_bind(
	    registry,
	    name,
	    &wl_shell_interface,
	    version);
    } else if (0 == strcmp(interface, "wl_seat")) {
	mSeat = (wl_seat*)wl_registry_bind(
	    registry,
	    name,
	    &wl_seat_interface,
	    version);
    } else if (0 == strcmp(interface, "wl_output")) {
	mOutput = (wl_output*)wl_registry_bind(
	    registry,
	    name,
	    &wl_output_interface,
	    version);
    } else {
	return false;
    }

    return true;
}
