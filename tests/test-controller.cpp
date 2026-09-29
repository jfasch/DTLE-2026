#include "sensor.h"
#include "led.h"
#include "controller.h"
#include <gtest/gtest.h>

TEST(controller_tests, basic)
{
    Sensor sensor;
    LED cold, comfy, hot;
    Controller controller(sensor, cold, comfy, hot, 10.0, 40.0);

    sensor.set_temperature(5.0);
    controller.update();

    ASSERT_TRUE(cold.get_state());
    ASSERT_FALSE(comfy.get_state());
    ASSERT_FALSE(hot.get_state());

    sensor.set_temperature(10.0);
    controller.update();

    ASSERT_FALSE(cold.get_state());
    ASSERT_TRUE(comfy.get_state());
    ASSERT_FALSE(hot.get_state());

    sensor.set_temperature(30.0);
    controller.update();

    ASSERT_FALSE(cold.get_state());
    ASSERT_TRUE(comfy.get_state());
    ASSERT_FALSE(hot.get_state());

    sensor.set_temperature(40.0);
    controller.update();

    ASSERT_FALSE(cold.get_state());
    ASSERT_TRUE(comfy.get_state());
    ASSERT_FALSE(hot.get_state());

    sensor.set_temperature(50.0);
    controller.update();

    ASSERT_FALSE(cold.get_state());
    ASSERT_FALSE(comfy.get_state());
    ASSERT_TRUE(hot.get_state());
}
