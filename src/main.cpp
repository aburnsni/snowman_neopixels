#include <Arduino.h>
#include <NeoPixelBus.h>

//Switch setup
const uint8_t switchPin = 5;

//NeoPixel Setup
const uint16_t PixelCount = 5;
const uint8_t PixelPin = 2;
#define brightness 1 // Between 0 and 1
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PixelCount, PixelPin);

// Set rgb colours
RgbColor white(255 * brightness);
RgbColor red(255 * brightness, 0, 0);
RgbColor green(0, 255 * brightness, 0);
RgbColor blue(0, 0, 255 * brightness);
RgbColor purple(255*brightness/2, 0, 255*brightness/2);
RgbColor black(0);

// Timing
unsigned long ledTimer = millis();
const int ledGap = 1 * 1000;
int loopnum = 1;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  // put your setup code here, to run once:
}

void loop() {
  if (digitalRead(switchPin)) {
    // Switch high static white light
    strip.SetPixelColor(4, white);
    for (uint8_t i = 0; i < PixelCount-1; i++) {
      strip.SetPixelColor(i, black);
    }
    strip.Show();
  } else {
    if (millis() > ledTimer + ledGap) {
      switch (loopnum) {
        case 1:
          strip.SetPixelColor(4, black);
          strip.SetPixelColor(0, red);
          strip.SetPixelColor(1, green);
          strip.SetPixelColor(2, blue);
          strip.SetPixelColor(3, black);
          loopnum++;
          break;
        case 2:
          strip.SetPixelColor(4, black);
          strip.SetPixelColor(0, black);
          strip.SetPixelColor(1, red);
          strip.SetPixelColor(2, green);
          strip.SetPixelColor(3, blue);
          loopnum++;
          break;
        case 3:
          strip.SetPixelColor(4, black);
          strip.SetPixelColor(0, blue);
          strip.SetPixelColor(1, black);
          strip.SetPixelColor(2, red);
          strip.SetPixelColor(3, green);
          loopnum++;
          break;
        case 4:
          strip.SetPixelColor(4, black);
          strip.SetPixelColor(0, green);
          strip.SetPixelColor(1, blue);
          strip.SetPixelColor(2, black);
          strip.SetPixelColor(3, red);
          loopnum = 1;
          break;
        default:
          loopnum = 1;
          break;
      }
      strip.Show();
      ledTimer = millis();
    }
  }
  delay(10);
}