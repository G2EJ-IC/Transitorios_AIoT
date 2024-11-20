#include <Arduino.h>
//Funsión Similar a cout << de C++.
//Debe estar despues de #include <Arduino.h> para que funcione.
template<class T> inline Print &operator <<(Print &obj, T arg) { 
  obj.print(arg); return obj; 
}

#include <SoftwareSerial.h>
//#include <serialUART>
 // Raspberry Pi Pico Rx (pin 1) ---- ESP8266 Tx
 // Raspberry Pi Pico Tx (pin 0) ---- ESP8266 Rx
SoftwareSerial esp8266(1,0); // RX | TX

void setup() {
  Serial.begin(115200);  // monitor serial del arduino
  esp8266.begin(115200); // baud rate del ESP8266
}

void setup1() {
  Serial.begin(115200);  // monitor serial del arduino
}


void loop() {
  // Repetir lo recibido por el ESP8266 hacia el monitor serial
  if (esp8266.available()) { 
    char c = esp8266.read() ;
    Serial.print(c);
  }

  // Repetir lo recibido por el monitor serial hacia el ESP8266
  if (Serial.available()) {  
    char c = Serial.read();
    esp8266.print(c);
  }
}

void loop1() {
  // Repetir lo recibido por el ESP8266 hacia el monitor serial
}