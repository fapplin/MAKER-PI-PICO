/*

NeoPixel LEDs
modified on 7 May 2019
by Saeed Hosseini @ Electropeak
https://electropeak.com/learn/

*/

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN        28
#define NUMPIXELS 1


Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() 
{
  pixels.begin();
}

void loop() 
{
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0xff, 0, 0));  // Red
  delay(500);
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(0, 0xff, 0));  // Green
  delay(500);
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0xff));  // Blue
  delay(500);
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(0xff, 0xff, 0));  // Purple
  delay(500);
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(0, 0xff, 0xff));  // Cyan
  delay(500);
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(0xff, 0xff, 0xff));  // White
  delay(500);
  pixels.show();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));  // Black or off
  delay(500);
  pixels.show();

}
