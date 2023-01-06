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
  for (int i = 40; i >= 0; i--) {
    // clear the LEDs
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j] = CRGB::Black;
    }

    // display the current number
    if (i >= 10) {
      // display tens digit
      for (int j = 0; j < (i / 10); j++) {
        leds[j] = CRGB::White;
      }
      // display ones digit
      for (int j = 0; j < (i % 10); j++) {
        leds[j + 10] = CRGB::White;
      }
    } else {
      // display ones digit
      for (int j = 0; j < i; j++) {
        leds[j] = CRGB::White;
      }
    }
    FastLED.show(); // update the LEDs

    delay(500); // delay for 500 milliseconds
  }
}
/*
This program will display the numbers 40, 39, 38, ..., 0, with each number
appearing for at least 500 milliseconds. The tens digit is displayed on the
first 10 LEDs and the ones digit is displayed on the next 10 LEDs. If the number
is less than 10, it is displayed on the first 10 LEDs. This will repeat
indefinitely.
*/