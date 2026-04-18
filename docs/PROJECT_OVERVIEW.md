# Smart Guide Patient Navigation System

ระบบนำทางผู้ป่วยอัจฉริยะในโรงพยาบาล

This document summarizes the working concept from `หลักการทำงานโปรเจกต์SmartGuide.docx` in a GitHub-friendly bilingual format.  
เอกสารนี้สรุปแนวคิดจากไฟล์ `หลักการทำงานโปรเจกต์SmartGuide.docx` ให้อ่านง่ายบน GitHub ในรูปแบบสองภาษา

---

## English

### Objective

Smart Guide is a patient navigation system for hospitals. It uses ESP32-S3 devices on both the patient side and the station side, together with BLE RSSI, NFC, HTTP, display pages, and audio guidance. The goal is to help patients move through hospital service points with less confusion and clearer step-by-step guidance.

### System Components

- Station1: Registration station, central web server, and central patient-state API
- Station2: Screening station using NFC to confirm screening arrival and completion
- Station3: Doctor room station using NFC to confirm doctor-room arrival and departure
- Station4: Payment station using a button to confirm payment
- Station5: Pharmacy station using a button to confirm medicine pickup for route `m1`
- MobileWalk: Patient-carried device that displays instructions, scans BLE for approximate distance, and plays audio guidance

### Working Principle

The system is built around one central state machine stored on Station1. Every patient workflow is represented by a numeric `step`. MobileWalk reads this state from Station1, while Station2-5 update it after real-world confirmation events such as NFC taps or button presses.

MobileWalk does not decide the whole workflow by itself. It reads `step` and `dept` from Station1 through `GET /status`. When the value changes, MobileWalk updates its LVGL page, queues the correct MP3 audio files, and enables BLE scanning for the next target station.

Station2-5 advertise BLE beacon names. MobileWalk scans for the expected name, reads RSSI, estimates distance, and shows the approximate distance on screen. When the device gets close enough, it can play an arrival guidance sound.

### RSSI Distance Formula

The project estimates BLE distance with this formula from `NavigationScan.cpp`:

```cpp
float estimateDistance(int rssi, int txPower = -69) {
  if (rssi == 0) return -1.0;

  float ratio = rssi * 1.0 / txPower;
  if (ratio < 1.0) {
    return pow(ratio, 10);
  }

  return 0.89976 * pow(ratio, 7.7095) + 0.111;
}
```

Formula:

```text
ratio = RSSI / TxPower

if ratio < 1:
    distance = ratio^10
else:
    distance = 0.89976 * ratio^7.7095 + 0.111
```

Variable meaning:

- `RSSI`: received BLE signal strength in dBm
- `TxPower`: reference RSSI at about 1 meter, currently `-69`
- `distance`: estimated distance in meters

BLE RSSI is only an approximation. Walls, people, device orientation, antenna position, and wireless interference can change the reading.

### Communication

- MobileWalk -> Station1: `GET /status`
- Station2-5 -> Station1: `GET /setstep?value=<step>`
- Station2-5 -> MobileWalk: BLE beacon advertising
- Browser -> Station1: Web registration form and status page

### Main Steps

| Step | Meaning |
| --- | --- |
| 0 | No patient registered |
| 1 | Registered and going to screening |
| 2 | Screening in progress |
| 3 | Screening completed and going to doctor room |
| 4 | At doctor room |
| 5 | Doctor visit completed and going to payment |
| 6 | Payment completed and going to pharmacy, or final route for `m2` |
| 7 | Medicine received and route completed |
| 8 | Waiting for NFC after web registration |
| 9 | Payment and device return completed for physical therapy |

### Field Usage

1. Start WiFi with SSID `SmartGuide` and password `88888888`
2. Power on all stations after WiFi is available
3. Power on MobileWalk using the small button below the SD card slot
4. Open `http://station1.local` with Safari or use the Station1 IP address if mDNS does not resolve
5. Register patient name, select department, and tap NFC to start the workflow

---

## ภาษาไทย

### เป้าหมาย

Smart Guide เป็นระบบนำทางผู้ป่วยภายในโรงพยาบาล โดยใช้ ESP32-S3 ทั้งฝั่งผู้ป่วยและฝั่งสถานี ร่วมกับ BLE RSSI, NFC, HTTP, หน้าจอแสดงผล และระบบเสียง เป้าหมายคือช่วยให้ผู้ป่วยเดินไปยังจุดบริการต่าง ๆ ได้ง่ายขึ้น ลดความสับสน และมีคำแนะนำทีละขั้นตอน

### องค์ประกอบในระบบ

