/*Este ejemplo avanzado usa el constructor NahuButtonConfig para configurar el botón.
En el ejemplo basic.cpp usa la version simple. 
La librería puede usar otros dos constructores:
Simple: NahuButton boton1(pin)
Medio: NahuButton boton1(pin, ButtonMode::pullup)
*/

//#include <Arduino.h> //Comentar si usas Arduino IDE, descomentar si usas Platform.IO.
#include <nahuButton.h>

NahuButtonConfig boton1Config;
NahuButton boton1(boton1Config);


void setup(){
    boton1Config.activeLow = true;
    boton1Config.debounceTime = 20; //keep between 20 and 50 milliseconds
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
        Serial.println("Presionando"); //Cuidado! Se cumple siempre mientras el botón está presionado. 
    }
    if (boton1.wasLongPressed()){
        Serial.println("Pulsación larga.");
    }
}
