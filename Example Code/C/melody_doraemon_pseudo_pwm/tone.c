#include <stdio.h>
#include "pico/stdlib.h"
#include <math.h>
#include "tone.h"

// char *notes [12] = {"C ","C#","D ","D#","E ","F ","F#","G ","G#","A ","A#","B "};


// converts from MIDI note number to string
// example: NoteToName(12)='C 1'
// char *NoteToName(n:integer)
// {
//     char *result;
//     if ((n >= 0) && (n <= 119)
//         result = notes[n % 12] + inttostr(n / 12);
//     else 
//         result = "---";
// }


//This is doing a pseudo PWM by turning a pin on and off
//very rapidly.
void tone(uint8_t pin, uint8_t midi_note, float duration)
{
    uint32_t pulse_start, pulse_end;
    double pulse_duration;
    uint16_t ui_frequency;
    float frequency;

    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT); 
  
    frequency  =  pow(2.0, ((midi_note - 69.0) / 12.0)) * 440.0;
    ui_frequency = (uint16_t) frequency;
    pulse_start = time_us_32 ();

    while(true)
    {
        pulse_end = time_us_32 ();
        pulse_duration = (double) (pulse_end - pulse_start);
        
        if (midi_note != 0)
        {
            gpio_put(18, 1);
            sleep_us(500000 / frequency);
            gpio_put(18, 0); 
            sleep_us(500000 / frequency);
        } //end if

        if (pulse_duration  >= (1000000 * duration))
            break;  
    } //end while

} //end tone