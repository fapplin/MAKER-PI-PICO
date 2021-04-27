#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <SPI.h>
#include "lcd_spi.h"

#define     COLUMNS             16
#define     ROWS                2

//Instruction set
#define     CLEARDISPLAY        0x01

#define     ENTRYMODESET        0x04
#define     ENTRYLEFT           0x02
#define     ENTRYRIGHT          0x00
#define     ENTRYSHIFTINCREMENT  0x01
#define     ENTRYSHIFTDECREMENT  0x00

#define     DISPLAYCONTROL       0x08
#define     DISPLAYON            0x04
#define     DISPLAYOFF           0x00
#define     CURSORON             0x02
#define     CURSOROFF            0x00
#define     BLINKON              0x01
#define     BLINKOFF             0x00

#define     FUNCTIONSET          0x20
#define     _5x10DOTS            0x04
#define     _5x8DOTS             0x00
#define     _1LINE               0x00
#define     _2LINE               0x08
#define     _8BITMODE            0x10
#define     _4BITMODE            0x00




static uint8_t lcd_row, lcd_col;
static uint8_t spi_flag;
static uint8_t cs_pin;
static uint8_t rx_pin;

void lcd_command(uint8_t value)
{
  int buff[2];
  
  buff[0] = 0;
  buff[0] |= value >> 1;
  buff[1] = (value & 1) << 7;
  delayMicroseconds(10000); 
  
  digitalWrite(cs_pin,LOW);
  SPI.transfer(buff[0]);
  SPI.transfer(buff[1]);
  digitalWrite(cs_pin,HIGH);
  delayMicroseconds(1);
} //end lcd_command

void lcd_on(const bool cursor, const bool blink)
{
        if ((cursor == false) && (blink == false))
            lcd_command(DISPLAYCONTROL | DISPLAYON | CURSOROFF | BLINKOFF);
        else if ((cursor == false) && (blink == true))
            lcd_command(DISPLAYCONTROL | DISPLAYON | CURSOROFF | BLINKON);
        else if ((cursor == true) && (blink == false))
            lcd_command(DISPLAYCONTROL | DISPLAYON | CURSORON | BLINKOFF);
        else if ((cursor == true) && (blink == true))
            lcd_command(DISPLAYCONTROL | DISPLAYON | CURSORON | BLINKON);
} //end lcd_on

void lcd_off()
{
    lcd_command(DISPLAYCONTROL | DISPLAYOFF | CURSOROFF | BLINKOFF);
} //end lcd_off

void lcd_set_cursor(uint8_t column, uint8_t row)
{
    uint8_t command;

    column = column % COLUMNS;
    row = row % ROWS;
    if (row == 0)
        command = column | 0x80;
    else
        command = column | 0xC0;

    lcd_row = row;
    lcd_col = column;
    lcd_command(command);
} //end lcd_set_cursor

void lcd_clear()
{
        lcd_command(CLEARDISPLAY);
        delayMicroseconds(2000);
        lcd_set_cursor(0,0);
} //end lcd_clear


void lcd_write(char *s)
{
  int buffs[2];
  uint8_t temp;

  for (int i = 0; i < strlen(s); i++)
  {
    temp = s[i];
    buffs[0] = 0x80;
    buffs[0] |= temp >> 1;
    buffs[1] = (temp & 1) << 7;
    delayMicroseconds(10000);
    digitalWrite(cs_pin,LOW);
    SPI.transfer(buffs[0]);
    SPI.transfer(buffs[1]);
    digitalWrite(cs_pin,HIGH);
    delayMicroseconds(1);   
    lcd_col = lcd_col + 1;
    if (lcd_col >= COLUMNS)
        lcd_set_cursor(0, lcd_row + 1);
  } //end for
} //end lcd_write

void lcd_display() 
{
   lcd_command(DISPLAYCONTROL | DISPLAYON | CURSOROFF | BLINKOFF);
}

void lcd_noDisplay()
{
   lcd_command(DISPLAYCONTROL | DISPLAYOFF | CURSOROFF | BLINKOFF);
}
void lcd_init(uint8_t cs)
{
    lcd_row = 0;
    lcd_col = 0;

    cs_pin = cs;

    // Chip select is active-low, so we'll initialise it to a driven-high state
    pinMode(cs_pin, OUTPUT);
    digitalWrite(cs_pin, HIGH);
    
    SPI.begin();
    
    SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));

    delayMicroseconds(50000);

    lcd_command(FUNCTIONSET | _2LINE);
    delayMicroseconds(10000);
        
    lcd_display();
    delayMicroseconds(40);
    lcd_clear();
    delayMicroseconds(2000);
    lcd_command(ENTRYMODESET | ENTRYLEFT | ENTRYSHIFTDECREMENT);

    lcd_set_cursor(0,0);
} //end lcd_init
