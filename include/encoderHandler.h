#pragma once

#include <arduino.h>
#include <Encoder.h>

class EncoderHandler
{
    public:
        EncoderHandler();
        EncoderHandler(uint8_t, uint8_t);
        void setup();
        void read();
    private:
        Encoder* _encoder;
        uint8_t _pin1;
        uint8_t _pin2;
        long _previousState;
};