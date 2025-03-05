#include <Arduino.h>

#include "soc/timer_group_struct.h"  //for wdt
#include "soc/timer_group_reg.h"     //for wdt

#include "config.h"

#include "io_service.h"

#include "screens.h"
#include "DateTime_AIoT.h"

dhms_AIoT DateTime;       // load DateTime

io_service::io_service() {}
io_service::~io_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR io_service::setup()
{
  Serial.begin(115200);
  // ParpadeoLED();
} // end io setup

void ICACHE_FLASH_ATTR io_service::loop()
{

} // end io loop

/**
 * @brief Breve descripción.
 * @param Parámetros.
 * @return Salida. 
 */
void io_service::setPinBL(bool estado) {
  pinMode(PIN_BL, OUTPUT);
  digitalWrite(PIN_BL, estado ? HIGH : LOW);
}

/**
 * @brief Breve descripción.
 * @param Parámetros.
 * @return Salida. 
 */
void io_service::setOpacity(uint32_t opaContainer) {
  // int32_t opaContainer = (int32_t)(255 * lv_slider_get_value(objects.slider_porcentaje) / 100);
  // Serial.println(opaContainer);
  const int pwmChannel  = 0; // 0-15
  const int frecuencia = 10000; // en Hz
  const int resolucion = 8; // 8-16 bits de resolución.

  pinMode(PIN_BL, OUTPUT);
  ledcSetup(pwmChannel , frecuencia, resolucion);
  ledcAttachPin(PIN_BL, pwmChannel);
  ledcWrite(pwmChannel , opaContainer);
}

///////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Breve descripción.
 * @param Parámetros.
 * @return Salida. 
 */
void ICACHE_FLASH_ATTR io_service::TestHWM(const char *taskName, uint32_t Ahora)
{
  UBaseType_t stack_HWM = uxTaskGetStackHighWaterMark(nullptr);
  BaseType_t portGCID = xPortGetCoreID();
  uint32_t dispGIT = lv_disp_get_inactive_time(NULL);
  float temperature = temperatureRead();
  // int HallEffectSensor = hallRead();
  // String DHMS = DateTime.DHMS_AIoT((uint64_t)Ahora);

  Serial.println("\n================================================================================");
  Serial.printf("(%s).: \n"
              "Tiene un máximo en la Pila (High Water Mark) de.: %u \n"
              "En el núcleo (%u) \n"
              "Timer(%u) \n"
              "Temperatura (%.2f°C) \n"
              "Ahora (%u mSeg) \n"
              /* "Hall Effect Sensor (%i)" */,
              taskName, stack_HWM, portGCID, dispGIT, temperature, Ahora);
  Serial.println("\n================================================================================");
}

void ICACHE_FLASH_ATTR io_service::cronometro(uint32_t Ahora)
{
  String DHMS = DateTime.DHMS_AIoT_get((uint64_t)(Ahora));
  // lv_label_set_text(objects.label_dhms_1, "xx.xx.xx.xx");
  // lv_label_set_text(objects.label_dhms_2, "xx.xx.xx.xx");
  lv_label_set_text(objects.label_dhms_1, String(DHMS).c_str());
  lv_label_set_text(objects.label_dhms_2, String(DHMS).c_str());
  // lv_label_set_text(objects.label_dhms_3, String(DHMS).c_str());
}

uint32_t ICACHE_FLASH_ATTR io_service::suspender(void)
{
  int N = 0;
  uint32_t N_sleep;

  N = lv_dropdown_get_selected(objects.drop_down_suspender);
  if (N==0) N_sleep = 15;
  if (N==1) N_sleep = 30;
  if (N==2) N_sleep = 1 * 60;
  if (N==3) N_sleep = 2 * 60;
  if (N==4) N_sleep = 5 * 60;
  if (N==5) N_sleep = 10 * 60;

  return N_sleep;
}