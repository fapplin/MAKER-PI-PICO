#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "lcd_i2c.h"

//PINS
//LCD - Pico
//SDA - GP2
//SCK - GP3
//VDD - 3V3
//VSS - GND


int main() 
{
    stdio_init_all();

    lcd_init(2, 3);     //Create LCD object with LCD's sda pin connected to 
                        //PICO's sda pin 2, LCD's sck pin connected to Pico's 
                        //scl pin 3
    lcd_set_cursor(0,0);
    lcd_write("Hello World!"); 

} //end main
