#ifndef LCD_COMPONENT_H
#define LCD_COMPONENT_H

#include <lvgl.h>

// หน้าจอทั้งหมด
extern lv_obj_t *pageWelcome;
extern lv_obj_t *pageToFilter;
extern lv_obj_t *pageToDoctor;
extern lv_obj_t *pageToPayment;
extern lv_obj_t *pageToPharmacy;

extern lv_obj_t *page_startm1;
extern lv_obj_t *page_startm2;

extern lv_obj_t *page_inweightcheckm1;
extern lv_obj_t *page_inweightcheckm2; // แก้ไขบรรทัดนี้

extern lv_obj_t *page_outweightcheckm1;
extern lv_obj_t *page_outweightcheckm2;

extern lv_obj_t *pageToDoctorm1;
extern lv_obj_t *pageToDoctorm2;

extern lv_obj_t *pageInDoctorm1;
extern lv_obj_t *pageInDoctorm2;

extern lv_obj_t *page_outm1;
extern lv_obj_t *page_outm2;

extern lv_obj_t *pageToPaymentm1;
extern lv_obj_t *pageToPaymentm2;

extern lv_obj_t *page_paysuccessm1;
extern lv_obj_t *page_paysuccessm2;

extern lv_obj_t *page_donem1;
extern lv_obj_t *page_donem2;

extern lv_obj_t *pageThankYou;
extern lv_obj_t *pageRegisterPrompt;
extern lv_obj_t *pageInProgress;

// Labels เฉพาะระยะทาง - แยกสำหรับแต่ละเส้นทาง
extern lv_obj_t *label_distance_filter;
extern lv_obj_t *label_distance_doctor_m1; // เพิ่มใหม่สำหรับ M1
extern lv_obj_t *label_distance_doctor_m2; // เพิ่มใหม่สำหรับ M2
extern lv_obj_t *label_distance_payment_m1; // เพิ่มใหม่สำหรับ M1
extern lv_obj_t *label_distance_payment_m2; // เพิ่มใหม่สำหรับ M2
extern lv_obj_t *label_distance_pharmacy;

// Labels สำหรับหน้าInProgress
extern lv_obj_t *label_inprogress_subtext;

// Function prototypes
void createPages();
void loadPage(lv_obj_t* page);
void updateNavigationInfo(const char* text, lv_obj_t* label); // ประกาศฟังก์ชันนี้
// ไม่ต้องประกาศ getPageName ที่นี่ถ้าจะนิยามใน main.ino
// ไม่ต้องประกาศ updateNavigationInfoWithDebug ที่นี่ถ้าจะนิยามใน main.ino

#endif // LCD_COMPONENT_H