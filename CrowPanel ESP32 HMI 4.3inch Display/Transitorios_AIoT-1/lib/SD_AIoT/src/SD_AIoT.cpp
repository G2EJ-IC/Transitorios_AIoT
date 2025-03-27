#include <Arduino.h>
#include "SD_AIoT.h"

SD_AIoT::SD_AIoT(uint8_t csPin, int sck, int miso, int mosi)
    : _csPin(csPin), _sck(sck), _miso(miso), _mosi(mosi) {}

bool SD_AIoT::begin()
{
    // Configura el bus SPI con los pines indicados:
    SPI.begin(_sck, _miso, _mosi, _csPin);
    // Inicia la SD usando el pin CS y la instancia SPI.
    if (!SD.begin(_csPin, SPI))
    {
        Serial.println("Fallo en la inicialización de la SD.");
        return false;
    }
    Serial.println("SD iniciada correctamente.");
    return true;
}

bool SD_AIoT::exists(const char *path)
{
    return SD.exists(path);
}

bool SD_AIoT::createFile(const char *path)
{
    // Abrimos el archivo en modo escritura; FILE_WRITE crea el archivo si no existe.
    File file = SD.open(path, FILE_WRITE);
    if (file)
    {
        file.close();
        return true;
    }
    return false;
}

bool SD_AIoT::removeFile(const char *path)
{
    return SD.remove(path);
}

String SD_AIoT::readFile(const char *path)
{
    String content = "";
    File file = SD.open(path, FILE_READ);
    if (file)
    {
        while (file.available())
        {
            content += (char)file.read();
        }
        file.close();
    }
    else
    {
        Serial.print("No se pudo abrir el archivo: ");
        Serial.println(path);
    }
    return content;
}

bool SD_AIoT::writeFile(const char *path, const String &data)
{
    File file = SD.open(path, FILE_WRITE);
    if (!file)
    {
        Serial.print("Error al abrir el archivo para escribir: ");
        Serial.println(path);
        return false;
    }
    file.print(data);
    file.close();
    return true;
}

bool SD_AIoT::appendFile(const char *path, const String &data)
{
    File file = SD.open(path, FILE_APPEND);
    if (!file)
    {
        Serial.print("Error al abrir el archivo para añadir: ");
        Serial.println(path);
        return false;
    }
    file.print(data);
    file.close();
    return true;
}

void SD_AIoT::listDir(const char *dirname, uint8_t levels)
{
    File root = SD.open(dirname);
    if (!root)
    {
        Serial.print("No se pudo abrir el directorio: ");
        Serial.println(dirname);
        return;
    }
    if (!root.isDirectory())
    {
        Serial.print("No es un directorio: ");
        Serial.println(dirname);
        return;
    }

    File file = root.openNextFile();
    while (file)
    {
        if (file.isDirectory())
        {
            Serial.print("DIR: ");
            Serial.println(file.name());
            if (levels > 0)
            {
                listDir(file.name(), levels - 1);
            }
        }
        else
        {
            Serial.print("FILE: ");
            Serial.print(file.name());
            Serial.print(" (");
            Serial.print(file.size());
            Serial.println(" bytes)");
        }
        file = root.openNextFile();
    }
    root.close();
}
