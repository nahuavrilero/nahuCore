#include <nahuButton.h>
#include <Arduino.h>

NahuButton::NahuButton(const NahuButtonConfig& config):_config(config){}
NahuButton::NahuButton(uint8_t pin){
    _config.pin = pin;
}

NahuButton::NahuButton(uint8_t pin, ButtonMode mode){
    _config.pin = pin;
    _config.mode = mode;

}
void NahuButton::begin(){
    switch (_config.mode)
    {
    case ButtonMode::pullup:
        pinMode(_config.pin, INPUT_PULLUP);
        break;
    case ButtonMode::pulldown:
        pinMode(_config.pin, INPUT_PULLDOWN);
        break;
    case ButtonMode::notset:
        pinMode(_config.pin, INPUT);
    default:

        break;
    }
}
bool NahuButton::readPin(){
    bool val;
    val = digitalRead(_config.pin);
    return _config.activeLow ? !val : val;

}

void NahuButton::setActiveLow(bool activeLow){
    _config.activeLow = activeLow;
}
void NahuButton::setLongPressTime(uint32_t time){
    _config.longPressTime = time;
}
void NahuButton::setDebounceTime(uint32_t time){
    _config.debounceTime = time;
}


bool NahuButton::wasPressed(){
   return _pressedEvent;
}
bool NahuButton::wasReleased(){
   return _releasedEvent;
}
bool NahuButton::isPressed(){
    return _stablePressed;
}
bool NahuButton::wasClicked(){
    return _clickedEvent;
}
bool NahuButton::wasLongPressed(){
    return _longPressedEvent;
}