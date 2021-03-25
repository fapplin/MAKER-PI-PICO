cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(read_ultrasonic)

pico_sdk_init()

add_executable(read_ultrasonic
        read_ultrasonic.c
        )

target_link_libraries(read_ultrasonic pico_stdlib)

pico_enable_stdio_usb(read_ultrasonic 0)
pico_enable_stdio_uart(read_ultrasonic 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(read_ultrasonic)
