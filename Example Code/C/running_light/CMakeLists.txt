cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(running_light)

pico_sdk_init()

add_executable(running_light
        running_light.c
        )

target_link_libraries(running_light 
	pico_stdlib 
)

pico_enable_stdio_usb(running_light 0)
pico_enable_stdio_uart(running_light 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(running_light)
