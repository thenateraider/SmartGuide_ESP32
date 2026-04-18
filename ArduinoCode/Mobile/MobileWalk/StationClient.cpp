#include "StationClient.h"

#include "MobileConfig.h"
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>

void connectToStationWiFi() {
  WiFi.begin(SMARTGUIDE_WIFI_SSID, SMARTGUIDE_WIFI_PASS);
  printf("Connecting to WiFi...");
  unsigned long wifiConnectStart = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - wifiConnectStart < 30000) {
    delay(500);
    printf(".");
  }
  if (WiFi.status() == WL_CONNECTED) {
    printf("✅ Connected to STATION_REGIS\n");
  } else {
    printf("\n❌ WiFi Connection Failed! Halting.\n");
    while (1) {
      delay(200);
    }
  }
}

bool fetchStepAndDept(int& step, String& dept) {
  HTTPClient http;
  http.begin(STATION1_STATUS_URL);
  int code = http.GET();
  if (code != 200) {
    printf("❌ HTTP GET /status failed, code: %d\n", code);
    http.end();
    return false;
  }

  String payload = http.getString();
  http.end();

  StaticJsonDocument<128> doc;
  DeserializationError err = deserializeJson(doc, payload);
  if (err) {
    printf("❌ deserializeJson failed: %s\n", err.c_str());
    return false;
  }

  step = doc["step"];
  dept = doc["dept"].as<String>();
  return true;
}

