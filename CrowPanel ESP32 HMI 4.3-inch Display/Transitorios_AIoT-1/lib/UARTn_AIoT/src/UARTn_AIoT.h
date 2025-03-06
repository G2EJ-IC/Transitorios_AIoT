#ifndef __UART1_AIOT_H__
#define __UART1_AIOT_H__

#include <Arduino.h>

class UARTn_AIoT {
    private:
    uint8_t _rxPin;
    uint8_t _txPin;
    unsigned long _baudRate;
    HardwareSerial* _serial; // Instancia del UART (en este caso, UART1)

public:
    UARTn_AIoT(HardwareSerial* , uint8_t , uint8_t , unsigned long );
    ~UARTn_AIoT();
    void begin();
    bool available();
    String readStringUntil(char);
    void write(const String &);
};

// UARTn_AIoT myUART(&Serial1, 16, 17, 115200);  // Usa Serial1, pines 16 (RX) y 17 (TX)

#endif // __UART1_AIOT_H__