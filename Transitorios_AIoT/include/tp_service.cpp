#include <Arduino.h>
#include "display_service.h"
#include "config.h"
#include "tp_service.h"
#include "DateTime_AIoT.h"
#include "io_service.h"
// #include "ui.h"

dhms_AIoT DateTimeAhora;       // load DateTime
// io_service ioAhora;            // load IO control service

tp_service::tp_service() {}
tp_service::~tp_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR tp_service::setup()
{
    pinMode(PIN_BL, OUTPUT);
} // end tp setup

void ICACHE_FLASH_ATTR tp_service::loop()
{
    lv_no_sleep(20);
} // end tp loop

void tp_service::setPin32(bool estado) {
  // Configurar el PIN 32 como salida (si es necesario)
  pinMode(PIN_BL, OUTPUT);

  // Escribir el estado en el PIN 32
  digitalWrite(PIN_BL, estado ? HIGH : LOW);
}

void ICACHE_FLASH_ATTR tp_service::lv_no_sleep(uint32_t lv_sleep)
{
    /*Normal operation (no sleep) in < 1 sec inactivity*/
    if (lv_display_get_inactive_time(NULL) < (1000 * lv_sleep))
    {
        setPin32(HIGH);
    }
    /*Sleep after 1 sec inactivity*/
    else
    {
        Serial.println();
        uint32_t Ahora = lv_display_get_inactive_time(NULL);
        String DHMS = DateTimeAhora.DHMS_AIoT_get((uint64_t)(Ahora));
        Serial.printf("%u mSeg - %s",Ahora, DHMS);
        setPin32(LOW);
        Serial.println();
    }
}

