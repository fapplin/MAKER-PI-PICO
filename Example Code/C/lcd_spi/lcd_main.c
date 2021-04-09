#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico/binary_info.h"
#include "lcd_spi.h"

//PINS
//LCD - Pico
//SDA - GP3
//SCK - GP2
//PSS - GND
//CS  - GP5
//VDD - 3V3
//VSS - GND


int main() 
{
    stdio_init_all();

    lcd_init(2, 3, 5);      
    lcd_set_cursor(0,0);
    lcd_write("SPI Hello World!"); 

} //end main