#include "StationBeacon.h"

#include "StationConfig.h"
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>

void startBLEBeacon() {
  BLEDevice::init(STATION_BLE_NAME);
  BLEServer* pServer = BLEDevice::createServer();
  BLEAdvertising* adv = pServer->getAdvertising();
  adv->start();
  Serial.println("📡 BLE Beacon Started");
}

