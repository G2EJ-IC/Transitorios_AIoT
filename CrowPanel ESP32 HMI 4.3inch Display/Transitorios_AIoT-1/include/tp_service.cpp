#include <Arduino.h>
#include "display_service.h"
#include "config.h"

#include "tp_service.h"
#include "io_service.h"
#include "screens.h"

#include "actions.h"

#include "DateTime_AIoT.h"
#include <SPI.h>

dhms_AIoT DateTimeAhora;       // load DateTime
io_service io_tp;              // load IO control service

tp_service::tp_service() {}
tp_service::~tp_service() {}

/* =============================icache functions========================= */
void tp_service::setup()
{
    pinMode(PIN_BL, OUTPUT);
} // end tp setup

void tp_service::loop()
{
    // lv_no_sleep();
} // end tp loop



void tp_service::lv_no_sleep(uint32_t lv_sleep){
    if (lv_display_get_inactive_time(NULL) < (1000 * lv_sleep)){
        io_tp.setPinBL(HIGH);
        io_tp.setOpacity((int32_t)(255 * lv_slider_get_value(objects.slider_porcentaje) / 100));    // 8 bits
        // io_tp.setOpacity((int32_t)(4095 * lv_slider_get_value(objects.slider_porcentaje) / 100));   // 12 bits
        // io_tp.setOpacity((int32_t)(65535 * lv_slider_get_value(objects.slider_porcentaje) / 100));  // 16 bits


    }
    /*Sleep after 1 sec inactivity*/
    else {
        Serial.println();
        uint32_t Ahora = lv_display_get_inactive_time(NULL);
        String DHMS = DateTimeAhora.DHMS_AIoT_get((uint64_t)(Ahora));
        // Serial.printf("%u mSeg - %s",Ahora, DHMS);
        io_tp.setPinBL(LOW);
        // Serial.println();
    }
}

