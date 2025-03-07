#include "Arduino.h"

#include "display_service.h"
#include "io_service.h"
#include "tp_service.h"

#include "config.h"
#include "screens.h"

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
//************************************************************************************************

// static uint32_t lvgl_refresh_timestamp = 5u;

void setup()
{
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
      2,
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
      3,
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
      25600, // 3200, //25600
      NULL,
      1,
      &Task4,
      0);
  if (taskCreationResult != pdPASS)
  {
    Serial.println("Error al crear Task4");
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
  vTaskDelay(pdMS_TO_TICKS(1000)); // delay( 1000 );
  // lv_task_handler();
}

void loop()
{
  vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
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

//////////////////////////////////////////////////////////////////////////////////////////////////
//************************************************************************************************

void loop1(void *parameter)
{
  io.setup();
  for (;;)
  {
    loop_Task1();
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
    // taskYIELD();
  }
}

void loop2(void *parameter)
{
  int delayLength2 = 200;
  unsigned long asyncDelay2 = 0;

  display.setup();
  for (;;)
  {
    loop_Task2();
    tp.lv_no_sleep(lv_N_sleep);
    if (millis() >= asyncDelay2)
    {
      io.cronometro(asyncDelay2);
      asyncDelay2 += delayLength2;
    }
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
    // taskYIELD();
  }
}

void loop3(void *parameter)
{
  tp.setup();
  for (;;)
  {
    loop_Task3();
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
    // taskYIELD();
  }
}

void loop4(void *parameter)
{
  unsigned long asyncDelay4 = 0;
  tp.setup();
  for (;;)
  {
    loop_Task4();
    vTaskDelay(pdMS_TO_TICKS(5)); // delay( 5 );
    // taskYIELD();
  }
}
