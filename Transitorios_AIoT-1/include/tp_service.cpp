#include <Arduino.h>
#include "display_service.h"
#include "config.h"
#include "tp_service.h"
#include "DateTime_AIoT.h"
#include "io_service.h"
#include "screens.h"
// #include "ui.h"

dhms_AIoT DateTimeAhora;       // load DateTime
io_service io_tp;              // load IO control service

tp_service::tp_service() {}
tp_service::~tp_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR tp_service::setup()
{
    pinMode(PIN_BL, OUTPUT);
} // end tp setup

void ICACHE_FLASH_ATTR tp_service::loop()
{
    // lv_no_sleep();
} // end tp loop



void ICACHE_FLASH_ATTR tp_service::lv_no_sleep(uint32_t lv_sleep)
{
    /*Normal operation (no sleep) in < 1 sec inactivity*/
    // uint32_t lv_N_sleep = lv_dropdown_get_selected(objects.drop_down_suspender);
    // uint32_t lv_sleep = 20;

    if (lv_display_get_inactive_time(NULL) < (1000 * lv_sleep))
    {
        io_tp.setPin32(HIGH);
    }
    /*Sleep after 1 sec inactivity*/
    else
    {
        Serial.println();
        uint32_t Ahora = lv_display_get_inactive_time(NULL);
        String DHMS = DateTimeAhora.DHMS_AIoT_get((uint64_t)(Ahora));
        Serial.printf("%u mSeg - %s",Ahora, DHMS);
        io_tp.setPin32(LOW);
        Serial.println();
    }
}

