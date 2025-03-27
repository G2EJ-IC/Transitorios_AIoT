#ifndef __SD_AIOT_H__
#define __SD_AIOT_H__

#include <SPI.h>
#include <SD.h>

class SD_AIoT
{
private:
    uint8_t _csPin;
    int _sck;
    int _miso;
    int _mosi;

public:
    // Constructor: recibe el pin CS, y los pines para SCK, MISO y MOSI.
    SD_AIoT(uint8_t csPin, int sck, int miso, int mosi);

    // Inicializa la SD (configura el bus SPI y la tarjeta SD).
    bool begin();

    // Comprueba si existe un archivo o directorio.
    bool exists(const char *path);

    // Crea (o abre en modo escritura) un archivo.
    bool createFile(const char *path);

    // Elimina un archivo.
    bool removeFile(const char *path);

    // Lee todo el contenido de un archivo y lo devuelve en un String.
    String readFile(const char *path);

    // Escribe (sobrescribe) un archivo con el String recibido.
    bool writeFile(const char *path, const String &data);

    // Añade datos al final de un archivo.
    bool appendFile(const char *path, const String &data);

    // Lista el contenido de un directorio (con niveles de recursividad).
    void listDir(const char *dirname, uint8_t levels);
};

#endif // __SD_AIOT_H__