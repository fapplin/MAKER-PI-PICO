#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "melody.h"
#include "../library/pwm_helpers.h"


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

#define PWM_MAX 32768

void play_melody() 
{
    uint8_t BUZZER_PIN = 18;
    uint8_t midi_note, note_length;
    float tempo = 0.65;
    float frequency;
    uint ui_frequency;
    float sleep_time;

    //pwm_cfg(BUZZER_PIN);
   
    for (int i = 0; i < MAX_NOTES; i++) 
    {          
        midi_note = my_melody[i].midi_note;
        note_length = my_melody[i].note_length;

        frequency  =  pow(2.0, ((midi_note - 69.0) / 12.0)) * 440.0 ;
        ui_frequency = (uint) frequency ;
        sleep_time = (tempo / (float) note_length);

        if (midi_note != 0)
        {
            set_pwm_pin(BUZZER_PIN, ui_frequency, 5000);
           
        } //end if
        sleep_ms(sleep_time * 1000);
        pwm_deinit();
    } //end for

    
} //end play_melody


int main(void)
{
   
    stdio_init_all(); //print things to the console
    
    play_melody();

    return 0;

} //end main