#include "UARTn_AIoT.h"

// Constructor: recibe los pines de RX, TX y la velocidad en baudios.
UARTn_AIoT::UARTn_AIoT(HardwareSerial* serial, uint8_t rxPin, uint8_t txPin, unsigned long baudRate)
    : _rxPin(rxPin), _txPin(txPin), _baudRate(baudRate), _serial(serial) { }

// Destructor
UARTn_AIoT::~UARTn_AIoT(){ };

// Inicializa el UART con los parámetros definidos.
void UARTn_AIoT::begin() {
    _serial->begin(_baudRate, SERIAL_8N1, _rxPin, _txPin);
}

// Devuelve true si hay datos disponibles en el buffer.
bool UARTn_AIoT::available() {
    return _serial->available();
}

// Lee la cadena recibida hasta el carácter terminador especificado.
String UARTn_AIoT::readStringUntil(char terminator) {
    return _serial->readStringUntil(terminator);
}

// Envía una cadena a través del UART.
void UARTn_AIoT::write(const String &msg) {
    _serial->write(msg.c_str());
}
