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
    
    if (temperature < _comfy_low) {
        _cold.set_state(true);
        _comfy.set_state(false);
        _hot.set_state(false);
        return;
    }
    if (temperature >= _comfy_low && temperature <= _comfy_high) {
        _cold.set_state(false);
        _comfy.set_state(true);
        _hot.set_state(false);
        return;
    }    
    if (temperature > _comfy_high) {
        _cold.set_state(false);
        _comfy.set_state(false);
        _hot.set_state(true);
        return;
    }    
}
