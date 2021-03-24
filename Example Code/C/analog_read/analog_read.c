#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

int main() {

    stdio_init_all(); //print things to the console

    adc_init();
    // set GP26 as analog input pin
    // Make sure GPIO is high-impedance, no pullups etc
    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_select_input(0);

    while (true) {
	printf("%d\n", adc_read());     // print analog value to serial
        sleep_ms(50);               // sleep for 50ms, then repeat.
    } //end while

    return 0;
} //end main
