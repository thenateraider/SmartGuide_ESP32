#include "StationNetwork.h"

#include "StationConfig.h"
#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <HTTPClient.h>
#include <WiFi.h>

void connectToWiFiWithMDNS() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WiFi");
  unsigned long wifiConnectStart = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - wifiConnectStart < 30000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(" ✅ Connected! IP: " + WiFi.localIP().toString());
    if (!MDNS.begin(STATION_MDNS_NAME)) {
      Serial.println("❌ Error starting MDNS for Station5");
    } else {
      Serial.println("🌐 MDNS responder started for station5.local");
    }
  } else {
    Serial.println("\n❌ WiFi Connection Failed! Halting.");
    while (1) {
      delay(200);
    }
  }
}

bool getStepAndDept(int& step, String& dept) {
  HTTPClient http;
  http.begin(String("http://") + STATION1_HOST + "/status");
  int code = http.GET();
  if (code != 200) {
    Serial.printf("❌ HTTP GET /status failed, code: %d\n", code);
    http.end();
    return false;
  }

  String payload = http.getString();
  http.end();
  StaticJsonDocument<128> doc;
  DeserializationError error = deserializeJson(doc, payload);
  if (error) {
    Serial.printf("❌ deserializeJson failed: %s\n", error.c_str());
    return false;
  }

  step = doc["step"];
  dept = doc["dept"].as<String>();
  return true;
}

void setStep(int stepValue) {
  HTTPClient http;
  http.begin(String("http://") + STATION1_HOST + "/setstep?value=" + String(stepValue));
  int code = http.GET();
  Serial.printf("📤 Set step = %d | Result = %d\n", stepValue, code);
  http.end();
}

void sendToMobile(const String& msg) {
  HTTPClient http;
  http.begin(String("http://") + STATION1_HOST + "/sendmobile?msg=" + msg);
  int code = http.GET();
  Serial.printf("📤 Mobile <- %s | Result = %d\n", msg.c_str(), code);
  http.end();
}

