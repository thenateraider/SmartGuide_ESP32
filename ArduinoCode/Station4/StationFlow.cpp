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

      if (step == STEP_TO_PAYMENT) {
        if (dept == "m1") {
          sendToMobile("paysuccessm1");
          setStep(STEP_TO_PHARMACY);
          Serial.println("✅ ชำระเงินสำหรับคลินิกหู คอ จมูก เสร็จสิ้น -> ไปรับยา");
        } else if (dept == "m2") {
          sendToMobile("paysuccessm2");
          setStep(STEP_DONE_PHY);
          Serial.println("✅ ชำระเงินสำหรับคลินิกกายภาพบำบัด เสร็จสิ้น -> คืนอุปกรณ์แล้ว");
        } else {
          sendToMobile("errorstep");
          Serial.println("⚠️ แผนกไม่รู้จัก");
        }
      } else {
        sendToMobile("errorstep");
        Serial.println("⚠️ สถานะปัจจุบันไม่เป็น STEP_TO_PAYMENT");
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

