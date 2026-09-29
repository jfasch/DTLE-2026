#pragma once

class Sensor
{
public:
    Sensor() : _temperature(-273.15) {}

    double get_temperature() const;
    void set_temperature(double);

private:
    double _temperature;
};
