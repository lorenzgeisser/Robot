#include <Arduino.h>
#include <HCSR04.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define MOTOR_PIN_RIGHT PA8
#define MOTOR_PIN_LEFT PA9

Adafruit_SSD1306 display(128, 32, &Wire, -1);

void setup()
{
    pinMode(MOTOR_PIN_RIGHT, OUTPUT);
    pinMode(MOTOR_PIN_LEFT, OUTPUT);
    
    analogWrite(MOTOR_PIN_RIGHT, map(10, 0, 100, 0, 0xFF));

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Start:");
    display.display();
}

void loop()
{
}