#include <Arduino.h>
#include <NeoPixelBus.h>

//Switch setup
const uint8_t switchPin = 0;

//NeoPixel Setup
const uint16_t PixelCount = 5;
const uint8_t PixelPin = 2;
#define brightness 0.7 // Between 0 and 1
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

// Set rgb colours
RgbColor white(255 * brightness);
RgbColor red(255 * brightness,0,0);
RgbColor green(0,255 * brightness,0);
RgbColor blue(0,0,255 * brightness);
RgbColor black(0);

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  // put your setup code here, to run once:
}

void loop() {
  if (digitalRead(switchPin)) {
    // Switch high static white light
    strip.SetPixelColor(0, white);
    for (uint8_t i = 1; i < PixelCount; i++) {
      strip.SetPixelColor(i, black);
    }
    strip.Show();
    delay(100);
  } else {
    //switch low colour change

  }
}