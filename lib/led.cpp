#include "led.h"

void LED::set_state(bool on)
{
    _state = on;
}

bool LED::get_state() const
{ 
    return _state;
}
