#pragma once

#include <Arduino.h>

void connectToWiFiWithMDNS();
bool getStepAndDept(int& step, String& dept);
void setStep(int stepValue);
void sendToMobile(const String& msg);

