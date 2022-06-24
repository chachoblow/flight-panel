#include <Arduino.h>
#include <Encoder.h>

const uint8_t BUTTON_PIN = 0;
const uint8_t SWITCH_PIN = 1;
const uint8_t ROCKER_PIN_1 = 2;
const uint8_t ROCKER_PIN_2 = 3;
const uint8_t ENCODER_PIN_1 = 4;
const uint8_t ENCODER_PIN_2 = 5;

Encoder encoder(ENCODER_PIN_1, ENCODER_PIN_2);
Encoder encoder2(6, 7);
Encoder encoder3(9, 10);
long previousEncoderPosition = -999;
long previousEncoderPosition2 = -999;
long previousEncoderPosition3 = -999;

uint8_t previousSwitchState;
uint8_t previousRocker1State;
uint8_t previousRocker2State;

void setup() {
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    pinMode(ROCKER_PIN_1, INPUT_PULLUP);
    pinMode(ROCKER_PIN_2, INPUT_PULLUP);

    previousSwitchState = digitalRead(SWITCH_PIN);
    previousRocker1State = digitalRead(ROCKER_PIN_1);
    previousRocker2State = digitalRead(ROCKER_PIN_2);
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

void readRockerPin()
{
    uint8_t rockerPin1 = digitalRead(ROCKER_PIN_1);
    uint8_t rockerPin2 = digitalRead(ROCKER_PIN_2);

    if (rockerPin1 != previousRocker1State || rockerPin2 != previousRocker2State)
    {
        if (rockerPin1 == LOW)
        {
            Serial.println("Rocker pin 1 low");
        }
        if (rockerPin2 == LOW)
        {
            Serial.println("Rocker pin 2 low");
        }
        if (rockerPin1 == HIGH && rockerPin2 == HIGH)
        {
            Serial.println("Rocker pin none");
        }
        previousRocker1State = rockerPin1;
        previousRocker2State = rockerPin2;
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
    readRockerPin();
    readEncoderPin();
}