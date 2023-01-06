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
  int NUM_ROWS = 8; // Number of rows in the grid
  int NUM_COLS = 8; // Number of columns in the grid
  // Iterate over each row of the grid
  for (int row = 0; row < NUM_ROWS; row++) {
    // Iterate over each column of the grid
    for (int col = 0; col < NUM_COLS; col++) {
      // Calculate the index of the LED in the array
      int index = row * NUM_COLS + col;

      // Set the color of the LED at the current position
      leds[index] = CRGB::Red;

      // Show the changes on the LED grid
      FastLED.show();

      // Delay for a moment before moving on to the next LED
      delay(100);
    }
  }
}
/*
This code will light up each LED in the grid in sequence from the top down, with
a delay of 100 milliseconds between each LED. The color of the LED will be set
to red, but you can change this to any color you like by using a different color
constant from the CRGB class (e.g. CRGB::Blue for blue, CRGB::Green for green,
etc.).
*/