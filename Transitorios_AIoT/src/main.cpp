#include "Arduino.h"
//#include <lvgl.h>
//#include "LovyanGFX_Class_ILI9488.h"
// #include <ui.h>
#include "display_service.h"
#include "io_service.h"
#include "tp_service.h"
#include "config.h"
#include "screens.h"

#include "flow_def.h"
#include "vars.h"

TaskHandle_t Task1 = NULL;
TaskHandle_t Task2 = NULL;
TaskHandle_t Task3 = NULL;
TaskHandle_t Task4 = NULL;
SemaphoreHandle_t cuentaMutex;

io_service io;            // load IO control service
display_service display;  // load display service
tp_service tp;            // load touchpad

uint32_t lv_N_sleep;

//************************************************************************************************
inline void loop_Task1(void);
inline void loop_Task2(void);
inline void loop_Task3(void);
inline void loop_Task4(void);
//************************************************************************************************
void loop1(void *);
void loop2(void *);
void loop3(void *);
void loop4(void *);
//************************************************************************************************setPin32;
#define ICACHE_FLASH_ATTR

unsigned long asyncDelay0 = 0;
int delayLength0 = 3000;

// static uint32_t lvgl_refresh_timestamp = 5u;

void ICACHE_FLASH_ATTR setup()
{
  io.memoria_ESP();
  // pinMode(PinLED, OUTPUT);
  // pinMode(PIN_BL, OUTPUT);
  // Segundo Siclo en el Núcleo Secundario.
  // Núcleo Principal  -> 1. APP
  // Núcleo Secundario -> 0. PRO
  /************************************Begin FreeRTOS*******************************************/
  
  BaseType_t taskCreationResult;

  taskCreationResult = xTaskCreatePinnedToCore(
      loop1,
      "Task_1",
      11264,
      NULL,
      3,
      &Task1,
      0);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task1");
    while (true)
      ;
  }

  taskCreationResult = xTaskCreatePinnedToCore(
      loop2,
      "Task_2",
      31744,
      NULL,
      2,
      &Task2,
      1);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task2");
    while (true)
      ;
  }

  taskCreationResult = xTaskCreatePinnedToCore(
      loop3,
      "Task_3",
      25600, //25600
      NULL,
      1,
      &Task3,
      0);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task3");
    while (true)
      ;
  }

  taskCreationResult = xTaskCreatePinnedToCore(
      loop4,
      "Task_4",
      1600, //25600
      NULL,
      1,
      &Task4,
      0);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task3");
    while (true)
      ;
  }

  cuentaMutex = xSemaphoreCreateMutex();
  if (cuentaMutex == NULL)
  {
    Serial.println("Error al crear semáforo");
    while (true)
      ;
  }

  /******************************************End FreeRTOS***************************************/
  delay(1000);
  // lv_task_handler();
}

void ICACHE_FLASH_ATTR loop()
{
  io.feedTheDog();
  // analogWrite(PIN_BL, 1);
  // tp.lv_no_sleep(60);
  if (millis() > asyncDelay0)
  {
    asyncDelay0 += delayLength0;
    io.TestHWM("loop", asyncDelay0); 
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************************************************************

inline void loop_Task1(void)
{
  io.loop();
}

inline void loop_Task2(void)
{
  display.loop();
  lv_N_sleep = io.suspender();
}

inline void loop_Task3(void)
{
  tp.loop();
}

inline void loop_Task4(void)
{
  tp.lv_no_sleep(lv_N_sleep);
}

void ICACHE_FLASH_ATTR loop1(void *parameter)
{
  int delayLength1 = 5333;
  unsigned long asyncDelay1 = 0;

  io.setup();
  for (;;) //while(1);
  {
    io.feedTheDog();
    loop_Task1();
    if (millis() > asyncDelay1)
    {
      asyncDelay1 += delayLength1;
      io.ParpadeoLED();
      io.TestHWM("loop1", asyncDelay1);          
    }
  }
}

void ICACHE_FLASH_ATTR loop2(void *parameter)
{
  int delayLength2 = 5222;
  unsigned long asyncDelay2 = 0;

  display.setup();
  for (;;)
  {
    io.feedTheDog();
    loop_Task2();
    tp.lv_no_sleep(lv_N_sleep);
    if (millis() >= asyncDelay2)
    {
      io.cronometro(asyncDelay2);
      asyncDelay2 += delayLength2;
      io.TestHWM("loop2", asyncDelay2);      
    }
  }
}

void ICACHE_FLASH_ATTR loop3(void *parameter)
{
  int delayLength3 = 5111;
  unsigned long asyncDelay3 = 0;

  tp.setup();
  for (;;)
  {
    io.feedTheDog();
    loop_Task3();
    if (millis() > asyncDelay3)
    {
      asyncDelay3 += delayLength3;
      io.TestHWM("loop3", asyncDelay3);      
    }
  }
}

void ICACHE_FLASH_ATTR loop4(void *parameter)
{
  unsigned long asyncDelay4 = 0;
  tp.setup();
  for (;;)
  {
    io.feedTheDog();
    loop_Task4();
    asyncDelay4 = millis();
    io.cronometro(asyncDelay4);
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
    // get_var_slider_porcentaje();
    // set_var_slider_porcentaje(15);

  }
}
