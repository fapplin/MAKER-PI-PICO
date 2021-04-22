uint8_t LED_PIN = 10;        

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
} //end setup

void loop() 
{

  // fade in
  // from 0 to 255
  for (int i = 0; i < 255; i++) 
  {               
      analogWrite(LED_PIN, i);   //duty cycle from 0 to 255
      delay(5);                     //sleep 1 microsecond
  } //end for
      
  //fade out
  for (int i = 255; i > 0; i--) 
  {               
      analogWrite(LED_PIN, i);   //duty cycle from 0 to 255
      delay(5);                     //sleep 1 microsecond
  } //end for
} //end loop
