I don't need to re-invent the wheel for this one. Cytron has a library that works. Simply download the .ZIP,
extract it to a directory, and then copy the directory:

Arduino_LCD-I2C_library

into your Arduino/Libraries directory (i.e. arduino-1.8.13/libraries/)

You should connect your Pico to the LCM1602A-14 module as follows:

```
LCM1602A-14            Maker Pi Pico
VSS                    GND
VDD                    3V3
SDA                    GP6
SCK                    GP7
```
https://github.com/CytronTechnologies/LCM1602-14_LCD_Library_Arduino
