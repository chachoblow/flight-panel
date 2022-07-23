#include <Arduino.h>
#include "rockerHandler.h"
#include "encoderHandler.h"

const uint8_t BUTTON_PIN = 0;
const uint8_t SWITCH_PIN = 1;
const uint8_t ENCODER_PIN_1 = 4;
const uint8_t ENCODER_PIN_2 = 5;

RockerHandler rocker1(2, 3);
RockerHandler rocker2(11, 12);

EncoderHandler encoder1(4, 5);
EncoderHandler encoder2(6, 7);
EncoderHandler encoder3(9, 10);

uint8_t previousSwitchState;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(SWITCH_PIN, INPUT_PULLUP);

    rocker1.setup();
    rocker2.setup();

    encoder1.setup();
    encoder2.setup();
    encoder3.setup();

    previousSwitchState = digitalRead(SWITCH_PIN);
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

void loop() {
    readButtonPin();
    readSwitchPin();

    rocker1.read();
    rocker2.read();

    encoder1.read();
    encoder2.read();
    encoder3.read();
}