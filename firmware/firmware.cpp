#include <sensor.h>
#include <led.h>
#include <controller.h>

#include <cassert>
#include <ctime>
#include <iostream>

double rotate_temperature()
{
    static unsigned step = 0;
    double temperature;

    if (step == 0)
        temperature = 5.0;
    else if (step == 1)
        temperature = 30.0;
    else if (step == 2)
        temperature = 50.0;
    else 
        assert(!"stupid");

    step++;
    step %= 3;

    return temperature;
}

int main()
{
    Sensor sensor;
    LED low, middle, high;
    Controller controller(sensor, low, middle, high, 10.0, 40.0);

    while (true) {
        double temperature = rotate_temperature();
        sensor.set_temperature(temperature);

        controller.update();

        std::cout << "--" << (low.get_state()?'*':'-') << "--" <<  (middle.get_state()?'*':'-') << "--" << (high.get_state()?'*':'-') << '\n';

        static const timespec interval = {.tv_sec=0, .tv_nsec=500'000'000};
        nanosleep(&interval, nullptr);
    }

    return 0;
}
