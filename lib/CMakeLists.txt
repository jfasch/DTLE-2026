add_library(
  DTLE-2026-lib

  led.h
  led.cpp

  sensor.h
  sensor.cpp

  controller.h
  controller.cpp
)

target_include_directories(
  DTLE-2026-lib
  INTERFACE
  ${CMAKE_CURRENT_SOURCE_DIR}
)
