cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)
set( SOURCES ../library/pwm_helpers.c melody_doraemon.c )

project(melody_doraemon)

pico_sdk_init()

add_executable(melody_doraemon
        melody_doraemon.c
        ../library/pwm_helpers.c
)

target_link_libraries(melody_doraemon 
        hardware_pwm
	pico_stdlib 
)

pico_enable_stdio_usb(melody_doraemon 0)
pico_enable_stdio_uart(melody_doraemon 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(melody_doraemon)
