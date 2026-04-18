# Smart Guide Patient Navigation System

ระบบนำทางผู้ป่วยภายในโรงพยาบาลด้วย ESP32-S3, BLE RSSI, NFC, Web UI, LVGL display และระบบเสียงจาก SD Card  
An ESP32-S3 based patient navigation system for hospitals using BLE RSSI, NFC, a registration web UI, LVGL screen pages, and SD-card audio guidance.

---

## ภาษาไทย

### ภาพรวมโครงการ

Smart Guide เป็นระบบต้นแบบสำหรับช่วยนำทางผู้ป่วยในโรงพยาบาล โดยให้ผู้ป่วยพกอุปกรณ์ MobileWalk และเดินผ่านสถานีต่าง ๆ ตั้งแต่ลงทะเบียน คัดกรอง พบแพทย์ ชำระเงิน และรับยา ระบบใช้ Station 1 เป็นศูนย์กลางเก็บสถานะปัจจุบันของผู้ป่วย ส่วน Station 2-5 จะอัปเดตสถานะกลับไปที่ Station 1 เมื่อผู้ป่วยแตะ NFC หรือกดปุ่มยืนยัน

อุปกรณ์ MobileWalk จะอ่านสถานะจาก Station 1 ผ่าน HTTP, เปลี่ยนหน้าจอตามขั้นตอน, สแกน BLE beacon ของสถานีปลายทางเพื่อประเมินระยะจาก RSSI และเล่นไฟล์เสียงแนะนำเมื่อผู้ป่วยเข้าใกล้จุดบริการ

### สิ่งที่ระบบทำได้

- ลงทะเบียนผู้ป่วยผ่านเว็บ `http://station1.local`
- สร้างรหัสผู้ป่วยแบบ `PT0001`, `PT0002`, ...
- เลือกเส้นทางการรักษาได้ 2 แผนก: `m1` และ `m2`
- อัปเดตขั้นตอนผู้ป่วยแบบ real-time ผ่าน HTTP API
- ใช้ BLE RSSI เพื่อแสดงระยะโดยประมาณบนอุปกรณ์ MobileWalk
- เล่นเสียงนำทางจาก SD Card ตามแผนกและขั้นตอน
- ใช้ NFC เพื่อยืนยันการมาถึง/ออกจากจุดบริการ
- ใช้ปุ่มกดที่ Station4 และ Station5 เพื่อยืนยันชำระเงิน/รับยา

### อุปกรณ์ในระบบ

| อุปกรณ์ | หน้าที่ | วิธีรับ input | ชื่อ BLE / Host |
| --- | --- | --- | --- |
| Station1 | จุดลงทะเบียนและ server สถานะกลาง | Web UI + NFC | `station1.local` |
| Station2 | จุดคัดกรอง | NFC | `Station2_Filter`, `station2.local` |
| Station3 | ห้องตรวจ | NFC | `Station3_Doctor`, `station3.local` |
| Station4 | จุดชำระเงิน | Button | `Station4_Payment`, `station4.local` |
| Station5 | จุดรับยา | Button | `Station5_Pharmacy`, `station5.local` |
| MobileWalk | อุปกรณ์ผู้ป่วย | BLE scan + display + audio + button | `MobileWalk` |

### การทำงานแบบ End-to-End

1. เปิด WiFi ชื่อ `SmartGuide` รหัส `88888888`
2. เปิด Station 1-5 ให้เชื่อมต่อ WiFi เดียวกัน
3. Station1 เปิดเว็บลงทะเบียนและ API กลางที่ `http://station1.local`
4. Station2-5 เริ่มส่ง BLE beacon ตามชื่อของแต่ละสถานี
5. เปิด MobileWalk แล้วรอเสียงต้อนรับจบ
6. ผู้ดูแลเข้าเว็บ Station1, ใส่ชื่อผู้ป่วย, เลือกแผนก และแตะ NFC
7. Station1 บันทึกผู้ป่วยและเปลี่ยนสถานะเป็น `STEP_TO_FILTER`
8. MobileWalk ดึง `/status` จาก Station1 ทุก 1 วินาที
9. เมื่อสถานะเปลี่ยน MobileWalk จะเปลี่ยนหน้าจอและเล่นเสียงตาม flow
10. เมื่อ MobileWalk ต้องนำทางไปสถานีถัดไป จะสแกน BLE beacon ของสถานีนั้นและแสดงระยะโดยประมาณ
11. เมื่อผู้ป่วยถึง Station2 หรือ Station3 ให้แตะ NFC เพื่ออัปเดต step
12. เมื่อถึง Station4 หรือ Station5 ให้กดปุ่มที่สถานีเพื่ออัปเดต step
13. เมื่อ flow จบ MobileWalk จะกลับไปหน้าให้ลงทะเบียนผู้ป่วยใหม่

