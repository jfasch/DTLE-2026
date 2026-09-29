cmake_minimum_required(VERSION 3.20)
project(DTLE-2026)

# Produce json file for code completion
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

add_subdirectory(firmware)
add_subdirectory(lib)
add_subdirectory(tests)
add_subdirectory(googletest)
