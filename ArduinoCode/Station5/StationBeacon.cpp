#include "StationBeacon.h"

#include "StationConfig.h"
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>

void startBLEBeacon() {
  BLEDevice::init(STATION_BLE_NAME);
  BLEServer* pServer = BLEDevice::createServer();
  BLEAdvertising* pAdvertising = pServer->getAdvertising();
  pAdvertising->start();
  Serial.println("📡 Station5 BLE Advertising Started");
}

