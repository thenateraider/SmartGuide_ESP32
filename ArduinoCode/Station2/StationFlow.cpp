#include "StationFlow.h"

#include "StationConfig.h"
#include "StationNetwork.h"

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

  if (step == STEP_TO_FILTER) {
    Serial.println("✅ ผู้ป่วยถึงจุดคัดกรองแล้ว (STEP_TO_FILTER -> STEP_FILTERING)");
    setStepOnStation1(STEP_FILTERING);
  } else if (step == STEP_FILTERING) {
    Serial.println("✅ คัดกรองเสร็จสิ้นแล้ว (STEP_FILTERING -> STEP_TO_DOCTOR)");
    setStepOnStation1(STEP_TO_DOCTOR);
  } else {
    Serial.println("⚠️ สถานะปัจจุบันไม่ตรงกับที่คาดหวังสำหรับการดำเนินการที่จุดคัดกรอง");
  }

  inCooldown = true;
  cooldownStart = millis();
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDG, HIGH);
}

void updateCooldown() {
  if (inCooldown && millis() - cooldownStart >= 5000) {
    inCooldown = false;
    Serial.println("⏳ Cooldown เสร็จสิ้น");
    digitalWrite(LEDY, HIGH);
    digitalWrite(LEDG, LOW);
  }
}

bool canReadNFC() {
  return !inCooldown;
}

