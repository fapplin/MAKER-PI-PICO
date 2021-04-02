typedef struct melody
{
   uint8_t midi_note;
   uint8_t note_length;
} melody;

#define MAX_NOTES 80

//Mario melody using midi notes
//{note, note_length} - rest is 0
melody my_melody[MAX_NOTES] = {
         {100, 4}, {100, 4}, {0, 4}, {100, 4}, {0, 4}, {96, 4}, {100, 4}, {0, 4}, {103, 4},  {0, 4}, {0, 4}, {0, 4},
         {91, 4}, {0, 4}, {0, 4}, {96, 4}, {0, 4}, {0, 4}, {91, 4}, {0, 4}, {0, 4}, {88, 4}, {0, 4}, {0, 4}, 
         {93, 4}, {0, 4}, {95, 4}, {0, 4}, {94, 4}, {93, 4}, {0, 4}, {91, 4}, {100, 4}, {0, 4}, {103, 4}, {105, 4},
         {0, 4}, {101, 4}, {103, 4}, {0, 4}, {100, 4}, {0, 4}, {96, 4}, {98, 4}, {95, 4}, {0, 4}, {0, 4}, {96, 4}, {0, 4},
         {0, 4}, {91, 4}, {0, 4}, {0, 4}, {88, 4}, {0, 4}, {0, 4}, {93, 4}, {0, 4}, {96, 4}, {0, 4}, {94, 4}, {93, 4},
         {0, 4}, {91, 4}, {100, 4}, {0, 4}, {103, 4}, {105, 4}, {0, 4}, {101, 4}, {103, 4}, {0, 4}, {100, 4}, {0, 4}, {96, 4},
         {98, 4}, {95, 4}, {0, 4}, {0, 4}
};
