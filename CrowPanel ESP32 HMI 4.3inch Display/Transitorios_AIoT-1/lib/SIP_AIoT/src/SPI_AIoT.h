#ifndef __SPI_AIOT_H__
#define __SPI_AIOT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <SPI.h>

class SPI_AIoT
{
private:
    SPIClass *_spi;
    uint8_t _csPin;
    uint32_t _clock;
    uint8_t _dataOrder;
    uint8_t _mode;

public:
    // Constructor: recibe la instancia SPI, el pin CS, la velocidad del reloj,
    // el orden de los bits (MSBFIRST o LSBFIRST) y el modo (SPI_MODE0, etc.)
    SPI_AIoT(SPIClass *spi, uint8_t csPin, uint32_t clock, uint8_t dataOrder = MSBFIRST, uint8_t mode = SPI_MODE0);

    // Inicializa la comunicación SPI
    void begin();

    // Transfiere un byte y retorna el byte recibido
    uint8_t transfer(uint8_t data);

    // Transfiere un buffer de datos (en modo full-duplex)
    void transfer(uint8_t *buf, size_t count);

    // Envía un byte (sin leer)
    void write(uint8_t data);

    // Envía un buffer de datos
    void write(const uint8_t *buf, size_t count);
};

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif // __SPI_AIOT_H__