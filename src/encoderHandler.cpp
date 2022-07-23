#include "encoderHandler.h"

EncoderHandler::EncoderHandler() = default;

EncoderHandler::EncoderHandler(uint8_t pin1, uint8_t pin2)
{
    _pin1 = pin1;
    _pin2 = pin2;
    _encoder = new Encoder(_pin1, _pin2);
    _previousState = -999;
}

void EncoderHandler::setup()
{
    _previousState = _encoder->read();
}

void EncoderHandler::read()
{
    long reading = _encoder->read();

    if (reading != _previousState && reading % 4 == 0)
    {
        if (reading > _previousState)
        {
            Serial.println("Encoder increased");
        }
        else
        {
            Serial.println("Encoder decreased");
        }
        _previousState = reading;
    }
}