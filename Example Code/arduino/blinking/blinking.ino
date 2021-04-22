
static uint toggle_flag = 0; //flag to aid in toggling the pin

void toggle(uint pin)
{
  gpio_put(pin, toggle_flag);
  toggle_flag = ~toggle_flag;
} //end toggle


void setup() 
{
    pinMode(10, OUTPUT); 
} //end setup


void loop() 
{
  toggle(10);     // toggle LED
  delay(500);     // sleep 500ms                      
} //end loop
