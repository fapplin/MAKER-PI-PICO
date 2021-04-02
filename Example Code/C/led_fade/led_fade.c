#include "../library/pwm_helpers.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    uint8_t LED_PIN = 10;

   stdio_init_all(); //print things to the console

   while(1)
   {
        // fade in
        // from 0 to 10000
        for (int i = 0; i < 10000; i++) 
        {               
            set_pwm_pin(LED_PIN, 5000, i);   //duty cycle from 0 to 10000
            sleep_us(500);                     //sleep 1 microsecond
            pwm_deinit();
        } //end for
            
        //fade out
        for (int i = 10000; i > 0; i--) 
        {               
            set_pwm_pin(LED_PIN, 5000, i);   //duty cycle from 0 to 10000
            sleep_us(500);                     //sleep 1 microsecond
            pwm_deinit();
        } //end for
   } //end while

   return 0;

} //end main