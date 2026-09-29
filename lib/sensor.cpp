#include "sensor.h"

double Sensor::get_temperature() const
{
    return _temperature;
}

void Sensor::set_temperature(double t)
{
    _temperature = t;
}
