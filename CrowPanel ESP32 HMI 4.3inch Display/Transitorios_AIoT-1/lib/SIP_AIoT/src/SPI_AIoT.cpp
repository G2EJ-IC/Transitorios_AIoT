#include <Arduino.h>
#include "SPI_AIoT.h"

SPI_AIoT::SPI_AIoT(SPIClass *spi, uint8_t csPin, uint32_t clock, uint8_t dataOrder, uint8_t mode)
    : _spi(spi), _csPin(csPin), _clock(clock), _dataOrder(dataOrder), _mode(mode) {}

void SPI_AIoT::begin()
{
    // Inicia la interfaz SPI
    _spi->begin();
    // Configura el pin de Chip Select como salida y lo pone en estado HIGH (inactivo)
    pinMode(_csPin, OUTPUT);
    digitalWrite(_csPin, HIGH);
}

uint8_t SPI_AIoT::transfer(uint8_t data)
{
    digitalWrite(_csPin, LOW);               // Activa el CS
    uint8_t received = _spi->transfer(data); // Transfiere el byte
    digitalWrite(_csPin, HIGH);              // Desactiva el CS
    return received;
}

void SPI_AIoT::transfer(uint8_t *buf, size_t count)
{
    digitalWrite(_csPin, LOW);
    _spi->transfer(buf, count);
    digitalWrite(_csPin, HIGH);
}

void SPI_AIoT::write(uint8_t data)
{
    digitalWrite(_csPin, LOW);
    _spi->transfer(data);
    digitalWrite(_csPin, HIGH);
}

void SPI_AIoT::write(const uint8_t *buf, size_t count)
{
    digitalWrite(_csPin, LOW);
    for (size_t i = 0; i < count; i++)
    {
        _spi->transfer(buf[i]);
    }
    digitalWrite(_csPin, HIGH);
}
