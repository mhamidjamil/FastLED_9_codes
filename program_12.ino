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
  int NUM_ROWS = 8; // number of rows in the grid
  int NUM_COLS = 8; // number of columns in the grid
  // clear the grid
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  static int row = 0; // current row of the light
  static int col = 0; // current column of the light
  static int dir = 1; // direction the light is moving (1 for down and right, -1
                      // for up and left)

  // update the position of the light
  row += dir;
  col += dir;
  if (row == NUM_ROWS - 1 || row == 0) {
    // reached the end of a row, change direction
    dir *= -1;
  }
  if (col == NUM_COLS - 1 || col == 0) {
    // reached the end of a column, change direction
    dir *= -1;
  }

  // set the current LED to white
  leds[row * NUM_COLS + col] = CRGB::White;

  FastLED.show(); // update the LEDs
  delay(100);     // delay for 100 milliseconds
}
