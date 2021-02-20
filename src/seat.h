
#pragma once

#include "resource.h"

namespace minic {

class Seat
    : public Resource
{
public:
    Seat();
    ~Seat() override;

    const void* getImplementation() override;

private:
    static void getPointer(
        struct wl_client *client,
        struct wl_resource *resource,
        uint32_t id);
    static void getKeyboard(
        struct wl_client *client,
        struct wl_resource *resource,
        uint32_t id);
    static void getTouch(
        struct wl_client *client,
        struct wl_resource *resource,
        uint32_t id);
    static void release(
        struct wl_client *client,
        struct wl_resource *resource);

private:
    static struct wl_seat_interface mImplementation;
};

class SeatBuilder
    : public ResourceBuilder
{
public:
    SeatBuilder();
    ~SeatBuilder() override;

    const struct wl_interface* getInterface() override;
    uint32_t getVersion() override;

protected:
    Resource* onCreate(
        struct wl_client* client,
        uint32_t& version) override;
};

}
