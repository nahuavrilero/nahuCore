/*Este es el ejemplo basico. Usa el constructor simple. 
La creación del objeto NahuButton solo requiere el pin como int o uint8_t pero se puede configurar mediante las funciones setters.
Los valores por defecto para la configuracion son:
debounceTime = 20 (ms)
activeLow = true
longPressTime = 1000 (ms)
mode = ButtonMode::pullup
Tambien se puede crear un objeto NahuButtonConfig que guarda la configuracion. Ver ejemplo advanced.cpp
*/

//#include <Arduino.h> //Comentar si usas Arduino IDE, descomentar si usas Platform.IO.
#include <nahuButton.h>

NahuButton boton1(4);

void setup(){

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
        Serial.println("Presionando."); //Cuidado, se cumple siempre mientras el botón está presionado. 
    }
    if (boton1.wasLongPressed()){
        Serial.println("Pulsación larga.");
    }
}
