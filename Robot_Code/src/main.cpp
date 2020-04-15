// **************** Includes **************** //
#include <Arduino.h>
#include <HCSR04.h>

// **************** Defines ***************** //
// Pins
#define TRIG_PIN PB12
#define ECHO_PIN_RIGHT PB13
#define ECHO_PIN_FRONT PB14
#define ECHO_PIN_LEFT PB15

#define MOTOR_PIN_RIGHT_FORWARD PA8
#define MOTOR_PIN_RIGHT_BACKWARD PA9
#define MOTOR_PIN_LEFT_FORWARD PB8
#define MOTOR_PIN_LEFT_BACKWARD PB9

// Ultrasonic
#define TEMPERATURE_ULTRASONIC 20
#define MAX_DISDANCE_ULTRASONIC 300

// **************** Globals ***************** //
HCSR04 ultrasonicSensorFront(TRIG_PIN, ECHO_PIN_FRONT, TEMPERATURE_ULTRASONIC, MAX_DISDANCE_ULTRASONIC);
float lastDistance = 0;
int counter = 0;

// *************** Functions **************** //
void setup()
{
    ultrasonicSensorFront.begin();

    pinMode(MOTOR_PIN_RIGHT_FORWARD, OUTPUT);
    pinMode(MOTOR_PIN_RIGHT_BACKWARD, OUTPUT);
    pinMode(MOTOR_PIN_LEFT_FORWARD, OUTPUT);
    pinMode(MOTOR_PIN_LEFT_BACKWARD, OUTPUT);

    digitalWrite(MOTOR_PIN_RIGHT_FORWARD, LOW);
    digitalWrite(MOTOR_PIN_RIGHT_BACKWARD, LOW);
    digitalWrite(MOTOR_PIN_LEFT_FORWARD, LOW);
    digitalWrite(MOTOR_PIN_LEFT_BACKWARD, LOW);
}

void loop()
{
    float distanceFront = ultrasonicSensorFront.getDistance();

    if (distanceFront == 38000)
    {
        if (lastDistance < 50)
        {
           distanceFront = 8;
        }
    }
    else
    {
        lastDistance = distanceFront;
    }

    if (distanceFront > 10)
    {
        counter = 0;
        digitalWrite(MOTOR_PIN_RIGHT_FORWARD, HIGH);
        digitalWrite(MOTOR_PIN_LEFT_FORWARD, HIGH);
    }
    else
    {
        digitalWrite(MOTOR_PIN_RIGHT_FORWARD, LOW);
        digitalWrite(MOTOR_PIN_LEFT_FORWARD, LOW);
        counter++;

        if(counter > 20){
            counter = 0;
            digitalWrite(MOTOR_PIN_LEFT_BACKWARD, HIGH);
            delay(1000);
            digitalWrite(MOTOR_PIN_LEFT_BACKWARD, LOW);
        }
    }

    delay(100);
}