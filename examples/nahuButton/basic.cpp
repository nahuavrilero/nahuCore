#include <Arduino.h>
#include <nahuButton.h>

NahuButton boton1(4,ButtonMode::pullup);

void setup(){
    boton1.setActiveLow(true);
    boton1.setDebounceTime(20);
    boton1.setLongPressTime(1000);
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
