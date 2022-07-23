#pragma once

#include <arduino.h>

class RockerHandler
{
    public:
        RockerHandler();
        RockerHandler(uint8_t, uint8_t);
        void setup();
        void read();
    private:
        uint8_t _pin1;
        uint8_t _pin2;
        uint8_t _previousState1;
        uint8_t _previousState2;
        uint8_t _currentState1;
        uint8_t _currentState2;
        unsigned long _lastDebounceTime;
        static const uint8_t DEBOUNCE_DELAY = 50;
};