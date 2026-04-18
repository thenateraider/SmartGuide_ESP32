#include "StationNetwork.h"

#include "StationConfig.h"
#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <HTTPClient.h>
#include <WiFi.h>

void connectToWiFiWithMDNS() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("🔌 กำลังเชื่อมต่อ WiFi");
  unsigned long wifiConnectStart = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - wifiConnectStart < 30000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ เชื่อมต่อ WiFi แล้ว. IP: " + WiFi.localIP().toString());
    if (!MDNS.begin(STATION_MDNS_NAME)) {
      Serial.println("❌ ข้อผิดพลาดในการเริ่ม MDNS สำหรับ Station2");
    } else {
      Serial.println("🌐 MDNS responder เริ่มทำงานแล้วสำหรับ station2.local");
    }
  } else {
    Serial.println("\n❌ การเชื่อมต่อ WiFi ล้มเหลว! หยุดการทำงาน.");
    while (1) {
      digitalWrite(LEDY, !digitalRead(LEDY));
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

void setStepOnStation1(int stepValue) {
  HTTPClient http;
  String url = String("http://") + STATION1_HOST + "/setstep?value=" + String(stepValue);
  http.begin(url);
  int code = http.GET();
  Serial.println("📤 setstep HTTP code: " + String(code));
  http.end();
}

