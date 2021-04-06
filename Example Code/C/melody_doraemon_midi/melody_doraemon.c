#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "melody.h"

#define UART_ID uart0
#define BAUD_RATE 31250

// We are using pins 0 and 1, but see the GPIO function select table in the
// datasheet for information on which other pins can be used.
#define UART_TX_PIN 0
#define UART_RX_PIN 1

int main(void)
{
    uint8_t MIDIon = 144;
    uint8_t MIDIoff = 128;

    uint8_t midi_note, note_length;
    float tempo = 0.35;
    float sleep_time;

    stdio_init_all(); //print things to the console

    // Set up our UART with the required speed.
    uart_init(UART_ID, BAUD_RATE);

    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

   
    //loop through the melody array of structures and
    //simply transmit it through the UART Tx 
    for (int i = 0; i < MAX_NOTES; i++) 
    {          
        midi_note = my_melody[i].midi_note;
        note_length = my_melody[i].note_length;
        sleep_time = (tempo / (float) note_length);
        
       // Send out 3 bytes: Midi On/Off, midi note, volume
        uart_putc_raw(UART_ID, MIDIon);
        uart_putc_raw(UART_ID, midi_note);
        uart_putc_raw(UART_ID, 127);

        //sleep is based on 1/4 note, 1/2 note, etc.
        sleep_ms(sleep_time * 1000);

        // Send out 3 bytes: Midi On/Off, midi note, volume
        uart_putc_raw(UART_ID, MIDIoff);
        uart_putc_raw(UART_ID, midi_note);
        uart_putc_raw(UART_ID, 127);

        //sleep is based on 1/4 note, 1/2 note, etc.
        sleep_ms(sleep_time * 1000);
    } //end for
  
    return 0;

} //end main