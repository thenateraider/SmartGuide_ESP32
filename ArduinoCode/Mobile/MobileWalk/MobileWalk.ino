#define LV_CONF_INCLUDE_SIMPLE

#include "AudioQueue.h"
#include "Audio_PCM5101.h"
#include "BAT_Driver.h"
#include "DriverManager.h"
#include "FlowController.h"
#include "LVGL_Driver.h"
#include "MobileConfig.h"
#include "NavigationScan.h"
#include "PWR_Key.h"
#include "SD_Card.h"
#include "StationClient.h"
#include "lv_conf.h"
#include "lcd_component.h"
#include <BLEDevice.h>
#include <lvgl.h>

void setup() {
  Serial.begin(115200);
  connectToStationWiFi();
  pinMode(MOBILE_BUTTON_PIN, INPUT_PULLUP);
  PWR_Init();
  BAT_Init();
  BLEDevice::init("MobileWalk");
  SD_Init();
  Audio_Init();
  delay(100);
  Lvgl_Init();
  createPages();
  Driver_Loop();

  printf("[INFO] Resetting status to: unregistered\n");

  queue_mp3_file("/voice", "welcome.mp3", []() {
    readytostart = 1;
  });
  loadPage(pageWelcome);
}

void loop() {
  if (pendingPageToLoad != nullptr && lv_scr_act() != pendingPageToLoad) {
    // ลบ printf ที่ใช้ getPageName ออก
    loadPage(pendingPageToLoad);
    pendingPageToLoad = nullptr;
  }
  Lvgl_Loop();
  audioLoopCheck();
  if (readytostart == 1) {
    checkStatusAndUpdateScreen();
    updateBLEScanForCurrentStep();

    static unsigned long buttonPressStart = 0;
    static bool buttonHandled = false;

    if (digitalRead(MOBILE_BUTTON_PIN) == LOW) {
      if (buttonPressStart == 0) buttonPressStart = millis();

      if (!buttonHandled && millis() - buttonPressStart > 3000) {
        printf("[BUTTON] M1 Done by Button (3s hold)\n");
        handleM1DoneByButton();
        buttonHandled = true;
      }
    } else {
      buttonPressStart = 0;
      buttonHandled = false;
    }
  }
}
