# Dependencies

## Required Tools

- Arduino IDE 2.x หรือ Arduino CLI
- ESP32 board package จาก Espressif
- USB driver สำหรับบอร์ด ESP32-S3 ที่ใช้งานจริง

## Arduino Libraries

ติดตั้งไลบรารีเหล่านี้ใน Arduino IDE ผ่าน Library Manager หรือใช้ `scripts/install_arduino_deps.sh`

- `ArduinoJson`
- `Adafruit PN532`
- `Adafruit BusIO`
- `lvgl`
- `ESP32-audioI2S` หรือไลบรารีที่ให้ไฟล์ `Audio.h`

ไลบรารีต่อไปนี้มาจาก ESP32 core:

- `WiFi`
- `WebServer`
- `HTTPClient`
- `ESPmDNS`
- `BLEDevice`
- `SD_MMC`
- `Wire`

## Arduino CLI Install

```bash
./scripts/install_arduino_deps.sh
```

สคริปต์จะติดตั้ง ESP32 core และไลบรารีหลักที่ใช้ในโปรเจกต์ ถ้าชื่อไลบรารีเสียงใน Library Manager ไม่ตรงกับเครื่องของคุณ ให้ติดตั้งไลบรารีที่มี `Audio.h` ให้ตรงกับ `Audio_PCM5101.h`

## Board Settings

ค่าจริงขึ้นกับบอร์ด ESP32-S3 ที่ใช้ แต่โดยทั่วไปให้เลือก:

- Board: ESP32S3 Dev Module หรือรุ่นที่ตรงกับบอร์ดจริง
- Upload speed: 921600 หรือ 115200 ถ้าอัปโหลดไม่ผ่าน
- PSRAM: Enabled ถ้าบอร์ดมี PSRAM และใช้ LVGL
- Flash size: ตามบอร์ดจริง
- Serial Monitor: 115200 baud

