#include <WiFi.h>
#include <WebServer.h>
#include <esp_bt.h>
#include <esp_bt_main.h>
#include <esp_bt_device.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLEClient.h>
#include <ArduinoJson.h>
#include <vector>
#include <esp_wifi.h>
#include <Wire.h>
#include <Adafruit_PN532.h>
#include <ESPmDNS.h>
#include "StationConfig.h"
#include "StationNetwork.h"

Adafruit_PN532 nfc(SDA_PIN, SCL_PIN);

WebServer server(80);

String registeredPatientID = ""; // PT0001, PT0002...
String registeredName = "";    // Patient's Name
String registeredDept = "";    // m1, m2 (department code)

bool waitingForNFC = false;

std::vector<String> registeredUIDs; // Stores UIDs to generate patient IDs

// Array of status texts (moved here for global access and consistent usage)
const char* registrationStatusText[] = {
  "ยังไม่มีผู้ป่วยลงทะเบียน", // STEP_INITIAL
  "✅ ลงทะเบียนแล้ว กำลังเดินทางไปจุดคัดกรอง", // STEP_TO_FILTER
  "🔄 กำลังคัดกรอง", // STEP_FILTERING
  "🚶 คัดกรองเสร็จแล้ว กำลังไปห้องตรวจ ", // STEP_TO_DOCTOR
  "👨‍⚕️ ถึงห้องตรวจแล้ว กำลังเข้าพบแพทย์", // STEP_WITH_DOCTOR
  "🏦 พบแพทย์เสร็จแล้ว กำลังไปห้องชำระเงิน", // STEP_TO_PAYMENT
  "🗾 ชำระเงินแล้ว กำลังไปรับยา", // STEP_TO_PHARMACY
  "💊 รับยาและคืนอุปกรณ์แล้ว", // STEP_DONE
  "⏳ กำลังรอแตะบัตร NFC...", // STEP_WAITNFC
  "✅ ชำระเงิน และคืนอุปกรณ์แล้ว", // STEP_DONE_PHY
  "📦 จ่ายเงินเรียบร้อย", // STEP_PAYFINISH
  "💊 รับยาแล้ว" // STEP_FINISHGETPILL
};


RegistrationStep currentStep = STEP_INITIAL;

unsigned long ledTimer = 0;
bool led21Active = false;

// Moved getDeptName here to be accessible globally for server-side HTML generation
String getDeptName(String code) {
  if (code == "m1") return "คลินิกหู คอ จมูก";
  if (code == "m2") return "คลินิกกายภาพบำบัด";
  return code;
}

