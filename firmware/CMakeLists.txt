add_executable(
  DTLE-2026-firmware
  firmware.cpp
)

target_link_libraries(
  DTLE-2026-firmware
  DTLE-2026-lib
)
