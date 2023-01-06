
#include <FastLED.h>
// how many number of LEDs in your strip?
#define NUM_LEDS 30

#define DATA_PIN 3
#define CLOCK_PIN 12
#define BRIGHTNESS 100
#define COLOR_ORDER RGB

// Define the array of leds
CRGB leds[NUM_LEDS];
void setup() {
  // FastLED.addLeds<WS2812B, DATA_PIN, COLOR_ORDER>(leds,
  // NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}
// a program that draws a circle
void loop() {
  // turn on all LEDs in a circular pattern
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::White; // set LED to white
    FastLED.show();        // update the LEDs
    delay(100);            // delay for 100 milliseconds
  }

  // turn off all LEDs in a circular pattern
  for (int i = NUM_LEDS - 1; i >= 0; i--) {
    leds[i] = CRGB::Black; // turn LED off
    FastLED.show();        // update the LEDs
    delay(100);            // delay for 100 milliseconds
  }
}
