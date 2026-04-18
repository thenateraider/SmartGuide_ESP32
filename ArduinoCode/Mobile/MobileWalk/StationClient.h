#pragma once

#include <Arduino.h>

void connectToStationWiFi();
bool fetchStepAndDept(int& step, String& dept);

