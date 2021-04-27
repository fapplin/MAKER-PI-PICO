#include "lcd_spi.h"

//PINS
//LCD - Pico
//SDA - GP3
//SCK - GP2
//PSS - GND
//CS  - GP5
//VDD - 3V3
//VSS - GND

void setup() {
  // put your setup code here, to run once:
   
    lcd_init(5);      //cs - GP5
    lcd_set_cursor(0,0);
    lcd_write("SPI Hello!"); 

}

void loop() {
  // put your main code here, to run repeatedly:

}
