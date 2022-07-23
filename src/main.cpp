#include <Arduino.h>
#include <Encoder.h>
#include "rocker.h"

const uint8_t BUTTON_PIN = 0;
const uint8_t SWITCH_PIN = 1;
const uint8_t ENCODER_PIN_1 = 4;
const uint8_t ENCODER_PIN_2 = 5;

Rocker rocker1(2, 3);
Rocker rocker2(11, 12);

Encoder encoder(ENCODER_PIN_1, ENCODER_PIN_2);
Encoder encoder2(6, 7);
Encoder encoder3(9, 10);
long previousEncoderPosition = -999;
long previousEncoderPosition2 = -999;
long previousEncoderPosition3 = -999;

uint8_t previousSwitchState;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(SWITCH_PIN, INPUT_PULLUP);

    rocker1.setup();
    rocker2.setup();

    previousSwitchState = digitalRead(SWITCH_PIN);
    previousEncoderPosition = encoder.read();
    previousEncoderPosition2 = encoder.read();
    previousEncoderPosition3 = encoder.read();
}

void readButtonPin()
{
    if (!digitalRead(BUTTON_PIN))
    {
        Serial.println("Button pressed");
    }
}

void readSwitchPin()
{
    const uint8_t switchPin = digitalRead(SWITCH_PIN);
    if (switchPin != previousSwitchState)
    {
        if (switchPin)
        {
            Serial.println("Switch turned on");
        }
        else 
        {
            Serial.println("Switch turned off");
        }
        previousSwitchState = switchPin;
    } 
}

void readEncoderPin()
{
    long encoderPosition = encoder.read();

    if (encoderPosition != previousEncoderPosition && encoderPosition % 4 == 0)
    {
        if (encoderPosition > previousEncoderPosition)
        {
            Serial.println("Encoder increased");
        }
        else 
        {
            Serial.println("Encoder decreased");
        }
        previousEncoderPosition = encoderPosition;
    }

    encoderPosition = encoder2.read();

    if (encoderPosition != previousEncoderPosition2 && encoderPosition % 4 == 0)
    {
        if (encoderPosition > previousEncoderPosition2)
        {
            Serial.println("Encoder 2 increased");
        }
        else 
        {
            Serial.println("Encoder 2 decreased");
        }
        previousEncoderPosition2 = encoderPosition;
    }

    encoderPosition = encoder3.read();

    if (encoderPosition != previousEncoderPosition3 && encoderPosition % 4 == 0)
    {
        if (encoderPosition > previousEncoderPosition3)
        {
            Serial.println("Encoder 3 increased");
        }
        else 
        {
            Serial.println("Encoder 3 decreased");
        }
        previousEncoderPosition3 = encoderPosition;
    }
}

void loop() {
    readButtonPin();
    readSwitchPin();
    readEncoderPin();

    rocker1.read();
    rocker2.read();
}