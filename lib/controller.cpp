#include "controller.h"

Controller::Controller(
    Sensor& sensor, 
    LED& cold, LED& comfy, LED& hot, 
    double comfy_low, double comfy_high)
: _sensor(sensor),
  _cold(cold),
  _comfy(comfy),
  _hot(hot),
  _comfy_low(comfy_low),
  _comfy_high(comfy_high) {}

void Controller::update()
{
    double temperature = _sensor.get_temperature();

    // argh. all this is getting too weird. I'm going to leave that
    // bloody company.
    
    if (temperature >= _comfy_low && temperature <= _comfy_high) {
        _cold.set_state(false);
        _comfy.set_state(true);
        _hot.set_state(false);
        return;
    }    
}
