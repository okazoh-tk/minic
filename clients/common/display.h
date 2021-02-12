
#pragma once

#include <wayland-client.h>

class Display {
public:
    Display(const char* name = nullptr);
    virtual ~Display();

    wl_display* getWlDisplay() const;
    wl_compositor* getWlCompositor() const;
    wl_shm* getWlShm() const;
    wl_shell* getWlShell() const;
    wl_seat* getWlSeat() const;
    wl_output* getWlOutput() const;

    int dispatch();
    int dispatchPending();

protected:
    virtual void onGlobal(
	wl_registry* wl_registry,
	uint32_t name,
	const char* interface,
	uint32_t version);
    virtual void onGlobalRemove(
	wl_registry* wl_registry,
	uint32_t name);

private:
    static void onGlobal(
	void* data,
	wl_registry* registry,
	uint32_t name,
	const char* interface,
	uint32_t version);

    static void onGlobalRemove(
	void* data,
	wl_registry* registry,
	uint32_t name);

    bool initInterface(
	wl_registry* registry,
	uint32_t name,
	const char* interface,
	uint32_t version);

private:
    wl_display* mDisplay;
    wl_registry* mRegistry;
    wl_registry_listener mListener;

    wl_compositor* mCompositor;
    wl_shm* mShm;
    wl_shell* mShell;
    wl_seat* mSeat;
    wl_output* mOutput;
};
