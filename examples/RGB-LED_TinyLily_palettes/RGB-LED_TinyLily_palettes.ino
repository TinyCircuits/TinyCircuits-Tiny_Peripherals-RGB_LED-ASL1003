#include <FastLED.h>

#define LED_PIN     3
#define NUM_LEDS    22
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 100

CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 myPalette;
extern const TProgmemPalette16 myPalette_p PROGMEM;

int brightness = 20; //value from 0-255 to manipulate brightness

void setup() {
  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
  //pinMode(DATA_PIN, OUTPUT);
  currentPalette = HeatColors_p;
  currentBlending = LINEARBLEND;
}

void loop() {
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */
    
  FillLEDsFromPaletteColors( startIndex);
    
  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
    uint8_t brightness = 255;
    
    for( int i = 0; i < NUM_LEDS; i++) {
        leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
}

const TProgmemPalette16 myPalette_p PROGMEM =
{
    CRGB::White,
    CRGB::Gray, // 'white' is too bright compared to red and blue
    CRGB::Black,
    CRGB::DarkGreen,
    
    CRGB::Green,
    CRGB::Purple,
    CRGB::Green,
    CRGB::Purple,
    
    CRGB::Green,
    CRGB::Green,
    CRGB::Red,
    CRGB::Red,
    CRGB::Blue,
    CRGB::Blue,
    CRGB::Yellow,
    CRGB::Yellow
};
