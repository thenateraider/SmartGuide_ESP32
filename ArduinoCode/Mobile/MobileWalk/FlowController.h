#pragma once

#include <Arduino.h>
#include <lvgl.h>

extern lv_obj_t* pendingPageToLoad;
extern bool readytostart;
extern bool enableScanFilter;
extern bool enableScanDoctor;
extern bool enableScanPayment;
extern bool enableScanPharmacy;

void checkStatusAndUpdateScreen();
void handleM1DoneByButton();

