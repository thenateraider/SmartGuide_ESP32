#pragma once

#include <Arduino.h>
#include <lvgl.h>

float estimateDistance(int rssi, int txPower = -69);
void updateBLEScanForCurrentStep();
void updateProximityScan(const String& targetName, const String& dept, lv_obj_t* labelDistance, const char* voiceFile);

