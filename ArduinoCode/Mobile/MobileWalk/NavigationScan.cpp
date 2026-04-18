#include "NavigationScan.h"

#include "AudioQueue.h"
#include "FlowController.h"
#include "lcd_component.h"
#include <BLEDevice.h>
#include <math.h>
#include <map>

float estimateDistance(int rssi, int txPower) {
  if (rssi == 0) return -1.0;
  float ratio = rssi * 1.0 / txPower;
  if (ratio < 1.0) return pow(ratio, 10);
  else return 0.89976 * pow(ratio, 7.7095) + 0.111;
}

std::map<String, bool> playedOnceMap;

void updateBLEScanForCurrentStep() {
  static unsigned long lastScanTime = 0;
  if (millis() - lastScanTime > 2000) {
    lastScanTime = millis();
    lv_obj_t* currentScreen = lv_scr_act();

    if (currentScreen == pageToFilter && enableScanFilter) {
      updateProximityScan("Station2_Filter", "m1", label_distance_filter, "3.mp3");
    } else if (currentScreen == pageToDoctorm1 && enableScanDoctor) {
      updateProximityScan("Station3_Doctor", "m1", label_distance_doctor_m1, "6.mp3");
    } else if (currentScreen == pageToDoctorm2 && enableScanDoctor) {
      updateProximityScan("Station3_Doctor", "m2", label_distance_doctor_m2, "6.mp3");
    } else if (currentScreen == pageToPaymentm1 && enableScanPayment) {
      updateProximityScan("Station4_Payment", "m1", label_distance_payment_m1, "11.mp3");
    } else if (currentScreen == pageToPaymentm2 && enableScanPayment) {
      updateProximityScan("Station4_Payment", "m2", label_distance_payment_m2, "11.mp3");
    } else if (currentScreen == pageToPharmacy && enableScanPharmacy) {
      updateProximityScan("Station5_Pharmacy", "m1", label_distance_pharmacy, "16.mp3");
    }
  }
}

void updateProximityScan(const String& targetName, const String& dept, lv_obj_t* labelDistance, const char* voiceFile) {
  String deptPrefix = dept;

  if (dept == "m1") deptPrefix = "/ear";
  else if (dept == "m2") deptPrefix = "/phy";

  BLEScan* scanner = BLEDevice::getScan();
  scanner->setActiveScan(true);
  BLEScanResults* results = scanner->start(3);

  for (int i = 0; i < results->getCount(); i++) {
    BLEAdvertisedDevice d = results->getDevice(i);
    if (d.getName() == targetName) {
      int rssi = d.getRSSI();
      float distance = estimateDistance(rssi);
      printf("📡 พบ %s | RSSI = %d | ระยะ ~ %.1f ม\n", targetName.c_str(), rssi, distance);

      char distStr[32];
      snprintf(distStr, sizeof(distStr), "ระยะทาง\n%.1f ม", distance);
      updateNavigationInfo(distStr, labelDistance);

      if (distance < 4.0 && !playedOnceMap[targetName]) {
        queue_mp3_file(deptPrefix.c_str(), voiceFile);
        playedOnceMap[targetName] = true;
        printf("✅ เล่น mp3 เพราะอยู่ใกล้พอ\n");
      }
    }
  }
}
