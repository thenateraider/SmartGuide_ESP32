# Smart Guide Patient Navigation System

ระบบนำทางผู้ป่วยภายในโรงพยาบาลด้วย ESP32-S3, BLE RSSI, NFC, หน้าจอ LVGL และเสียงจาก SD Card

โปรเจกต์นี้แบ่งเป็น 2 ส่วนหลัก:

- `MobileWalk`: อุปกรณ์พกพาของผู้ป่วย ใช้แสดงเส้นทาง, สแกน BLE เพื่อประมาณระยะ, เล่นเสียงแนะนำ และอ่านสถานะจาก Station 1
- `Station1` - `Station5`: สถานีประจำจุดต่าง ๆ ใช้ลงทะเบียน, อัปเดตขั้นตอนการรักษา, ส่ง BLE beacon, อ่าน NFC หรือรับปุ่มกด

## Folder Structure

```text
SmartParcelESP32/
├── ArduinoCode/
│   ├── Mobile/
│   │   └── MobileWalk/
│   │       ├── MobileWalk.ino          # setup/loop หลักของอุปกรณ์ผู้ป่วย
│   │       ├── FlowController.*        # flow หน้าจอและเสียงตาม step/dept
│   │       ├── NavigationScan.*        # BLE scan และคำนวณระยะจาก RSSI
│   │       ├── AudioQueue.*            # queue เล่น MP3 ตามลำดับ
│   │       ├── StationClient.*         # WiFi + HTTP /status จาก Station1
│   │       ├── DriverManager.*         # task battery/power
│   │       └── ไดรเวอร์จอ/เสียง/SD/LVGL เดิม
│   ├── Station1/
│   │   ├── Station1.ino                # web UI ลงทะเบียนและ API กลาง
│   │   ├── StationConfig.h             # pins, WiFi, enum step
│   │   └── StationNetwork.*            # WiFi + mDNS
│   ├── Station2/
│   │   ├── Station2.ino                # จุดคัดกรอง
│   │   ├── StationConfig.h
│   │   ├── StationNetwork.*
│   │   ├── StationNfc.*
│   │   ├── StationBeacon.*
│   │   └── StationFlow.*
│   ├── Station3/                       # ห้องตรวจ โครงสร้างเหมือน Station2
│   ├── Station4/                       # ชำระเงิน ใช้ปุ่มกด
│   └── Station5/                       # รับยา ใช้ปุ่มกด
├── docs/
│   ├── PROJECT_OVERVIEW.md
│   └── DEPENDENCIES.md
├── scripts/
│   └── install_arduino_deps.sh
└── หลักการทำงานโปรเจกต์SmartGuide.docx
```

## Hardware Roles

| Device | Role | Input | BLE name / Host |
| --- | --- | --- | --- |
| Station1 | ลงทะเบียนและเก็บสถานะกลาง | NFC + Web UI | `station1.local` |
| Station2 | จุดคัดกรอง | NFC | `Station2_Filter`, `station2.local` |
| Station3 | ห้องตรวจ | NFC | `Station3_Doctor`, `station3.local` |
| Station4 | ชำระเงิน | Button | `Station4_Payment`, `station4.local` |
| Station5 | รับยา | Button | `Station5_Pharmacy`, `station5.local` |
| MobileWalk | อุปกรณ์ผู้ป่วย | Button + BLE scan + screen + audio | `MobileWalk` |

## Patient Flow

1. เปิด WiFi ชื่อ `SmartGuide` รหัส `88888888`
2. เปิด Station 1-5 ให้เชื่อมต่อ WiFi และเริ่ม mDNS/BLE
3. เปิด MobileWalk
4. เข้าเว็บลงทะเบียนที่ `http://station1.local`
5. ใส่ชื่อผู้ป่วย เลือกแผนก แล้วแตะ NFC ที่ Station1
6. MobileWalk อ่าน `/status` จาก Station1 และแสดงหน้า/เสียงตามขั้นตอน
7. Station2 และ Station3 ใช้ NFC เพื่อยืนยันเข้า/ออกจุดบริการ
8. Station4 และ Station5 ใช้ปุ่มกดเพื่อยืนยันชำระเงิน/รับยา

เส้นทาง `m1` คือคลินิกหู คอ จมูก และไปต่อรับยาที่ Station5  
เส้นทาง `m2` คือคลินิกกายภาพบำบัด และจบหลัง Station4

## Dependencies

ต้องติดตั้ง:

- Arduino IDE หรือ Arduino CLI
- ESP32 board package
- ArduinoJson
- Adafruit PN532
- Adafruit BusIO
- LVGL
- ESP32-audioI2S หรือไลบรารี `Audio.h` ที่ใช้กับ `Audio_PCM5101`

ติดตั้งผ่าน Arduino CLI ได้ด้วย:

```bash
./scripts/install_arduino_deps.sh
```

รายละเอียดอยู่ที่ [docs/DEPENDENCIES.md](docs/DEPENDENCIES.md)

## Upload Order

แนะนำให้อัปโหลด firmware ตามลำดับนี้:

1. `ArduinoCode/Station1/Station1.ino`
2. `ArduinoCode/Station2/Station2.ino`
3. `ArduinoCode/Station3/Station3.ino`
4. `ArduinoCode/Station4/Station4.ino`
5. `ArduinoCode/Station5/Station5.ino`
6. `ArduinoCode/Mobile/MobileWalk/MobileWalk.ino`

หลังอัปโหลดครบ ให้เปิด Serial Monitor ที่ `115200` เพื่อตรวจว่าแต่ละบอร์ดเชื่อม WiFi และเริ่ม mDNS/BLE สำเร็จ

## Notes

- หน้าตาเว็บ Station1 และหน้าจอ MobileWalk ถูกคงไว้ตามโค้ดเดิม
- ค่า WiFi ปัจจุบันฝังไว้เป็น `SmartGuide` / `88888888`
- MobileWalk ใช้ `http://station1.local/status` เพื่ออ่านสถานะกลาง
- ไฟล์เสียงต้องอยู่บน SD Card ตาม path เดิม เช่น `/voice/welcome.mp3`, `/ear/3.mp3`, `/phy/17.mp3`

## GitHub Push

เมื่อต้องการนำขึ้น GitHub:

```bash
git init
git add .
git commit -m "Prepare Smart Guide firmware for GitHub"
git branch -M main
git remote add origin https://github.com/<your-user>/<your-repo>.git
git push -u origin main
```

