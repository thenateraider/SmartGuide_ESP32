#include "StationBeacon.h"
#include "StationFlow.h"
#include "StationNetwork.h"
#include "StationNfc.h"

void setup() {
  Serial.begin(115200);
  delay(500);
  startStationPins();
  connectToWiFiWithMDNS();
  startBLEBeacon();
  initNFC();
}

void loop() {
  updateCooldown();

  if (canReadNFC()) {
    String uid = readUID();
    if (uid.length() > 0) {
      handleUID(uid);
    }
  }

  delay(200);
}

