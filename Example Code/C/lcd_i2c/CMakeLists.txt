cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(lcd_main)

pico_sdk_init()

add_executable(lcd_main
        lcd_i2c.c
        lcd_main.c
)

target_link_libraries(lcd_main 
        hardware_i2c
        hardware_gpio
	pico_stdlib 
)

pico_enable_stdio_usb(lcd_main 0)
pico_enable_stdio_uart(lcd_main 1)

# create map/bin/hex file etc.
pico_add_extra_outputs(lcd_main)
