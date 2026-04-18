#pragma once

#include <Arduino.h>

void connectToWiFiWithMDNS();
bool getStepAndDept(int& step, String& dept);
void setStepOnStation1(int stepValue);

