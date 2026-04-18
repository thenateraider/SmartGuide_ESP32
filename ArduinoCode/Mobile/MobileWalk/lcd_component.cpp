#include "lcd_component.h"
#include "IBMTH_24.h"
#include <lvgl.h>
#include <vector>
#include <queue>
#include <functional>
#include <stdio.h>
#include <string.h>
// Page object definitions
lv_obj_t *pageWelcome;
lv_obj_t *pageToFilter;
lv_obj_t *pageToDoctor;
lv_obj_t *pageToPayment;
lv_obj_t *pageToPharmacy;

lv_obj_t *page_startm1;
lv_obj_t *page_startm2;

lv_obj_t *page_inweightcheckm1;
lv_obj_t *page_inweightcheckm2;

lv_obj_t *page_outweightcheckm1;
lv_obj_t *page_outweightcheckm2;

lv_obj_t *pageToDoctorm1;
lv_obj_t *pageToDoctorm2; // <-- บรรทัดนี้ผิด ควรจะเป็น extern lv_obj_t *pageToDoctorm2;

lv_obj_t *pageInDoctorm1;
lv_obj_t *pageInDoctorm2;

lv_obj_t *page_outm1;
lv_obj_t *page_outm2;

lv_obj_t *pageToPaymentm1;
lv_obj_t *pageToPaymentm2;

lv_obj_t *page_paysuccessm1;
lv_obj_t *page_paysuccessm2;

lv_obj_t *page_donem1;
lv_obj_t *page_donem2;

lv_obj_t *pageThankYou;
lv_obj_t *pageRegisterPrompt;
lv_obj_t *pageInProgress;

// Labels per screen
lv_obj_t *label_distance_filter;
lv_obj_t *label_distance_doctor_m1; // ประกาศใหม่
lv_obj_t *label_distance_doctor_m2; // ประกาศใหม่
lv_obj_t *label_distance_payment_m1; // ประกาศใหม่
lv_obj_t *label_distance_payment_m2; // ประกาศใหม่
lv_obj_t *label_distance_pharmacy;
lv_obj_t *label_inprogress_subtext;

