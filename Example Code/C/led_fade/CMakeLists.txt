cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(led_fade)

pico_sdk_init()
set( SOURCES ../library/pwm_helpers.c led_fade.c )

add_executable(led_fade
        led_fade.c
        ../library/pwm_helpers.c
        )

target_link_libraries(led_fade 
        hardware_pwm
	pico_stdlib 
)

pico_enable_stdio_usb(led_fade 0)
pico_enable_stdio_uart(led_fade 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(led_fade)
