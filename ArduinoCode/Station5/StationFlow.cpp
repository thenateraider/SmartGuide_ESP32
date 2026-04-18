#include "StationFlow.h"

#include "StationConfig.h"
#include "StationNetwork.h"
#include <Arduino.h>

static bool inCooldown = false;
static unsigned long cooldownStart = 0;
static bool lastButtonState = HIGH;

void startStationPins() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void handleButtonLoop() {
  if (inCooldown && millis() - cooldownStart >= 5000) {
    inCooldown = false;
    Serial.println("⏳ Cooldown complete");
  }

  bool buttonState = digitalRead(BUTTON_PIN);
  if (!inCooldown && lastButtonState == HIGH && buttonState == LOW) {
    Serial.println("🔘 Button pressed");

    int step;
    String dept;
    if (getStepAndDept(step, dept)) {
      Serial.printf("📦 สถานะปัจจุบันจาก Station1: step = %d | dept = %s\n", step, dept.c_str());

      if (step == STEP_TO_PHARMACY && dept == "m1") {
        sendToMobile("finishgetpillm1");
        setStep(STEP_FINISH_GET_PILL);
        Serial.println("✅ รับยาสำหรับคลินิกหู คอ จมูก เสร็จสิ้น");
      } else {
        sendToMobile("errorstep");
        Serial.println("⚠️ ไม่อยู่ในสถานะ STEP_TO_PHARMACY หรือเป็นแผนกอื่นที่ไม่ใช่ m1");
      }
    } else {
      sendToMobile("errorstep");
      Serial.println("❌ ไม่สามารถดึงสถานะจาก Station1 ได้");
    }

    inCooldown = true;
    cooldownStart = millis();
  }

  lastButtonState = buttonState;
  delay(10);
}

