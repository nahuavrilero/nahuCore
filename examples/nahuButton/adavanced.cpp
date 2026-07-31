#include <Arduino.h>
#include <nahuButton.h>

NahuButtonConfig boton1Config;
NahuButton boton1(boton1Config);


void setup(){
    boton1Config.activeLow = true;
    boton1Config.debounceTime = 50; //keep between 20 and 50 milliseconds
    boton1Config.mode = ButtonMode::pullup; //pulldown or notset
    boton1Config.pin = 4;
    boton1.begin();
    Serial.begin(115200);
}
void loop(){
    boton1.update();
    if (boton1.wasClicked()){
        Serial.println("Click detectado.");
    }
    if (boton1.wasPressed()){
        Serial.println("Boton presionado.");
    }
    if (boton1.wasReleased()){
        Serial.println("Boton soltado.");
    }
    if (boton1.isPressed()){
        Serial.println("Presionando");
    }
}
