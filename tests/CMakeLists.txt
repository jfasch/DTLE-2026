add_executable(
  DTLE-2026-tests

  test-led.cpp
  test-sensor.cpp
  test-controller.cpp
)

target_link_libraries(
  DTLE-2026-tests

  DTLE-2026-lib
  gtest_main 
)
