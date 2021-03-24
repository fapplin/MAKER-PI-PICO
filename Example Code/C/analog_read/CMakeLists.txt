cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(analog_read)

pico_sdk_init()

add_executable(analog_read
        analog_read.c
        )

target_link_libraries(analog_read hardware_adc pico_stdlib)

pico_enable_stdio_usb(analog_read 0)
pico_enable_stdio_uart(analog_read 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(analog_read)