### เส้นทางการรักษา

| Code | แผนก | Flow |
| --- | --- | --- |
| `m1` | คลินิกหู คอ จมูก | ลงทะเบียน -> คัดกรอง -> ห้องตรวจ -> ชำระเงิน -> รับยา -> จบ |
| `m2` | คลินิกกายภาพบำบัด | ลงทะเบียน -> คัดกรอง -> ห้องตรวจ -> ชำระเงิน -> จบ |

### ตาราง Step

| Step | ชื่อในโค้ด | ความหมาย |
| --- | --- | --- |
| 0 | `STEP_INITIAL` | ยังไม่มีผู้ป่วยลงทะเบียน |
| 1 | `STEP_TO_FILTER` | ลงทะเบียนแล้ว กำลังเดินทางไปจุดคัดกรอง |
| 2 | `STEP_FILTERING` | อยู่ที่จุดคัดกรอง / กำลังคัดกรอง |
| 3 | `STEP_TO_DOCTOR` | คัดกรองเสร็จแล้ว กำลังไปห้องตรวจ |
| 4 | `STEP_WITH_DOCTOR` | ถึงห้องตรวจ / กำลังพบแพทย์ |
| 5 | `STEP_TO_PAYMENT` | พบแพทย์เสร็จแล้ว กำลังไปชำระเงิน |
| 6 | `STEP_TO_PHARMACY` | ชำระเงินแล้ว กำลังไปรับยา หรือจบ flow สำหรับ `m2` บน Mobile |
| 7 | `STEP_DONE` / `STEP_FINISH_GET_PILL` | รับยาแล้ว / จบ flow สำหรับ `m1` |
| 8 | `STEP_WAITNFC` | ลงทะเบียนผ่านเว็บแล้ว รอแตะ NFC |
| 9 | `STEP_DONE_PHY` | ชำระเงินและคืนอุปกรณ์แล้วสำหรับกายภาพบำบัด |
| 10 | `STEP_PAYFINISH` | สถานะจ่ายเงินเรียบร้อยที่มีไว้รองรับ flow เพิ่มเติม |
| 11 | `STEP_FINISHGETPILL` | รับยาแล้วที่มีไว้รองรับ flow เพิ่มเติม |

### API หลักของ Station1

| Endpoint | ใช้โดย | รายละเอียด |
| --- | --- | --- |
| `GET /` | Browser | หน้าเว็บลงทะเบียนและแสดงสถานะผู้ป่วย |
| `POST /register` | Browser | รับชื่อและแผนก จากนั้นเปลี่ยนเป็นสถานะรอ NFC |
| `GET /status` | MobileWalk, Station2-5 | คืนค่า JSON เช่น `step`, `dept`, `uid`, `name` |
| `GET /setstep?value=<step>` | Station2-5 | เปลี่ยนสถานะกลางของผู้ป่วย |
| `POST /clear` | Browser | ล้างข้อมูลผู้ป่วยทั้งหมด |

### โครงสร้างโฟลเดอร์

```text
SmartParcelESP32/
├── ArduinoCode/
│   ├── Mobile/
│   │   └── MobileWalk/
│   │       ├── MobileWalk.ino          # setup/loop หลักของอุปกรณ์ผู้ป่วย
│   │       ├── MobileConfig.h          # ค่า WiFi, endpoint, pin
│   │       ├── FlowController.*        # flow หน้าจอและเสียงตาม step/dept
│   │       ├── NavigationScan.*        # BLE scan และคำนวณระยะจาก RSSI
│   │       ├── AudioQueue.*            # queue เล่น MP3 ตามลำดับ
│   │       ├── StationClient.*         # WiFi + HTTP /status จาก Station1
│   │       ├── DriverManager.*         # task battery/power
│   │       └── ไดรเวอร์จอ/เสียง/SD/LVGL เดิม
│   ├── Station1/
│   │   ├── Station1.ino                # Web UI ลงทะเบียนและ API กลาง
│   │   ├── StationConfig.h             # pins, WiFi, enum step
│   │   └── StationNetwork.*            # WiFi + mDNS
│   ├── Station2/                       # จุดคัดกรอง: NFC + BLE beacon
│   ├── Station3/                       # ห้องตรวจ: NFC + BLE beacon
│   ├── Station4/                       # ชำระเงิน: button + BLE beacon
│   └── Station5/                       # รับยา: button + BLE beacon
├── docs/
│   ├── PROJECT_OVERVIEW.md
│   └── DEPENDENCIES.md
├── scripts/
│   └── install_arduino_deps.sh
└── หลักการทำงานโปรเจกต์SmartGuide.docx
```

