#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>


#define SDA_OLED_PIN 21 //Data
#define SCL_OLED_PIN 22 //Clock

/* Uncomment the initialize the I2C address , uncomment only one, If you get a totally blank screen try the other*/
#define i2c_Address 0x3c //initialize with the I2C addr 0x3C Typically eBay OLED's
//#define i2c_Address 0x3d //initialize with the I2C addr 0x3D Typically Adafruit OLED's

#define OLED_PIN_RESET 23

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   //   QT-PY / XIAO


Adafruit_SH1106G display = Adafruit_SH1106G(128, 64, &Wire, OLED_PIN_RESET);

void setup() {
    Serial.begin(921600);
    Wire.begin(SDA_OLED_PIN, SCL_OLED_PIN, 400000);
    while(!display.begin(i2c_Address, true)) { // Address 0x3C for 128x64, reset pin 23
        Serial.println(F("SSD1309 allocation failed"));
        delay(250);
    }
    display.display();

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SH110X_WHITE);
    display.setCursor(0,0);
    display.println(F("Hello, world!"));
    display.display();
}

void loop() {
}