void handleRoot() {
  String html = R"rawliteral(
  <!DOCTYPE html>
  <html><head>
    <meta charset='UTF-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1.0'>
    <style>
      body {
        background: #20A7DB; font-family: sans-serif; font-size: 20px; padding: 20px; color: black;
      }
      .title {
        text-align: center; color: white; font-size: 36px; font-weight: bold;
        text-shadow: 2px 2px 4px rgba(0,0,0,0.5);
      }
      input, select { font-size: 20px; padding: 5px; margin: 5px 0; }
      input[type='submit'] {
        background: #4CAF50; color: white; padding: 10px 20px; border: none; cursor: pointer;
      }
      input[type='submit']:hover { background: #45a049; }
      .status-box {
        background: white; padding: 20px; border-radius: 12px;
        box-shadow: 0 2px 10px rgba(0,0,0,0.2);
      }
      .danger-button {
        background: #e53935; /* สีแดง */
        color: white;
        padding: 10px 20px;
        border: none;
        cursor: pointer;
      }
      .danger-button:hover {
        background: #c62828;
      }
      #overlay {
        position: fixed; top: 0; left: 0; right: 0; bottom: 0;
        background: rgba(0,0,0,0.6); color: white;
        font-size: 24px; display: none; align-items: center; justify-content: center;
        z-index: 1000;
      }
    </style>
    <script>
      function showOverlay() {
        document.getElementById('overlay').style.display = 'flex';
      }
      // statusText is now defined on the server side, but client can have a version for initial render/fall back
      const statusTextClient = [
        "ยังไม่มีผู้ป่วยลงทะเบียน",
        "✅ ลงทะเบียนแล้ว กำลังเดินทางไปจุดคัดกรอง",
        "🔄 กำลังคัดกรอง",
        "🚶🏻 คัดกรองเสร็จแล้ว กำลังไปห้องตรวจ ",
        "👨🏻‍⚕️ ถึงห้องตรวจแล้ว กำลังเข้าพบแพทย์",
        "🏦 พบแพทย์เสร็จแล้ว กำลังไปห้องชำระเงิน",
        "🧾 ชำระเงินแล้ว กำลังไปรับยา",
        "💊 รับยาและคืนอุปกรณ์แล้ว",
        "⏳ กำลังรอแตะบัตร NFC...",
        "✅ ชำระเงิน และคืนอุปกรณ์แล้ว",
        "📦 จ่ายเงินเรียบร้อย",
        "💊 รับยาแล้ว"
      ];

      function getDeptNameClient(code) { // Renamed to avoid conflict if function is also server-side
        if (code === "m1") return "คลินิกหู คอ จมูก";
        if (code === "m2") return "คลินิกกายภาพบำบัด";
        return code; // Fallback if code is not m1/m2
      }
      async function fetchStatus() {
        try {
          const res = await fetch('/status');
          const data = await res.json();

          const deptName = getDeptNameClient(data.dept);
          let currentStatusString = statusTextClient[data.step]; // Get text from client-side array
          if (data.step === 3) { // STEP_TO_DOCTOR
            currentStatusString += deptName; // Append department name for this specific step
          }

          document.getElementById("status").innerText = currentStatusString;
          // *** FIX: Update UID and Name fields ***
          document.getElementById("uid").innerText = data.uid || "N/A"; // Use data.uid, default to N/A
          document.getElementById("name").innerText = data.name || "N/A"; // Use data.name, default to N/A
          document.getElementById("dept").innerText = deptName;

          // Handle overlay visibility based on step
          if (data.step == 8) { // STEP_WAITNFC
            document.getElementById('overlay').style.display = 'flex';
          } else {
            document.getElementById('overlay').style.display = 'none';
          }

        } catch (error) {
          console.error("Failed to fetch status:", error);
          // Optionally, display a "connection lost" message on the UI
        }
      }

      setInterval(fetchStatus, 1000);
    </script>
  </head><body>
    <div id='overlay'>⏳ รอการแตะอุปกรณ์นำทางผู้ป่วย...</div>
    <h1 class='title'>สถานีลงทะเบียน</h1>
    <h1 class='title'>Smart Guide</h1>
    <hr>
    <div class='status-box'>
      <h2>ลงทะเบียนผู้ป่วย</h2>
      <form action='/register' method='POST' onsubmit='showOverlay()'>
        ชื่อ: <input name='name' value='")rawliteral";
  html += registeredName; // Pre-fill name if available
  html += R"rawliteral(''><br>
        แผนก:
        <select name='dept'>
          <option value='คลินิกหู คอ จมูก' )rawliteral";
  if (registeredDept == "m1") html += "selected";
  html += R"rawliteral(>คลินิกหู คอ จมูก</option>
          <option value='คลินิกกายภาพบำบัด' )rawliteral";
  if (registeredDept == "m2") html += "selected";
  html += R"rawliteral(>คลินิกกายภาพบำบัด</option>
        </select><br>
        <input type='submit' value='ยืนยัน'>
      </form>
    </div>
    <hr>
    <div class='status-box'>
      <p><b>สถานะปัจจุบัน:</b> <span id='status'>")rawliteral";

  String statusTextForInitialRender = String(registrationStatusText[currentStep]);
  if (currentStep == STEP_TO_DOCTOR) {
    statusTextForInitialRender += getDeptName(registeredDept); // Append translated dept name for initial render
  }
  html += statusTextForInitialRender;
  html += R"rawliteral(</span></p>
      <p><b>รหัสผู้ป่วย:</b> <span id='uid'>")rawliteral";
  html += registeredPatientID;
  html += R"rawliteral(</span></p>
      <p><b>ชื่อ:</b> <span id='name'>")rawliteral";
  html += registeredName;
  html += R"rawliteral(</span></p>
      <p><b>แผนก:</b> <span id='dept'>")rawliteral";
  html += getDeptName(registeredDept); // Use getDeptName for initial render as well
  html += R"rawliteral(</span></p>
  <form action='/clear' method='POST' onsubmit='return confirm("ล้างข้อมูลผู้ป่วยทั้งหมด?")'>
    <button type='submit' class='danger-button'>🧹 ล้างข้อมูลผู้ป่วยทั้งหมด</button>
  </form>
  )rawliteral";
  html += "</p></div></body></html>";

  server.send(200, "text/html; charset=utf-8", html);
}

void handleRegister() {
  registeredName = server.arg("name");
  String rawDept = server.arg("dept");
  if (rawDept.indexOf("หู") >= 0) registeredDept = "m1";
  else if (rawDept.indexOf("กายภาพ") >= 0) registeredDept = "m2";
  else registeredDept = "unknown"; // Should not happen with dropdown, but good for robustness
  waitingForNFC = true;
  currentStep = STEP_WAITNFC;
  Serial.println("🟡 รอการแตะบัตร NDEF...");
  server.sendHeader("Location", "/", true); // Redirect back to root to refresh the page
  server.send(302, "text/plain", "");
}

