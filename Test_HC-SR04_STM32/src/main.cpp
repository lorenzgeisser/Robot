#include <Arduino.h>
#include <HCSR04.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TRIG_PIN PB12
#define ECHO_PIN_RIGHT PB13
#define ECHO_PIN_FRONT PB14
#define ECHO_PIN_LEFT PB15
#define TEMPERATURE_ULTRASONIC 20
#define MAX_DISDANCE_ULTRASONIC 300

HCSR04 ultrasonicSensorRight(TRIG_PIN, ECHO_PIN_RIGHT, TEMPERATURE_ULTRASONIC, MAX_DISDANCE_ULTRASONIC);
HCSR04 ultrasonicSensorFront(TRIG_PIN, ECHO_PIN_FRONT, TEMPERATURE_ULTRASONIC, MAX_DISDANCE_ULTRASONIC);
HCSR04 ultrasonicSensorLeft(TRIG_PIN, ECHO_PIN_LEFT, TEMPERATURE_ULTRASONIC, MAX_DISDANCE_ULTRASONIC);

Adafruit_SSD1306 display(128, 32, &Wire, -1);

void setup()
{
    ultrasonicSensorRight.begin();
    ultrasonicSensorFront.begin();
    ultrasonicSensorLeft.begin();

    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Start:");
    display.display();

    delay(3000);
}

void loop()
{
    delay(100);
    float distaanceRight = ultrasonicSensorRight.getDistance();
    delay(100);
    float distaanceFront = ultrasonicSensorFront.getDistance();
    delay(100);
    float distaanceLeft = ultrasonicSensorLeft.getDistance();

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(distaanceRight);
    display.println(" cm");
    display.print(distaanceFront);
    display.println(" cm");
    display.print(distaanceLeft);
    display.println(" cm");
    display.display();

    delay(500);
}
