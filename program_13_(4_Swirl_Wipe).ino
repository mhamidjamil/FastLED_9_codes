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

  int NUM_ROWS = 8;          // Number of rows in the grid
  int NUM_COLS = 8;          // Number of columns in the grid
  int dx[4] = {1, 0, -1, 0}; // Offsets for moving in the x direction
  int dy[4] = {0, 1, 0, -1}; // Offsets for moving in the y direction

  // Set all LEDs to black
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  // Start at the center of the grid
  int x = NUM_COLS / 2;
  int y = NUM_ROWS / 2;

  // Set the first LED to red
  int index = y * NUM_COLS + x;
  leds[index] = CRGB::Red;

  // Set the direction to move in to be right
  int direction = 0;

  // Keep track of the number of steps taken
  int steps = 1;

  // Keep track of the number of steps taken in the current direction
  int steps_taken = 0;

  // Keep going until all LEDs have been lit up
  while (true) {
    // Update the position based on the current direction
    x += dx[direction];
    y += dy[direction];

    // Calculate the index of the LED at the new position
    index = y * NUM_COLS + x;

    // If the LED at the new position is out of bounds, break out of the loop
    if (x < 0 || x >= NUM_COLS || y < 0 || y >= NUM_ROWS) {
      break;
    }

    // Set the color of the LED at the new position
    leds[index] = CRGB::Red;

    // Show the changes on the LED grid
    FastLED.show();

    // Delay for a moment before moving on to the next LED
    delay(100);

    // Increment the number of steps taken in the current direction
    steps_taken++;

    // If the number of steps taken in the current direction equals the total
    // number of steps, change direction and reset the steps taken
    if (steps_taken == steps) {
      direction = (direction + 1) % 4; // Change direction
      steps_taken = 0;                 // Reset the steps taken

      // If changing direction to the right or down, increase the number of
      // steps taken
      if (direction == 0 || direction == 1) {
        steps++;
      }
    }
  }
}