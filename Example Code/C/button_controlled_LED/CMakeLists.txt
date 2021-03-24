cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(button_controlled_LED)

pico_sdk_init()

add_executable(button_controlled_LED
        button_controlled_LED.c
        )

target_link_libraries(button_controlled_LED 
	pico_stdlib 
)

pico_enable_stdio_usb(button_controlled_LED 0)
pico_enable_stdio_uart(button_controlled_LED 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(button_controlled_LED)
