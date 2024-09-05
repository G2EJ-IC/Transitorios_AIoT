#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <task.h>

TaskHandle_t Task1 = NULL;
TaskHandle_t Task2 = NULL;
SemaphoreHandle_t cuentaMutex;

// #include <semphr.h>  // add the FreeRTOS functions for Semaphores (or Flags).

int cuenta = 0;

// define two tasks for Blink & AnalogRead
void TaskLoop2(void *);
void TaskLoop3(void *);

void TestHwm(const char *);

// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);

  BaseType_t taskCreationResult;

  // taskCreationResult = xTaskCreatePinnedToCore(
  taskCreationResult = xTaskCreate(
                        TaskLoop2, 
                        "Look_2", 
                        10000, 
                        NULL, 
                        1,
                        nullptr);
                        // &Task2);
  if (taskCreationResult != pdPASS) {
    Serial.println("Error al crear Task2");
    while (true);
  }
  // taskCreationResult = xTaskCreatePinnedToCore(
  taskCreationResult = xTaskCreate(
                        TaskLoop3, 
                        "Look_3", 
                        10000, 
                        NULL, 
                        1, 
                        nullptr);
                        // &Task3);
  if (taskCreationResult != pdPASS) {
    Serial.println("Error al crear Task3");
    while (true);
  }
}

void loop() {
  // Empty. Things are done in Tasks. 
}

void TaskLoop2(void *pvParameters){
  (void) pvParameters;
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(2222));
    Serial.println("\t\t\t Loop dos (2) - 🤯🤯🤯");
    cuenta++;
    Serial.println("================================================================================");
    Serial.println("desde loop 2 -> " + String(cuenta));
    TestHwm("loop2");
  }
}

void TaskLoop3(void *pvParameters){
  (void) pvParameters;
  for(;;){
    vTaskDelay(pdMS_TO_TICKS(3333));
    Serial.println("\t\t\t Loop tres (3) - 🤯🤯🤯");    
    cuenta++;
    Serial.println("================================================================================");
    Serial.println("desde loop 3 -> " + String(cuenta));
    TestHwm("loop3");
  }
}

void TestHwm(const char *taskName) {
  int stack_hwm_temp = uxTaskGetStackHighWaterMark(nullptr);
  Serial.println("\n================================================================================\n");
  Serial.printf("%s Tiene un máximo en la Pila (High Water Mark) de.: %u\n", taskName, stack_hwm_temp);
  Serial.println("\n================================================================================\n");
}