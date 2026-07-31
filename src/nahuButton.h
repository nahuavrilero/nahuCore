#pragma once
#include <Arduino.h>

enum class ButtonMode{
    pullup, pulldown, notset
};

struct NahuButtonConfig {
    uint32_t debounceTime = 30;
    uint8_t pin;
    uint32_t longPressTime = 1000;
    bool activeLow = true;
    ButtonMode mode = ButtonMode::notset;
};

class NahuButton{
    public:
        explicit NahuButton(uint8_t pin, ButtonMode mode);
        explicit NahuButton(const NahuButtonConfig& config);
        explicit NahuButton(uint8_t pin);
        void begin();
        void setLongPressTime(uint32_t time);
        void setActiveLow(bool activeLow);
        void setDebounceTime(uint32_t time);
        bool isPressed();
        bool wasPressed();

        bool wasLongPressed();
        bool wasReleased();
        bool wasClicked();
        void update();
    private:
        NahuButtonConfig _config;
        uint32_t _lastPressedTime;
        uint32_t _lastRawPressedTime;
        uint32_t _pressedTime;
        

        bool _longPressStarted = false;
        bool _pressedEvent = false;
        bool _releasedEvent = false;
        bool _longPressedEvent = false;
        bool _rawPressed = false;
        bool _lastRawPressed = false;
        bool _stablePressed = false;
        bool _clickedEvent = false;
        bool readPin();

};