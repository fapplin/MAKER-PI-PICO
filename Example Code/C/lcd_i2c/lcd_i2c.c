#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"

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




#define     I2C_ADDR                0x3E
static uint8_t lcd_row, lcd_col;
static uint8_t i2c_flag;

void lcd_command(uint8_t value)
{
    int ret_code;
    uint8_t buf[2];

    buf[0] = 0x80;
    buf[1] = value;
    if (i2c_flag == 1) {
        ret_code = i2c_write_blocking(i2c1, I2C_ADDR, buf, 2, false);
    }
    if (i2c_flag == 0) {
        ret_code = i2c_write_blocking(i2c0, I2C_ADDR, buf, 2, false);
    }
    sleep_ms(1);
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
        lcd_set_cursor(0,0);
} //end lcd_clear

void lcd_write_one(unsigned char s)
{
    uint8_t buf[2];

    sleep_ms(10);
    buf[0] = 0x40;
    buf[1] = s;

    if (i2c_flag == 1) 
    {
        i2c_write_blocking(i2c1, I2C_ADDR, buf, 2, false);
    } //end if

    if (i2c_flag == 0) 
    {
        i2c_write_blocking(i2c0, I2C_ADDR, buf, 2, false);
    } //end if

    lcd_col = lcd_col + 1;
    if (lcd_col >= COLUMNS)
        lcd_set_cursor(0, lcd_row + 1);
} //end lcd_write

void lcd_write(char *s)
{
    uint8_t buf[2]; 
    for (int i = 0; i < strlen(s); i++)
    {
        sleep_ms(10);
        buf[0] = 0x40;
        buf[1] = s[i];

        if (i2c_flag == 1) 
        {
            i2c_write_blocking(i2c1, I2C_ADDR, buf, 2, false);
        } //end if
        
        if (i2c_flag == 0) 
        {
            i2c_write_blocking(i2c0, I2C_ADDR, buf, 2, false);
        } //end if
        
        lcd_col = lcd_col + 1;
        if (lcd_col >= COLUMNS)
            lcd_set_cursor(0, lcd_row + 1);
    } //end for
} //end lcd_write

 
void lcd_init(uint8_t sda, uint8_t scl)
{
    uint ret_code;

    lcd_row = 0;
    lcd_col = 0;
    
    if ((scl == 3) || (scl == 7) || (scl == 11) || (scl == 15) || (scl == 19) || (scl == 27))
        i2c_flag = 1;
    else
        i2c_flag = 0;


    if (i2c_flag == 1)
        ret_code = i2c_init(i2c1, 400000);

    if (i2c_flag == 0)
        ret_code = i2c_init(i2c0, 400000);


    gpio_set_function(sda, GPIO_FUNC_I2C);
    gpio_set_function(scl, GPIO_FUNC_I2C);

    gpio_pull_up(sda);
    gpio_pull_up(scl);

    sleep_ms(50);
        
    for (int i = 0; i < 3; i++)
    { 
        lcd_command(FUNCTIONSET | _2LINE);
        sleep_ms(10);
    } //end for
        
    lcd_on(false, false);
    lcd_clear();
        
    lcd_command(ENTRYMODESET | ENTRYLEFT | ENTRYSHIFTDECREMENT);
        
    lcd_set_cursor(0,0);
} //end lcd_init