### Dependencies

ต้องติดตั้ง:

- Arduino IDE 2.x หรือ Arduino CLI
- ESP32 board package จาก Espressif
- ArduinoJson
- Adafruit PN532
- Adafruit BusIO
- LVGL
- ESP32-audioI2S หรือไลบรารีที่มี `Audio.h` และเข้ากับ `Audio_PCM5101`

ติดตั้งผ่าน Arduino CLI:

```bash
./scripts/install_arduino_deps.sh
```

รายละเอียดเพิ่มเติมอยู่ที่ [docs/DEPENDENCIES.md](docs/DEPENDENCIES.md)

### ลำดับการอัปโหลด Firmware

แนะนำให้อัปโหลดตามลำดับนี้:

1. `ArduinoCode/Station1/Station1.ino`
2. `ArduinoCode/Station2/Station2.ino`
3. `ArduinoCode/Station3/Station3.ino`
4. `ArduinoCode/Station4/Station4.ino`
5. `ArduinoCode/Station5/Station5.ino`
6. `ArduinoCode/Mobile/MobileWalk/MobileWalk.ino`

หลังอัปโหลด ให้เปิด Serial Monitor ที่ `115200` baud เพื่อตรวจว่า WiFi, mDNS, BLE, NFC และ SD/audio เริ่มทำงานถูกต้อง

### ไฟล์เสียงบน SD Card

MobileWalk เล่นเสียงจาก path เดิมใน SD Card เช่น:

- `/voice/welcome.mp3`
- `/voice/pleasrg.mp3`
- `/ear/1.mp3` ถึง `/ear/17.mp3`
- `/phy/1.mp3` ถึง `/phy/17.mp3`

โฟลเดอร์ `/ear` ใช้กับเส้นทาง `m1` และ `/phy` ใช้กับเส้นทาง `m2`

### การใช้งานจริงโดยย่อ

1. เปิด hotspot/router เป็นชื่อ `SmartGuide` และรหัส `88888888`
2. เปิด Station ทุกตัวก่อน แล้วรอให้เชื่อม WiFi สำเร็จ
3. เปิด MobileWalk ด้วยปุ่มเล็กใต้ช่อง SD Card
4. ใช้มือถือหรือแท็บเล็ตเข้า `http://station1.local`
5. ถ้า Android เข้า hostname ไม่ได้ ให้ดู IP จาก Serial Monitor ของ Station1 แล้วเข้า URL ด้วย IP แทน
6. ลงทะเบียนชื่อผู้ป่วย เลือกแผนก และแตะ NFC ที่ Station1
7. ให้ผู้ป่วยถือ MobileWalk และเดินตามเสียง/หน้าจอ

### Troubleshooting

| ปัญหา | แนวทางตรวจสอบ |
| --- | --- |
| เข้า `station1.local` ไม่ได้ | ตรวจ WiFi ว่าอยู่ network เดียวกัน, ลองใช้ Safari/iOS, หรือใช้ IP จาก Serial Monitor |
| Mobile ไม่เปลี่ยนหน้า | ตรวจว่า Station1 ตอบ `/status`, WiFi ชื่อ/รหัสตรง, mDNS ใช้งานได้ |
| ไม่ได้ยินเสียง | ตรวจ SD Card, path ไฟล์เสียง, ลำโพง/I2S, และไลบรารี `Audio.h` |
| NFC อ่านไม่ได้ | ตรวจสาย SDA/SCL, ไฟเลี้ยง PN532, และ Serial Monitor |
| ระยะ BLE ไม่นิ่ง | RSSI แกว่งตามสภาพแวดล้อม ให้ใช้เป็นระยะโดยประมาณ ไม่ใช่ระยะจริงระดับเซนติเมตร |

