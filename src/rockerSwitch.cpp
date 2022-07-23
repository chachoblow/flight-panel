#include "rockerSwitch.h"

RockerSwitch::RockerSwitch() = default;

RockerSwitch::RockerSwitch(uint8_t pin1, uint8_t pin2)
{
    _pin1 = pin1;
    _pin2 = pin2;
    _lastDebounceTime = 0;
}

void RockerSwitch::setup()
{
    pinMode(_pin1, INPUT_PULLUP);
    pinMode(_pin2, INPUT_PULLUP);
    _previousState1 = digitalRead(_pin1);
    _previousState2 = digitalRead(_pin2);
}

void RockerSwitch::read()
{
    uint8_t pin1Reading = digitalRead(_pin1);
    uint8_t pin2Reading = digitalRead(_pin2);

    if (pin1Reading != _previousState1 || pin2Reading != _previousState2)
    {
        _lastDebounceTime = millis();
    }

    bool debounceIntervalExceeded = millis() - _lastDebounceTime > DEBOUNCE_DELAY;
    bool currentStateChanged = pin1Reading != _currentState1 || pin2Reading != _currentState2;
    if (debounceIntervalExceeded && currentStateChanged)
    {
        _currentState1 = pin1Reading;
        _currentState2 = pin2Reading;

        if (_currentState1 == LOW) 
        {
            Serial.println("Rocker switch pin 1 LOW");
        }
        else if (_currentState2 == LOW)
        {
            Serial.println("Rocker switch pin 2 LOW");
        }
        else 
        {
            Serial.println("Rocker switch pin NONE");
        }
    }

    _previousState1 = pin1Reading;
    _previousState2 = pin2Reading;
}