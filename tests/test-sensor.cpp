#include "sensor.h"
#include <gtest/gtest.h>

TEST(sensor_tests, basic)
{
    Sensor sensor;
    ASSERT_DOUBLE_EQ(sensor.get_temperature(), -273.15);
    sensor.set_temperature(42.666);
    ASSERT_DOUBLE_EQ(sensor.get_temperature(), 42.666);
}