void setup() {
  Serial.begin(115200);
  delay(100); // Small delay for serial init

  Wire.begin(SDA_PIN, SCL_PIN, 400000);
  nfc.begin();
  uint32_t versiondata = nfc.getFirmwareVersion();
  if (!versiondata) {
    Serial.println("❌ Didn't find PN532! Halting.");
    while (1)
      ;  // halt
  }
  nfc.SAMConfig();  // ต้องมีเสมอหลัง begin()

  Serial.println("✅ PN532 Ready (Adafruit)");

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  digitalWrite(LED1_PIN, HIGH); // LED1 on by default (idle)
  digitalWrite(LED2_PIN, LOW); // LED2 off by default

  connectToWiFiWithMDNS(); // Connect to WiFi and start mDNS

  server.on("/", handleRoot);
  server.on("/register", HTTP_POST, handleRegister);
  server.on("/status", []() {
    String json = "{";
    json += "\"step\":" + String(currentStep) + ",";
    json += "\"dept\":\"" + registeredDept + "\",";
    json += "\"uid\":\"" + registeredPatientID + "\","; // *** FIX: Include patient ID
    json += "\"name\":\"" + registeredName + "\"";     // *** FIX: Include patient name
    json += "}";
    server.send(200, "application/json", json);
  });
  server.on("/setstep", []() {
    if (!server.hasArg("value")) {
      server.send(400, "text/plain", "Missing 'value'");
      return;
    }
    int newStep = server.arg("value").toInt();

    // Validate the incoming step value against the enum range
    if (newStep < STEP_INITIAL || newStep > STEP_FINISHGETPILL) {
      server.send(400, "text/plain", "Invalid step");
      return;
    }

    currentStep = static_cast<RegistrationStep>(newStep);
    Serial.println("🆕 เปลี่ยนสถานะ currentStep = " + String(currentStep) + " (" + registrationStatusText[currentStep] + ")");
    server.send(200, "text/plain", "Step updated to " + String(currentStep));
  });

  server.on("/clear", HTTP_POST, []() {
    registeredUIDs.clear();
    registeredPatientID = "";
    registeredName = "";
    registeredDept = "";
    currentStep = STEP_INITIAL; // Reset to initial state
    waitingForNFC = false;

    Serial.println("🧹 ข้อมูลผู้ป่วยถูกล้างเรียบร้อยแล้ว");

    server.sendHeader("Location", "/", true);  // กลับหน้าแรก
    server.send(302, "text/plain", "");
  });

  server.begin();
  Serial.println("✅ Web server started.");
}

void loop() {
  server.handleClient();
  //MDNS.update(); // Keep mDNS service alive
  yield();

  if (waitingForNFC) {
    uint8_t uid[7];
    uint8_t uidLength;

    // Read NFC with a timeout to avoid blocking loop too long
    if (nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, uid, &uidLength, 100)) { // Reduced timeout to 100ms
      String uidStr = "";
      for (int i = 0; i < uidLength; i++) {
        if (uid[i] < 0x10) uidStr += "0";
        uidStr += String(uid[i], HEX);
        if (i < uidLength - 1) uidStr += ":";
      }
      uidStr.toUpperCase();

      // 🧠 ค้นหา UID นี้ใน vector
      int index = -1;
      for (int i = 0; i < registeredUIDs.size(); i++) {
        if (registeredUIDs[i] == uidStr) {
          index = i;
          break;
        }
      }

      // 🔢 ถ้าไม่เคยมี → เพิ่ม UID ใหม่และกำหนด ID ผู้ป่วย
      if (index == -1) {
        registeredUIDs.push_back(uidStr);
        index = registeredUIDs.size() - 1; // Index of the newly added UID
      }
      // สร้าง PT000X (index + 1 เพราะ ID ผู้ป่วยเริ่มจาก 1)
      char patientCode[10];
      sprintf(patientCode, "PT%04d", index + 1);
      registeredPatientID = String(patientCode);

      Serial.println("👤 ชื่อ: " + registeredName + " | แผนก: " + registeredDept);

      waitingForNFC = false; // Stop waiting for NFC
      currentStep = STEP_TO_FILTER; // Set initial step for patient flow

      Serial.println("✅ UID: " + uidStr);
      Serial.println("📌 รหัสผู้ป่วย: " + registeredPatientID);

      // LED feedback for successful NFC read and registration
      digitalWrite(LED1_PIN, LOW);  // Turn off idle LED
      digitalWrite(LED2_PIN, HIGH); // Turn on success LED
      ledTimer = millis();
      led21Active = true;
    }
  }
  // 🕒 ตรวจสอบว่า LED2 เปิดครบ 5 วิหรือยัง
  if (led21Active && millis() - ledTimer >= 5000) {
    digitalWrite(LED1_PIN, HIGH);  // ✅ กลับมาเปิด LED1
    digitalWrite(LED2_PIN, LOW);   // ⬛️ ปิด LED2
    led21Active = false;
  }
}