void createSimpleCenteredPage(lv_obj_t **page, const char* title, lv_color_t bgColor, lv_obj_t** out_label_distance) {
  *page = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(*page, bgColor, LV_PART_MAIN);
  lv_obj_set_style_bg_opa(*page, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_set_flex_flow(*page, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(*page, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  lv_obj_t *label_title = lv_label_create(*page);
  lv_label_set_text(label_title, title);
  lv_obj_set_style_text_font(label_title, &IBMTH_24, LV_PART_MAIN);
  lv_obj_set_style_text_align(label_title, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_width(label_title, lv_pct(100));
  lv_obj_set_style_pad_bottom(label_title, 10, 0);
  lv_obj_align(label_title, LV_ALIGN_CENTER, 0, -30);

  if (out_label_distance) {
    *out_label_distance = lv_label_create(*page);
    lv_label_set_text(*out_label_distance, "ระยะทาง: ");
    lv_obj_set_style_text_font(*out_label_distance, &IBMTH_24, LV_PART_MAIN);
    lv_obj_set_width(*out_label_distance, lv_pct(90));
    lv_obj_set_style_text_align(*out_label_distance, LV_TEXT_ALIGN_CENTER, 0);
  }
}

void updateNavigationInfo(const char* text, lv_obj_t* label) {
  printf("[DEBUG_NAV] updateNavigationInfo called. label: %p, text: \"%s\"\n", (void*)label, text); // Debug Point 1

  if (label) {
    lv_label_set_text(label, text);
    lv_obj_invalidate(label);
    lv_refr_now(NULL);
    printf("[DEBUG_NAV] Label text set. Invalidated and refreshed.\n"); // Debug Point 2
  } else {
    printf("[DEBUG_NAV] Label is NULL, cannot update.\n"); // Debug Point 3
  }
}

void createPages() {
  pageWelcome = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(pageWelcome, lv_color_white(), LV_PART_MAIN);
  lv_obj_set_style_bg_opa(pageWelcome, LV_OPA_COVER, LV_PART_MAIN);
  {
    lv_obj_t *label = lv_label_create(pageWelcome);
    lv_label_set_text(label, "SMART\nGuide\nกล่องนำทาง\nอัจฉริยะ");
    lv_obj_set_style_text_font(label, &IBMTH_24, LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
  }

  createSimpleCenteredPage(&pageRegisterPrompt, " ยินดีต้อนรับ\n\nกรุณาลงทะเบียน\nกับเจ้าหน้าที่", lv_color_hex(0xD1C4E9), nullptr);
  createSimpleCenteredPage(&page_startm1, "เริ่มต้น\nการนำทาง\nให้เราดูแลคุณวันนี้\n\nคลินิคหูคอจมูก", lv_color_hex(0xFF3EAA), nullptr);
  createSimpleCenteredPage(&page_startm2, "เริ่มต้น\nการนำทาง\nให้เราดูแลคุณวันนี้\n\nคลินิค\nกายภาพบำบัด", lv_color_hex(0xCE7E00), nullptr);
  createSimpleCenteredPage(&pageToFilter, " ถัดไป\n\nแผนกคัดกรอง\nชั่งน้ำหนัก\nวัดความดัน", lv_color_hex(0xFFF9C4), &label_distance_filter);
  createSimpleCenteredPage(&page_inweightcheckm1, "กำลังชั่งน้ำหนัก\n\nวัดความดัน\n\nถัดไป : คลินิคหูคอจมูก", lv_color_hex(0xFFF59D), nullptr);
  createSimpleCenteredPage(&page_inweightcheckm2, "กำลังชั่งน้ำหนัก\n\nวัดความดัน\n\nถัดไป : ห้องกายภาพบำบัด", lv_color_hex(0xFFF59D), nullptr);
  createSimpleCenteredPage(&page_outweightcheckm1, "คัดกรอง ชั่งน้ำหนัก\nวัดความดัน\nเรียบร้อยแล้ว", lv_color_hex(0xBBDEFB), nullptr);
  createSimpleCenteredPage(&page_outweightcheckm2, "คัดกรอง ชั่งน้ำหนัก\nวัดความดัน\nเรียบร้อยแล้ว", lv_color_hex(0xBBDEFB), nullptr);
  createSimpleCenteredPage(&pageToDoctorm1, "ถัดไป : พบแพทย์\n(หู คอ จมูก)\n", lv_color_hex(0xE1BEE7), &label_distance_doctor_m1); // ใช้ label_distance_doctor_m1
  createSimpleCenteredPage(&pageToDoctorm2, "ถัดไป : พบแพทย์\n(กายภาพบำบัด)\n", lv_color_hex(0xE1BEE7), &label_distance_doctor_m2); // ใช้ label_distance_doctor_m2
  createSimpleCenteredPage(&pageInDoctorm1, "กำลังพบแพทย์ \n(หู คอ จมูก)\n", lv_color_hex(0xE1BEE7), nullptr);
  createSimpleCenteredPage(&pageInDoctorm2, "กำลังพบแพทย์ \n(กายภาพบำบัด)\n", lv_color_hex(0xE1BEE7), nullptr);
  createSimpleCenteredPage(&page_outm1, "พบแพทย์เสร็จสิ้น ไปห้องการเงิน", lv_color_hex(0xFFE082), nullptr);
  createSimpleCenteredPage(&page_outm2, "พบแพทย์เสร็จสิ้น ไปห้องการเงิน", lv_color_hex(0xFFE082), nullptr);
  createSimpleCenteredPage(&pageToPaymentm1, "ถัดไป : ชำระเงิน \nเดินตรงมาทางซ้าย\nจาก\nคลินิคหู คอ จมูก", lv_color_hex(0xFFE082), &label_distance_payment_m1); // ใช้ label_distance_payment_m1
  createSimpleCenteredPage(&pageToPaymentm2, "ถัดไป : ชำระเงิน \nเดินตรงมาทางขวา\nจากห้องกายภาพบำบัด", lv_color_hex(0xFFE082), &label_distance_payment_m2); // ใช้ label_distance_payment_m2
  createSimpleCenteredPage(&page_paysuccessm1, "ชำระเงินเสร็จสิ้น\nโปรดรับยา\nที่ห้องจ่ายยา", lv_color_hex(0xDCEDC8), nullptr);
  createSimpleCenteredPage(&page_paysuccessm2, "ชำระเงินเสร็จสิ้น\nโปรดคืนอุปกรณ์\n", lv_color_hex(0xDCEDC8), nullptr);
  createSimpleCenteredPage(&pageToPharmacy, " ถัดไป : รับยา", lv_color_hex(0xDCEDC8), &label_distance_pharmacy);
  createSimpleCenteredPage(&page_donem1, "จบกระบวนการ \nขอบคุณครับ", lv_color_hex(0xF8BBD0), nullptr);
  createSimpleCenteredPage(&page_donem2, "จบกระบวนการ \nขอบคุณครับ", lv_color_hex(0xF8BBD0), nullptr);
  createSimpleCenteredPage(&pageThankYou, " ขอบคุณที่ใช้บริการ Smart Guide", lv_color_hex(0xF8BBD0), nullptr);

  pageInProgress = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(pageInProgress, lv_color_hex(0xFFF3E0), LV_PART_MAIN);
  lv_obj_set_style_bg_opa(pageInProgress, LV_OPA_COVER, LV_PART_MAIN);
  lv_obj_set_flex_flow(pageInProgress, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(pageInProgress, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  lv_obj_t *label_main = lv_label_create(pageInProgress);
  lv_label_set_text(label_main, "กำลังดำเนินการ...");
  lv_obj_set_style_text_font(label_main, &IBMTH_24, LV_PART_MAIN);
  lv_obj_set_style_text_align(label_main, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_set_width(label_main, lv_pct(100));
  lv_obj_set_style_pad_bottom(label_main, 10, 0);

  label_inprogress_subtext = lv_label_create(pageInProgress);
  lv_label_set_text(label_inprogress_subtext, "");
  lv_obj_set_style_text_font(label_inprogress_subtext, &IBMTH_24, LV_PART_MAIN);
  lv_obj_set_width(label_inprogress_subtext, lv_pct(90));
  lv_obj_set_style_text_align(label_inprogress_subtext, LV_TEXT_ALIGN_CENTER, 0);
}

void loadPage(lv_obj_t *page) {
  lv_scr_load(page);
  lv_refr_now(NULL);
}

void updateInProgressSubtext(const char* msg) {
  if (label_inprogress_subtext) {
    lv_label_set_text(label_inprogress_subtext, msg);
    lv_refr_now(NULL);
  }
}