- Station1: จุดลงทะเบียน เว็บเซิร์ฟเวอร์กลาง และ API กลางสำหรับสถานะผู้ป่วย
- Station2: จุดคัดกรอง ใช้ NFC เพื่อยืนยันการมาถึงและคัดกรองเสร็จ
- Station3: ห้องตรวจ ใช้ NFC เพื่อยืนยันการเข้าห้องตรวจและออกจากห้องตรวจ
- Station4: จุดชำระเงิน ใช้ปุ่มกดเพื่อยืนยันการชำระเงิน
- Station5: จุดรับยา ใช้ปุ่มกดเพื่อยืนยันการรับยา เฉพาะเส้นทาง `m1`
- MobileWalk: อุปกรณ์ผู้ป่วย ใช้แสดงคำแนะนำ สแกน BLE เพื่อประมาณระยะ และเล่นเสียงนำทาง

### หลักการทำงาน

ระบบนี้ใช้ Station1 เป็น state machine กลาง สถานะการเดินทางของผู้ป่วยแทนด้วยตัวเลข `step` โดย MobileWalk จะอ่านสถานะจาก Station1 ส่วน Station2-5 จะอัปเดตสถานะหลังเกิดเหตุการณ์จริง เช่น แตะ NFC หรือกดปุ่ม

MobileWalk ไม่ได้ตัดสิน flow ทั้งหมดเอง แต่จะอ่าน `step` และ `dept` จาก Station1 ผ่าน `GET /status` เมื่อค่ามีการเปลี่ยนแปลง MobileWalk จะเปลี่ยนหน้า LVGL เพิ่มไฟล์เสียง MP3 ที่เกี่ยวข้องเข้า queue และเปิดการสแกน BLE สำหรับสถานีเป้าหมายถัดไป

Station2-5 จะส่ง BLE beacon ด้วยชื่อประจำสถานี MobileWalk จะสแกนหาชื่อที่คาดไว้ อ่านค่า RSSI ประมาณระยะ และแสดงระยะโดยประมาณบนหน้าจอ เมื่อเข้าใกล้พอ ระบบสามารถเล่นเสียงแจ้งเตือนการถึงจุดบริการได้

### สูตรคำนวณระยะจาก RSSI

โปรเจกต์ใช้สูตรคำนวณระยะ BLE จาก `NavigationScan.cpp`:

```cpp
float estimateDistance(int rssi, int txPower = -69) {
  if (rssi == 0) return -1.0;

  float ratio = rssi * 1.0 / txPower;
  if (ratio < 1.0) {
    return pow(ratio, 10);
  }

  return 0.89976 * pow(ratio, 7.7095) + 0.111;
}
```

เขียนเป็นสมการ:

```text
ratio = RSSI / TxPower

ถ้า ratio < 1:
    distance = ratio^10
ถ้า ratio >= 1:
    distance = 0.89976 * ratio^7.7095 + 0.111
```

ความหมายของตัวแปร:

- `RSSI`: ค่าความแรงสัญญาณ BLE ที่รับได้ หน่วย dBm
- `TxPower`: ค่า RSSI อ้างอิงที่ระยะประมาณ 1 เมตร ปัจจุบันตั้งไว้ที่ `-69`
- `distance`: ระยะโดยประมาณ หน่วยเมตร

ค่า BLE RSSI เป็นเพียงค่าประมาณ เพราะได้รับผลกระทบจากผนัง คนเดินผ่าน ทิศทางอุปกรณ์ ตำแหน่งเสาอากาศ และสัญญาณรบกวน

### การสื่อสาร

- MobileWalk -> Station1: `GET /status`
- Station2-5 -> Station1: `GET /setstep?value=<step>`
- Station2-5 -> MobileWalk: ส่ง BLE beacon
- Browser -> Station1: หน้าเว็บลงทะเบียนและดูสถานะ

### Step หลัก

| Step | ความหมาย |
| --- | --- |
| 0 | ยังไม่มีผู้ป่วยลงทะเบียน |
| 1 | ลงทะเบียนแล้ว กำลังไปจุดคัดกรอง |
| 2 | กำลังคัดกรอง |
| 3 | คัดกรองเสร็จแล้ว กำลังไปห้องตรวจ |
| 4 | อยู่ที่ห้องตรวจ |
| 5 | พบแพทย์เสร็จแล้ว กำลังไปชำระเงิน |
| 6 | ชำระเงินแล้ว กำลังไปรับยา หรือจบสำหรับ `m2` |
| 7 | รับยาและจบกระบวนการ |
| 8 | รอแตะ NFC หลังลงทะเบียน |
| 9 | ชำระเงินและคืนอุปกรณ์แล้วสำหรับกายภาพ |

### การใช้งานหน้างาน

1. เปิด WiFi ชื่อ `SmartGuide` รหัส `88888888`
2. เสียบไฟ Station แต่ละจุดหลัง WiFi พร้อมใช้งาน
3. เปิด MobileWalk ด้วยปุ่มเล็กใต้ช่อง SD Card
4. เข้า `http://station1.local` ด้วย Safari หรือใช้ IP ของ Station1 ถ้าอุปกรณ์ไม่ resolve mDNS
5. ลงทะเบียนชื่อผู้ป่วย เลือกแผนก และแตะ NFC เพื่อเริ่ม flow

