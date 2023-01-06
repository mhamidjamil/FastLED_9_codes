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
  int NUM_COLS = 8;
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  // Keep going until the entire grid is filled
  while (true) {
    // Choose a random color
    CRGB color = CRGB(random(256), random(256), random(256));

    // Choose a random number of LEDs for the shape (between 1 and 8)
    int shape_size = random(1, 9);

    // Choose a random starting position for the shape
    int x = random(NUM_COLS - shape_size + 1);
    int y = 0;

    // Set the LEDs in the shape to the chosen color
    for (int i = 0; i < shape_size; i++) {
      int index = y * NUM_COLS + x + i;
      leds[index] = color;
    }

    // Show the changes on the LED grid
    FastLED.show();

    // Delay for a moment before moving on to the next shape
    delay(1000);

    // Move the shape down one row
    y++;

    // If the shape has reached the bottom of the grid, break out of the loop
    if (y == NUM_ROWS) {
      break;
    }
  }
}