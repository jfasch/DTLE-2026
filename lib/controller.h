#pragma once

#include "sensor.h"
#include "led.h"

class Controller
{
public:
    Controller(Sensor& sensor, 
               LED& cold, LED& comfy, LED& hot, 
               double comfy_low, double comfy_high);

    void update();

private:
    Sensor& _sensor;
    LED& _cold;
    LED& _comfy;
    LED& _hot;
    double _comfy_low;
    double _comfy_high;
};
