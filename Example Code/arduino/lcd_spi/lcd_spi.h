#ifndef lcd_i2c_h
#define lcd_i2c_h

void lcd_command(uint8_t value);
void lcd_on(const bool cursor, const bool blink);
void lcd_off();
void lcd_set_cursor(uint8_t column, uint8_t row);
void lcd_clear();
void lcd_write(char *s);
void lcd_init(uint8_t cs);

#endif
