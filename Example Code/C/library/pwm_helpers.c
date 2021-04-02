#include "../library/pwm_helpers.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


static uint16_t slice = 0;


//This was developed by user martinkooij on the Raspberry Pi forum.
//It allows frequency on a pin to be set between from 50Hz upwards 
//(I didn't try anything larger than 20KHz, but it should work). 
//The duty cycle is an integer between 0 and 10000: 0 = 0%, 5000 = 50%, 
//10000=100%.
void set_pwm_pin(uint pin, uint freq, uint duty_c) { // duty_c between 0..10000
    gpio_set_function(pin, GPIO_FUNC_PWM);
    slice = pwm_gpio_to_slice_num(pin);
    pwm_config config = pwm_get_default_config();
    float div = (float)clock_get_hz(clk_sys) / (freq * 10000);
    pwm_config_set_clkdiv(&config, div);
    pwm_config_set_wrap(&config, 10000); 
    pwm_init(slice, &config, true); // start the pwm running according to the config
    pwm_set_gpio_level(pin, duty_c); //connect the pin to the pwm engine and set the on/off level. 
} //end set_pwm_pin

void pwm_deinit(void) 
{
    pwm_set_enabled(slice, false);
} //end pwm_deinit