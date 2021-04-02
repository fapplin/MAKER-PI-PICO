cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
set( SOURCES ../library/pwm_helpers.c mario.c )

project(mario)

pico_sdk_init()

add_executable(mario
        mario.c
        ../library/pwm_helpers.c
)

target_link_libraries(mario 
        hardware_pwm
	pico_stdlib 
)

pico_enable_stdio_usb(mario 0)
pico_enable_stdio_uart(mario 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(mario)
