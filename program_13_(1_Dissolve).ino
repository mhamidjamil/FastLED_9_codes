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
  bool zero_occupied = false;
  int new_index = 0;
  int array_[NUM_LEDS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < NUM_LEDS; i++) {
    bool index_pinned = false;
    do {
      new_index = random(NUM_LEDS);
      int for_breaker = 0;
      int j = 0;
      for (; j < NUM_LEDS && for_breaker == 0; j++) {
        if (!zero_occupied && new_index == 0) {
          index_pinned = true;
          zero_occupied = true;
          for_breaker = 1;
          array_[j] = new_index;
        } else if (array_[j] == new_index) {
          // index_pinned = true;
          for_breaker = 2;
        } else {
          // continue searching
        }
      }
      if (for_breaker == 0) {
        index_pinned = true;
        array_[j] = new_index;
      }

    } while (!index_pinned);
    leds[new_index] = CRGB::Red; // Set the current LED to red
    FastLED.show();              // Update the LED strip
    delay(100);                  // Delay for 100 milliseconds
  }
}