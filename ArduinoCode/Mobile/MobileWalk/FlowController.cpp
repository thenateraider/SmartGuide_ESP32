#include "FlowController.h"

#include "AudioQueue.h"
#include "StationClient.h"
#include "lcd_component.h"

String lastStepKey = "";
unsigned long lastStatusCheck = 0;
bool readytostart = 0;

lv_obj_t* pendingPageToLoad = nullptr;

bool enableScanFilter = false;
bool enableScanDoctor = false;
bool enableScanPayment = false;
bool enableScanPharmacy = false;

void checkStatusAndUpdateScreen() {
  if (millis() - lastStatusCheck > 1000) {
    lastStatusCheck = millis();
    int step;
    String dept;
    if (fetchStepAndDept(step, dept)) {
      String stepKey = String(step) + "_" + dept;

      if (stepKey != lastStepKey) {
        lastStepKey = stepKey;
        printf("[STATUS] Changed: step=%d, dept=%s\n", step, dept.c_str());

        enableScanFilter = enableScanDoctor = enableScanPayment = enableScanPharmacy = false;

        if (step == 0) {
          loadPage(pageRegisterPrompt);
          queue_mp3_file("/voice", "pleasrg.mp3");
        } else if (step == 1 && dept == "m1") {
          loadPage(page_startm1);
          queue_mp3_file("/ear", "1.mp3", []() {
            queue_mp3_file("/ear", "2.mp3", []() {
              pendingPageToLoad = pageToFilter;
              enableScanFilter = true;
              enableScanDoctor = false;
              enableScanPayment = false;
              enableScanPharmacy = false;
            });
          });
        } else if (step == 1 && dept == "m2") {
          loadPage(page_startm2);
          queue_mp3_file("/phy", "1.mp3", []() {
            queue_mp3_file("/phy", "2.mp3", []() {
              pendingPageToLoad = pageToFilter;
              enableScanFilter = true;
              enableScanDoctor = false;
              enableScanPayment = false;
              enableScanPharmacy = false;
            });
          });
        } else if (step == 2 && dept == "m1") {
          loadPage(page_inweightcheckm1);
          queue_mp3_file("/ear", "4.mp3");
        } else if (step == 2 && dept == "m2") {
          loadPage(page_inweightcheckm2);
          queue_mp3_file("/phy", "4.mp3");
        } else if (step == 3 && dept == "m1") {
          loadPage(page_outweightcheckm1);
          queue_mp3_file("/ear", "5.mp3", []() {
            pendingPageToLoad = pageToDoctorm1;
            enableScanDoctor = true;
            enableScanFilter = false;
            enableScanPayment = false;
            enableScanPharmacy = false;
          });
        } else if (step == 3 && dept == "m2") {
          loadPage(page_outweightcheckm2);
          queue_mp3_file("/phy", "5.mp3", []() {
            pendingPageToLoad = pageToDoctorm2;
            enableScanDoctor = true;
            enableScanFilter = false;
            enableScanPayment = false;
            enableScanPharmacy = false;
          });
        } else if (step == 4 && dept == "m1") {
          loadPage(pageInDoctorm1);
          queue_mp3_file("/ear", "7.mp3");
        } else if (step == 4 && dept == "m2") {
          loadPage(pageInDoctorm2);
          queue_mp3_file("/phy", "7.mp3");
        } else if (step == 5 && dept == "m1") {
          loadPage(page_outm1);
          queue_mp3_file("/ear", "8.mp3", []() {
            enableScanPayment = true;
            enableScanFilter = false;
            enableScanDoctor = false;
            enableScanPharmacy = false;
            pendingPageToLoad = pageToPaymentm1;
            queue_mp3_file("/ear", "9.mp3", []() {
              queue_mp3_file("/ear", "10.mp3");
            });
          });
        } else if (step == 5 && dept == "m2") {
          loadPage(page_outm2);
          queue_mp3_file("/phy", "8.mp3", []() {
            pendingPageToLoad = pageToPaymentm2;
            enableScanPayment = true;
            enableScanFilter = false;
            enableScanDoctor = false;
            enableScanPharmacy = false;
            queue_mp3_file("/phy", "9.mp3", []() {
              queue_mp3_file("/phy", "10.mp3");
            });
          });
        } else if (step == 6 && dept == "m1") {
          loadPage(page_paysuccessm1);
          queue_mp3_file("/ear", "12.mp3", []() {
            pendingPageToLoad = pageToPharmacy;
            queue_mp3_file("/ear", "13.mp3", []() {
              enableScanPharmacy = true;
              enableScanFilter = false;
              enableScanDoctor = false;
              enableScanPayment = false;
              queue_mp3_file("/ear", "14.mp3", []() {
                queue_mp3_file("/ear", "15.mp3");
              });
            });
          });
        } else if (step == 6 && dept == "m2") {
          loadPage(page_donem2);
          queue_mp3_file("/phy", "12.mp3", []() {
            queue_mp3_file("/phy", "13.mp3", []() {
              pendingPageToLoad = pageRegisterPrompt;
              queue_mp3_file("/voice", "pleasrg.mp3");
            });
          });
        } else if (step == 7 && dept == "m1") {
          loadPage(page_donem1);
          queue_mp3_file("/ear", "17.mp3", []() {
            pendingPageToLoad = pageRegisterPrompt;
            queue_mp3_file("/voice", "pleasrg.mp3");
          });
        }
      }
    }
  }
}

void handleM1DoneByButton() {
  pendingPageToLoad = page_donem1;
  queue_mp3_file("/ear", "17.mp3", []() {
    pendingPageToLoad = pageRegisterPrompt;
    queue_mp3_file("/voice", "pleasrg.mp3");
  });
}

