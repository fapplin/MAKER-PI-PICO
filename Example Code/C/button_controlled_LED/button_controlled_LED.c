#include "pico/stdlib.h"

int main() 
{
    // Button Controlled LED
    
    gpio_init(20);              // set pin 20 as INPUT with PULL_UP
    gpio_set_dir(20, GPIO_IN);
    gpio_pull_up(20);

    uint led = 25;              // set pin 25 as OUTPUT
    gpio_init(led);
    gpio_set_dir(led, GPIO_OUT);

    while (true) 
    {
        if (gpio_get(20) == 0)    // if button is pressed
            gpio_put(led, 1);     // turn on the LED
        else
            gpio_put(led, 0);   

    } //end while

    return 0;
} //end main
