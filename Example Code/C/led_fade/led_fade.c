#include "pwm_helpers.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   stdio_init_all(); //print things to the console

   pwm_cfg(10);
   pwm_freq(1000);

   while(1)
   {
        // fade in
        // from 0 to 65535
        for (int i = 0; i < 65535; i++) 
        {               
            pwm_duty_u16(i);              //duty cycle from 0 to 65535
            sleep_us(1);                     //sleep 1 microsecond
        } //end for
            
        //fade out
        for (int i = 65535; i > 0; i--) 
        {               
            pwm_duty_u16(i);              //duty cycle from 0 to 65535
            sleep_us(1);                     //sleep 1 microsecond
        } //end for
   } //end while

   return 0;

} //end main