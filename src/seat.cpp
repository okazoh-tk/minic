
#include "seat.h"

namespace minic {

Seat::Seat()
{
}

Seat::~Seat()
{
}

struct wl_seat_interface Seat::mImplementation = {
    .get_pointer = Seat::getPointer,
    .get_keyboard = Seat::getKeyboard,
    .get_touch = Seat::getTouch,
    .release = Seat::release
};

const void* Seat::getImplementation()
{
    return &mImplementation;
}

void Seat::getPointer(
    struct wl_client *client,
    struct wl_resource *resource,
    uint32_t id)
{

}

void Seat::getKeyboard(
    struct wl_client *client,
    struct wl_resource *resource,
    uint32_t id)
{
}

void Seat::getTouch(
    struct wl_client *client,
    struct wl_resource *resource,
    uint32_t id)
{
}

void Seat::release(
    struct wl_client *client,
    struct wl_resource *resource)
{
}

SeatBuilder::SeatBuilder()
{
}

SeatBuilder::~SeatBuilder()
{
}

Resource* SeatBuilder::onCreate(
    struct wl_client* client,
    uint32_t& version)
{
    return new Seat();
}

const struct wl_interface* SeatBuilder::getInterface()
{
    return &wl_seat_interface;
}

uint32_t SeatBuilder::getVersion()
{
    return WL_SEAT_RELEASE_SINCE_VERSION;
}

}
