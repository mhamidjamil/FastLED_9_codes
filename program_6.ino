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
// A program that lights up one light at a time to give the appearance of a
// moving light that travels around your loop.
// Each time completes one round it speeds up. Must complete the circle at
// least 10 times.
void loop() {
  // to enjoy effect you must place strip in a circle
  int delayTime = 100;
  for (int attempt = 0; attempt < 10; attempt++) {

    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
      FastLED.show();
      delay(delayTime);
      leds[i] = CRGB::Black;
    }
    // for (int i = NUM_LEDS; i > 0; i--) {
    //   leds[i] = CRGB::Red;
    //   FastLED.show();
    //   delay(delayTime);
    //   leds[i] = CRGB::Black;
    // }
    delayTime = delayTime - 10;
  }
}