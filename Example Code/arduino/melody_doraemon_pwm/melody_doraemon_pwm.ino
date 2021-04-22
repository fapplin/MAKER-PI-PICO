#include "melody.h"

void play_melody() 
{
    uint8_t BUZZER_PIN = 18;
    uint8_t midi_note, note_length;
    float tempo = 0.65;
    float frequency;
    float sleep_time;
   
    for (int i = 0; i < MAX_NOTES; i++) 
    {          
        midi_note = my_melody[i].midi_note;
        note_length = my_melody[i].note_length;

        frequency  =  pow(2.0, ((midi_note - 69.0) / 12.0)) * 440.0 ;
        sleep_time = (tempo / (float) note_length);
        if (midi_note != 0)
        {
            tone(BUZZER_PIN, frequency, 1000 / note_length);
        } //end if

        delay(sleep_time * 1000);
    } //end for

    
} //end play_melody

void setup() 
{
  play_melody();
} //end setup

void loop() 
{
  // put your main code here, to run repeatedly:

} //end loop
