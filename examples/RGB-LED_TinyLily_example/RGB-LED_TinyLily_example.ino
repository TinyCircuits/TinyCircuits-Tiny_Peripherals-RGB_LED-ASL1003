#include <FastLED.h>
#define NUM_LEDS 1 //this is the number of LEDs in your strip
#define DATA_PIN 1 //this is the number on the silkscreen you want to use
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];

int brightness = 20; //value from 0-255 to manipulate brightness

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  pinMode(DATA_PIN, OUTPUT);
}

void loop() {
  for(int i = 0; i < 256; i++) {
    //fill_rainbow(targetArray, numToFill, initialHue, deltaHue);
    fill_rainbow(leds, NUM_LEDS, i, 256/NUM_LEDS);
    FastLED.show(); //update the LEDs
    //delay(100); //optional delay for slower fading
  }
}
