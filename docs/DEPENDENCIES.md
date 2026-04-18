# Dependencies / รายการที่ต้องติดตั้ง

This document lists the required tools, Arduino board package, libraries, and recommended board settings for building the Smart Guide ESP32 firmware.  
เอกสารนี้สรุปเครื่องมือ Arduino board package ไลบรารี และค่าบอร์ดที่แนะนำสำหรับ compile และ upload firmware ของ Smart Guide ESP32

---

## English

### Required Tools

- Arduino IDE 2.x or Arduino CLI
- Espressif ESP32 board package
- USB driver for the actual ESP32-S3 board in use
- A USB data cable that supports flashing, not charge-only

### Arduino Board Package

Install the ESP32 core by Espressif.

For Arduino IDE:

1. Open Arduino IDE
2. Go to Boards Manager
3. Search for `esp32`
4. Install `esp32 by Espressif Systems`

For Arduino CLI:

```bash
arduino-cli core update-index
arduino-cli core install esp32:esp32
```

### Arduino Libraries

Install these libraries from Arduino IDE Library Manager or by running `scripts/install_arduino_deps.sh`.

- `ArduinoJson`
- `Adafruit PN532`
- `Adafruit BusIO`
- `lvgl`
- `ESP32-audioI2S`, or another compatible library that provides `Audio.h`

These libraries are provided by the ESP32 core and do not normally need separate installation:

- `WiFi`
- `WebServer`
- `HTTPClient`
- `ESPmDNS`
- `BLEDevice`
- `SD_MMC`
- `Wire`

### Install With Arduino CLI

From the project root:

```bash
./scripts/install_arduino_deps.sh
```

The script installs the ESP32 core and the main Arduino libraries used by the project. If the audio library name in Library Manager differs on your machine, install a compatible library that provides `Audio.h` for `Audio_PCM5101`.

### Recommended Board Settings

The exact values depend on the ESP32-S3 board model. These settings are a good starting point:

- Board: ESP32S3 Dev Module, or the exact board model you are using
- Upload speed: 921600, or 115200 if upload fails
- PSRAM: Enabled if the board has PSRAM and LVGL needs more memory
- Flash size: Match the real board flash size
- Serial Monitor: 115200 baud

### Firmware Upload Order

Recommended upload order:

1. `ArduinoCode/Station1/Station1.ino`
2. `ArduinoCode/Station2/Station2.ino`
3. `ArduinoCode/Station3/Station3.ino`
4. `ArduinoCode/Station4/Station4.ino`
5. `ArduinoCode/Station5/Station5.ino`
6. `ArduinoCode/Mobile/MobileWalk/MobileWalk.ino`

### Notes

- Station1 must be running for MobileWalk and Station2-5 to read or update patient state.
- The WiFi SSID and password are currently fixed as `SmartGuide` and `88888888`.
- MobileWalk requires the SD card audio files to be placed in the expected folders such as `/voice`, `/ear`, and `/phy`.
- If compilation cannot find `Audio.h`, install or adjust the compatible ESP32 audio library.

---

## ภาษาไทย

### เครื่องมือที่ต้องใช้

- Arduino IDE 2.x หรือ Arduino CLI
- ESP32 board package จาก Espressif
- USB driver สำหรับบอร์ด ESP32-S3 ที่ใช้งานจริง
- สาย USB data ที่ใช้ flash firmware ได้ ไม่ใช่สายชาร์จอย่างเดียว

### Arduino Board Package

ติดตั้ง ESP32 core จาก Espressif

สำหรับ Arduino IDE:

1. เปิด Arduino IDE
2. เข้า Boards Manager
3. ค้นหา `esp32`
4. ติดตั้ง `esp32 by Espressif Systems`

สำหรับ Arduino CLI:

```bash
arduino-cli core update-index
arduino-cli core install esp32:esp32
```

### Arduino Libraries

ติดตั้งไลบรารีเหล่านี้ผ่าน Arduino IDE Library Manager หรือใช้ `scripts/install_arduino_deps.sh`

- `ArduinoJson`
- `Adafruit PN532`
- `Adafruit BusIO`
- `lvgl`
- `ESP32-audioI2S` หรือไลบรารีที่เข้ากันได้และมีไฟล์ `Audio.h`

ไลบรารีต่อไปนี้มากับ ESP32 core โดยปกติไม่ต้องติดตั้งแยก:

- `WiFi`
- `WebServer`
- `HTTPClient`
- `ESPmDNS`
- `BLEDevice`
- `SD_MMC`
- `Wire`

### ติดตั้งด้วย Arduino CLI

รันจากโฟลเดอร์หลักของโปรเจกต์:

```bash
./scripts/install_arduino_deps.sh
```

สคริปต์จะติดตั้ง ESP32 core และไลบรารีหลักที่ใช้ในโปรเจกต์ ถ้าชื่อไลบรารีเสียงใน Library Manager ไม่ตรงกับเครื่องของคุณ ให้ติดตั้งไลบรารีที่มี `Audio.h` ให้ตรงกับ `Audio_PCM5101`

### ค่าบอร์ดที่แนะนำ

ค่าจริงขึ้นกับรุ่นบอร์ด ESP32-S3 ที่ใช้ แต่โดยทั่วไปเริ่มจากค่านี้ได้:

- Board: ESP32S3 Dev Module หรือรุ่นที่ตรงกับบอร์ดจริง
- Upload speed: 921600 หรือ 115200 ถ้าอัปโหลดไม่ผ่าน
- PSRAM: Enabled ถ้าบอร์ดมี PSRAM และ LVGL ต้องใช้หน่วยความจำเพิ่ม
- Flash size: ตั้งให้ตรงกับบอร์ดจริง
- Serial Monitor: 115200 baud

### ลำดับการอัปโหลด Firmware

แนะนำให้อัปโหลดตามลำดับนี้:

1. `ArduinoCode/Station1/Station1.ino`
2. `ArduinoCode/Station2/Station2.ino`
3. `ArduinoCode/Station3/Station3.ino`
4. `ArduinoCode/Station4/Station4.ino`
5. `ArduinoCode/Station5/Station5.ino`
6. `ArduinoCode/Mobile/MobileWalk/MobileWalk.ino`

### หมายเหตุ

- Station1 ต้องทำงานก่อน เพื่อให้ MobileWalk และ Station2-5 อ่านหรืออัปเดตสถานะผู้ป่วยได้
- WiFi SSID และ password ปัจจุบันตั้งไว้เป็น `SmartGuide` และ `88888888`
- MobileWalk ต้องมีไฟล์เสียงใน SD Card ตามโฟลเดอร์ที่กำหนด เช่น `/voice`, `/ear`, และ `/phy`
- ถ้า compile แล้วหา `Audio.h` ไม่เจอ ให้ติดตั้งหรือปรับไลบรารีเสียง ESP32 ที่เข้ากันได้

