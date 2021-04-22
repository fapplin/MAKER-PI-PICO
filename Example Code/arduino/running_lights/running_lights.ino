void setup() 
{
  // RUNNING LIGHT
  for (uint x = 0; x < 29; x++) // from 0 to 28 
  {
    if (x == 23 || x == 24)   // pin 23 and 24 are not GPIO pins
      continue;
    pinMode(x, OUTPUT);
  } //end for
} //end setuo

void loop() 
{
  for (uint x = 0; x < 29; x++)
  {
    if (x == 23 || x == 24) 
      continue;
    digitalWrite(x, LOW);
    delay(100);  // sleep for 100ms
    digitalWrite(x, HIGH);
  } //end for

  for (uint x = 28; x > 0; x--) // from 28 to 0
  {
    if (x == 23 || x == 24) 
      continue;
    digitalWrite(x, HIGH); // turn on the LED
    delay(100);
    digitalWrite(x, LOW);  // turn off the LED
  } //end for
} //end loop
