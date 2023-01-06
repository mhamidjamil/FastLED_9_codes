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
void loop() {
  // clear the LEDs
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  // object falls from the top
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Yellow; // object is yellow
    FastLED.show();         // update the LEDs
    delay(100);             // delay for 100 milliseconds
  }

  // explosion
  for (int i = 0; i < NUM_LEDS / 2; i++) {
    // mushroom shape
    leds[i] = CRGB::Red;
    leds[NUM_LEDS - 1 - i] = CRGB::Red;
    // fade out
    leds[i + 1].fadeToBlackBy(64);
    leds[NUM_LEDS - 2 - i].fadeToBlackBy(64);
    FastLED.show(); // update the LEDs
    delay(100);     // delay for 100 milliseconds
  }

  delay(1000); // delay for 1 second before repeating
}
/*
This program will represent an explosion by first showing an object falling from
the top of the LED strip, then showing an explosion in the form of a mushroom
shape that fades out. This will repeat indefinitely, with a 1 second delay
between each repetition.
*/