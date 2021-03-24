#include "pico/stdlib.h"
#include "hardware/gpio.h"

int main() 
{

	stdio_init_all();

	// RUNNING LIGHT
	for (uint x = 0; x < 29; x++)	// from 0 to 28 
	{
		if (x == 23 || x == 24) 	// pin 23 and 24 are not GPIO pins
			continue;
		gpio_init(x);
		gpio_set_dir(x, GPIO_OUT);	// set the pins to output
	}


	while(true)
	{
		for (uint x = 0; x < 29; x++)
		{
			if (x == 23 || x == 24) continue;
			gpio_put(x, 0);	// turn off the LED
			sleep_ms(100);	// sleep for 100ms
			gpio_put(x, 1);	// turn on the LED
		} //end for

		for (uint x = 28; x > 0; x--)	// from 28 to 0
		{
			if (x == 23 || x == 24) continue;
			gpio_put(x, 1);	// turn on the LED
			sleep_ms(100);
			gpio_put(x, 0);	 // turn off the LED
		} //end for
	} //end while

	return 0;
} //end main