#include "led.h"
#include <gtest/gtest.h>

TEST(led_tests, basic)
{
    LED led;
    ASSERT_FALSE(led.get_state());
    led.set_state(true);
    ASSERT_TRUE(led.get_state());
}
