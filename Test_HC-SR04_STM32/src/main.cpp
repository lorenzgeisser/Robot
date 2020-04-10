#include <Arduino.h>
#include <HCSR04.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 32, &Wire, -1);

HCSR04 ultrasonicSensor1(PB10, PB11, 20, 300);
HCSR04 ultrasonicSensor2(PB13, PB12, 20, 300);
float distance1 = 0;
float distance2 = 0;

void setup()
{

    ultrasonicSensor1.begin();
    
    ultrasonicSensor2.begin();

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
    distance1 = ultrasonicSensor1.getDistance();
    delay(100);
    distance2 = ultrasonicSensor2.getDistance();

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.print(distance1);
    display.println(" cm");
    display.print(distance2);
    display.println(" cm");
    display.display();

    delay(500);
}
