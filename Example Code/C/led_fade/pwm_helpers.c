#include "pwm_helpers.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


static uint pwm_pin;
static uint16_t slice = 0;
static uint8_t channel = 0;
static uint32_t top = 0;


void pwm_cfg(uint pin)
{
   // Get static peripheral object.
   pwm_pin = pin;
   gpio_set_function(pwm_pin, GPIO_FUNC_PWM);
   slice = pwm_gpio_to_slice_num(pwm_pin);
   channel = pwm_gpio_to_channel(pwm_pin);


   // Select PWM function for given GPIO.
   gpio_set_function(pwm_pin, GPIO_FUNC_PWM);

} //end pwm_init

void pwm_freq(uint16_t freq)
{
    uint32_t source_hz = clock_get_hz(clk_sys);
   // Set the frequency, making "top" as large as possible for maximum resolution.
   // Maximum "top" is set at 65534 to be able to achieve 100% duty with 65535.
   #define TOP_MAX 65534
   uint32_t div16_top = 16 * source_hz / freq;
   top = 1;
   for (;;) {
       // Try a few small prime factors to get close to the desired frequency.
       if (div16_top >= 16 * 5 && div16_top % 5 == 0 && top * 5 <= TOP_MAX) {
           div16_top /= 5;
           top *= 5;
       } else if (div16_top >= 16 * 3 && div16_top % 3 == 0 && top * 3 <= TOP_MAX) {
           div16_top /= 3;
           top *= 3;
       } else if (div16_top >= 16 * 2 && top * 2 <= TOP_MAX) {
           div16_top /= 2;
           top *= 2;
       } else {
           break;
       } //end if
   } //end for

   if (div16_top < 16) {
      printf("freq too large\n");
   } else if (div16_top >= 256 * 16) {
      printf("freq too small\n");
   } //end if
}


int pwm_duty_u16(uint16_t duty_u16)
{
   // Set duty cycle.
   uint8_t top = 1;
   uint32_t cc = duty_u16 * (top + 1) / 65535;
   pwm_set_chan_level(slice, channel, cc);
   pwm_set_enabled(slice, true); 

   pwm_set_gpio_level(pwm_pin, duty_u16);
   pwm_set_enabled(slice, false); 
}