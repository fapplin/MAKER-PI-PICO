#include "pico/stdlib.h"
#include "pico/time.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "melody.h"
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



void play_melody() 
{
    uint8_t BUZZER_PIN = 18;
    uint8_t midi_note, note_length;
    float tempo = 0.65;
    float sleep_time;

   
    for (int i = 0; i < MAX_NOTES; i++) 
    {          
        midi_note = my_melody[i].midi_note;
        note_length = my_melody[i].note_length;
        sleep_time = (tempo / (float) note_length);
        
        tone(BUZZER_PIN, midi_note, sleep_time);
    } //end for

    
} //end play_melody


int main(void)
{
   
    stdio_init_all(); //print things to the console
    
    play_melody();

    return 0;

} //end main