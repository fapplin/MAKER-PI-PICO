#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/time.h"

#define trig  6
#define echo  7

long read_ultrasonic() 
{
    uint32_t pulse_start, pulse_end;
    long pulse_duration, distance, micros;    

    gpio_put(trig, 0);
    sleep_us(2);  
    gpio_put(trig, 1);
    sleep_us(10);  
    gpio_put(trig, 0);

    while(!gpio_get(echo))
       pulse_start = time_us_32 ();

    
    while(gpio_get(echo))
       pulse_end = time_us_32 ();

    pulse_duration = (pulse_end - pulse_start);
    distance = pulse_duration / 58;

    return distance;
} //end read_ultrasonic


int main() {

    stdio_init_all(); //print things to the console

    
    gpio_init(trig);    //Connect Trig pin to pin 6 and set to OUTPUT
    gpio_set_dir(trig, GPIO_OUT); 

    gpio_init(echo);    // Connect Echo pin to pin 7 and set to INPUT
    gpio_set_dir(echo, GPIO_IN);

    while (true) {
	    printf("%d\n",  read_ultrasonic());     // print ultrasonic distance
        sleep_ms(1000);                         // sleep 1 second            
    } //end while

    return 0;
} //end main
