#include "StationFlow.h"

#include "StationConfig.h"
#include "StationNetwork.h"

static bool handledOnce = false;
static bool inCooldown = false;
static unsigned long cooldownStart = 0;

void startStationPins() {
  pinMode(LEDY, OUTPUT);
  pinMode(LEDG, OUTPUT);
  digitalWrite(LEDY, HIGH);
  digitalWrite(LEDG, LOW);
}

void handleUID(String uid) {
  Serial.println("🪪 UID = " + uid);

  int step;
  String dept;
  if (!getStepAndDept(step, dept)) {
    Serial.println("⚠️ ไม่สามารถดึง step/dept จาก Station1 ได้");
    return;
  }

  Serial.printf("📦 สถานะปัจจุบันจาก Station1: step = %d | dept = %s\n", step, dept.c_str());

  if (!handledOnce && step == STEP_TO_DOCTOR) {
    Serial.println("✅ ตรวจพบผู้ป่วยถึงห้องตรวจแล้ว (STEP_TO_DOCTOR -> STEP_WITH_DOCTOR)");
    setStepOnStation1(STEP_WITH_DOCTOR);
    handledOnce = true;
  } else if (handledOnce && step == STEP_WITH_DOCTOR) {
    Serial.println("✅ ตรวจพบผู้ป่วยพบแพทย์เสร็จแล้ว (STEP_WITH_DOCTOR -> STEP_TO_PAYMENT)");
    setStepOnStation1(STEP_TO_PAYMENT);
    handledOnce = false;
  } else {
    Serial.println("⚠️ เงื่อนไขไม่ตรงกับ step ที่ควรดำเนินการ หรือผู้ป่วยยังอยู่ใน Cooldown");
  }

  inCooldown = true;
  cooldownStart = millis();
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDG, HIGH);
}

void updateCooldown() {
  if (inCooldown && millis() - cooldownStart >= 5000) {
    inCooldown = false;
    Serial.println("⏳ Cooldown complete");
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDG, LOW);
  }
}

bool canReadNFC() {
  return !inCooldown;
}

