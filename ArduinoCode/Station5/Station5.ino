#include "StationBeacon.h"
#include "StationFlow.h"
#include "StationNetwork.h"

void setup() {
  Serial.begin(115200);
  startStationPins();
  connectToWiFiWithMDNS();
  startBLEBeacon();
}

void loop() {
  handleButtonLoop();
}

