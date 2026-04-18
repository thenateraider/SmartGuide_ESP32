#include "StationNetwork.h"

#include "StationConfig.h"
#include <Arduino.h>
#include <ESPmDNS.h>
#include <WiFi.h>

void connectToWiFiWithMDNS() {
  WiFi.mode(WIFI_STA);

  Serial.print("🔌 Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  unsigned long wifiConnectStart = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - wifiConnectStart < 30000) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi connected!");
    Serial.println("IP Address: " + WiFi.localIP().toString());

    if (MDNS.begin(MDNS_NAME)) {
      Serial.println("🌐 mDNS started: http://" + String(MDNS_NAME) + ".local");
    } else {
      Serial.println("❌ mDNS start failed");
    }
  } else {
    Serial.println("\n❌ WiFi Connection Failed! Halting.");
    while (1) {
      digitalWrite(LED1_PIN, !digitalRead(LED1_PIN));
      delay(200);
    }
  }
}