---

## English

### Project Overview

Smart Guide is a prototype patient navigation system for hospitals. A patient carries the MobileWalk device and moves through multiple service stations: registration, screening, doctor room, payment, and pharmacy. Station1 acts as the central state server. Station2-5 update the patient state through Station1 when the patient taps an NFC card/device or when staff presses a confirmation button.

The MobileWalk device polls Station1 over HTTP, changes LVGL pages according to the current step, scans BLE beacons from the target station, estimates distance from RSSI, and plays voice guidance from the SD card when the patient approaches a service point.

### Main Features

- Patient registration through `http://station1.local`
- Auto-generated patient IDs such as `PT0001`, `PT0002`, ...
- Two department routes: `m1` and `m2`
- Real-time workflow updates through HTTP APIs
- BLE RSSI based approximate distance display on MobileWalk
- SD-card MP3 voice guidance by department and step
- NFC confirmation at Station2 and Station3
- Button confirmation at Station4 and Station5

### System Devices

| Device | Role | Input | BLE name / Host |
| --- | --- | --- | --- |
| Station1 | Registration point and central state server | Web UI + NFC | `station1.local` |
| Station2 | Screening station | NFC | `Station2_Filter`, `station2.local` |
| Station3 | Doctor room | NFC | `Station3_Doctor`, `station3.local` |
| Station4 | Payment station | Button | `Station4_Payment`, `station4.local` |
| Station5 | Pharmacy station | Button | `Station5_Pharmacy`, `station5.local` |
| MobileWalk | Patient-carried navigation device | BLE scan + display + audio + button | `MobileWalk` |

### End-to-End Workflow

1. Start a WiFi network named `SmartGuide` with password `88888888`
2. Power on Station1-5 and let them join the same WiFi network
3. Station1 hosts the registration page and central API at `http://station1.local`
4. Station2-5 start advertising BLE beacons using their station names
5. Power on MobileWalk and wait until the welcome audio finishes
6. Staff opens the Station1 web UI, enters patient name, selects department, and taps NFC
7. Station1 stores the patient and changes the state to `STEP_TO_FILTER`
8. MobileWalk polls `/status` from Station1 every second
9. When the state changes, MobileWalk updates the screen and plays the matching audio sequence
10. During navigation, MobileWalk scans the target station BLE beacon and displays an approximate distance
11. At Station2 and Station3, NFC taps move the patient to the next step
12. At Station4 and Station5, button presses move the patient to the next step
13. After the workflow finishes, MobileWalk returns to the registration prompt

### Treatment Routes

| Code | Department | Flow |
| --- | --- | --- |
| `m1` | Ear, Nose and Throat clinic | Registration -> Screening -> Doctor -> Payment -> Pharmacy -> Done |
| `m2` | Physical therapy clinic | Registration -> Screening -> Doctor -> Payment -> Done |

### Step Table

| Step | Code Name | Meaning |
| --- | --- | --- |
| 0 | `STEP_INITIAL` | No patient registered |
| 1 | `STEP_TO_FILTER` | Registered and going to screening |
| 2 | `STEP_FILTERING` | At screening / screening in progress |
| 3 | `STEP_TO_DOCTOR` | Screening done and going to doctor room |
| 4 | `STEP_WITH_DOCTOR` | At doctor room / seeing doctor |
| 5 | `STEP_TO_PAYMENT` | Doctor visit done and going to payment |
| 6 | `STEP_TO_PHARMACY` | Payment done and going to pharmacy, or final Mobile state for `m2` |
| 7 | `STEP_DONE` / `STEP_FINISH_GET_PILL` | Medicine received / final state for `m1` |
| 8 | `STEP_WAITNFC` | Registration submitted and waiting for NFC tap |
| 9 | `STEP_DONE_PHY` | Payment and device return completed for physical therapy |
| 10 | `STEP_PAYFINISH` | Reserved payment-finished state for future flow expansion |
| 11 | `STEP_FINISHGETPILL` | Reserved medicine-received state for future flow expansion |

### Station1 APIs

| Endpoint | Used By | Description |
| --- | --- | --- |
| `GET /` | Browser | Registration and patient status web page |
| `POST /register` | Browser | Receives patient name and department, then waits for NFC |
| `GET /status` | MobileWalk, Station2-5 | Returns JSON with `step`, `dept`, `uid`, and `name` |
| `GET /setstep?value=<step>` | Station2-5 | Updates the central patient step |
| `POST /clear` | Browser | Clears all registered patient data |

