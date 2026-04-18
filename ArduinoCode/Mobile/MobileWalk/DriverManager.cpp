#include "DriverManager.h"

#include "BAT_Driver.h"
#include "PWR_Key.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static void DriverTask(void* parameter) {
  while (1) {
    PWR_Loop();
    BAT_Get_Volts();
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

void Driver_Loop() {
  xTaskCreatePinnedToCore(
    DriverTask,
    "DriverTask",
    8192,
    NULL,
    3,
    NULL,
    0);
}

