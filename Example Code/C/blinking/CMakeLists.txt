cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(blinking)

pico_sdk_init()

add_executable(blinking
        blinking.c
        )

target_link_libraries(blinking 
	pico_stdlib 
)

pico_enable_stdio_usb(blinking 0)
pico_enable_stdio_uart(blinking 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(blinking)
