#include "StationNfc.h"

#include "StationConfig.h"
#include <Adafruit_PN532.h>
#include <Wire.h>

static Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

void initNFC() {
  Wire.begin(SDA_PIN, SCL_PIN, 400000);
  nfc.begin();
  if (!nfc.getFirmwareVersion()) {
    Serial.println("❌ ไม่พบ PN532");
    while (1);
  }
  nfc.SAMConfig();
  Serial.println("✅ NFC พร้อมใช้งาน");
}

String readUID() {
  uint8_t uid[7];
  uint8_t uidLength;
  if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 100)) {
    String uidStr = "";
    for (int i = 0; i < uidLength; i++) {
      if (uid[i] < 0x10) uidStr += "0";
      uidStr += String(uid[i], HEX);
      if (i < uidLength - 1) uidStr += ":";
    }
    uidStr.toUpperCase();
    return uidStr;
  }
  return "";
}

