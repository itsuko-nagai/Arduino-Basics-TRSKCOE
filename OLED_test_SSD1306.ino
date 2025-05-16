// Code for using a 128x32 OLED
// SSD1306 OLED display

#include <Wire.h>  //for I2C
#include <Adafruit_GFX.h>  //graphics library
#include <Adafruit_SSD1306.h>  //OLED driver library

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  if (!display.begin(SSD1306_I2C_ADDRESS, SCREEN_WIDTH, SCREEN_HEIGHT)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); //initialize and debug
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
 
  display.setCursor(0, 0);  // Set text position in terms of (x,y) on the screen axis .... reference given below

  // (0, 0): Top-left corner
  // (127, 0): Top-right corner
  // (0, 63): Bottom-left corner
  // (127, 63): Bottom-right corner

  display.println(F("Hello, OLED!"));
  display.display();
}

void loop() {
  // left blank intentionally
}