#include "pico/stdlib.h"

static uint toggle_flag = 0; //flag to aid in toggling the pin

void toggle(uint pin)
{
	gpio_put(pin, toggle_flag);
	toggle_flag = ~toggle_flag;
} //end toggle

int main() {

    gpio_init(10);
    gpio_set_dir(10, GPIO_OUT); // set pin 10 as OUTPUT

    while (true) {
        toggle(10);     // toggle LED
        sleep_ms(500);  // sleep 500ms
    } //end while

    return 0;
} //end main
