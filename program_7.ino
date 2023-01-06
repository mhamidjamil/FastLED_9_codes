
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

// A program that plays a 5 second light show that repeats. Must contain at
// least three different actions using all of the lights.
void loop() {
  // action 1: fade all LEDs from red to blue over the course of 1 second
  for (int i = 0; i < 256; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j].setRGB(255 - i, i, 0); // fade from red to blue
    }
    FastLED.show(); // update the LEDs
    delay(4);       // delay for 4 milliseconds
  }

  // action 2: blink all LEDs white for 0.2 seconds, then off for 0.2 seconds
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j] = CRGB::White; // set all LEDs to white
    }
    FastLED.show(); // update the LEDs
    delay(200);     // delay for 200 milliseconds

    for (int j = 0; j < NUM_LEDS; j++) {
      leds[j] = CRGB::Black; // turn all LEDs off
    }
    FastLED.show(); // update the LEDs
    delay(200);     // delay for 200 milliseconds
  }

  // action 3: chase a single green LED down the strip
  for (int i = 0; i < NUM_LEDS; i++) {
    for (int j = 0; j < NUM_LEDS; j++) {
      if (j == i) {
        leds[j] = CRGB::Green; // turn current LED green
      } else {
        leds[j] = CRGB::Black; // turn all other LEDs off
      }
    }
    FastLED.show(); // update the LEDs
    delay(100);     // delay for 100 milliseconds
  }
}