### Folder Structure

```text
SmartParcelESP32/
├── ArduinoCode/
│   ├── Mobile/
│   │   └── MobileWalk/
│   │       ├── MobileWalk.ino          # Main setup/loop for the patient device
│   │       ├── MobileConfig.h          # WiFi, endpoint, and pin configuration
│   │       ├── FlowController.*        # Screen and audio flow by step/department
│   │       ├── NavigationScan.*        # BLE scan and RSSI distance estimation
│   │       ├── AudioQueue.*            # Ordered MP3 playback queue
│   │       ├── StationClient.*         # WiFi + HTTP /status client for Station1
│   │       ├── DriverManager.*         # Battery/power background task
│   │       └── Existing display/audio/SD/LVGL drivers
│   ├── Station1/
│   │   ├── Station1.ino                # Registration Web UI and central APIs
│   │   ├── StationConfig.h             # Pins, WiFi, and step enum
│   │   └── StationNetwork.*            # WiFi + mDNS setup
│   ├── Station2/                       # Screening: NFC + BLE beacon
│   ├── Station3/                       # Doctor room: NFC + BLE beacon
│   ├── Station4/                       # Payment: button + BLE beacon
│   └── Station5/                       # Pharmacy: button + BLE beacon
├── docs/
│   ├── PROJECT_OVERVIEW.md
│   └── DEPENDENCIES.md
├── scripts/
│   └── install_arduino_deps.sh
└── หลักการทำงานโปรเจกต์SmartGuide.docx
```

### Dependencies

Required tools and libraries:

- Arduino IDE 2.x or Arduino CLI
- Espressif ESP32 board package
- ArduinoJson
- Adafruit PN532
- Adafruit BusIO
- LVGL
- ESP32-audioI2S or another compatible library that provides `Audio.h` for `Audio_PCM5101`

Install with Arduino CLI:

```bash
./scripts/install_arduino_deps.sh
```

More details are available in [docs/DEPENDENCIES.md](docs/DEPENDENCIES.md)

### Firmware Upload Order

Recommended upload order:

1. `ArduinoCode/Station1/Station1.ino`
2. `ArduinoCode/Station2/Station2.ino`
3. `ArduinoCode/Station3/Station3.ino`
4. `ArduinoCode/Station4/Station4.ino`
5. `ArduinoCode/Station5/Station5.ino`
6. `ArduinoCode/Mobile/MobileWalk/MobileWalk.ino`

After uploading, open Serial Monitor at `115200` baud and check that WiFi, mDNS, BLE, NFC, SD card, and audio initialize correctly.

### SD Card Audio Files

MobileWalk expects MP3 files at the original SD card paths:

- `/voice/welcome.mp3`
- `/voice/pleasrg.mp3`
- `/ear/1.mp3` through `/ear/17.mp3`
- `/phy/1.mp3` through `/phy/17.mp3`

The `/ear` folder is used for route `m1`, and `/phy` is used for route `m2`.

### Quick Field Setup

1. Start a hotspot/router with SSID `SmartGuide` and password `88888888`
2. Power on all stations and wait for WiFi connection
3. Power on MobileWalk using the small button below the SD card slot
4. Open `http://station1.local` from a phone or tablet
5. If Android cannot resolve the hostname, use the Station1 IP shown in Serial Monitor
6. Register the patient, choose a department, and tap NFC at Station1
7. Give MobileWalk to the patient and follow the on-screen/audio instructions

### Troubleshooting

| Problem | What to Check |
| --- | --- |
| Cannot open `station1.local` | Check same WiFi network, try Safari/iOS, or use the IP from Serial Monitor |
| MobileWalk does not change screen | Check Station1 `/status`, WiFi credentials, and mDNS connectivity |
| No audio | Check SD card, audio file paths, I2S wiring, speaker, and `Audio.h` library |
| NFC does not read | Check PN532 wiring, SDA/SCL pins, power, and Serial Monitor logs |
| BLE distance is unstable | RSSI is environment-dependent and should be treated as an approximate distance only |

---

## GitHub Push

```bash
git remote add origin https://github.com/<your-user>/<your-repo>.git
git push -u origin main
```

