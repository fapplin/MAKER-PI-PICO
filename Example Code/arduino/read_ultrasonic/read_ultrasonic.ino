
#define trig  26
#define echo  18

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

long read_ultrasonic() 
{
  uint32_t pulse_start, pulse_end;
  long pulse_duration, distance, microseconds;    

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  while(digitalRead(echo) == LOW) 
  {
    pulse_start = micros();
  } //end while
  
  while(digitalRead(echo) == HIGH) 
  {
    pulse_end = micros();
  } //end while
    
  pulse_duration = (pulse_end - pulse_start);

  distance = pulse_duration / 58;
  //distance = (duration * 0.0343) / 2;

  return distance;
} //end read_ultrasonic

void setup() 
{
  pinMode(trig, OUTPUT); // Sets the trig as an OUTPUT
  pinMode(echo, INPUT); // Sets the echo as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
} //end setup

void loop() 
{
  Serial.println(read_ultrasonic());
  delay(1000);
} //end loop
