//
// Created by suy on 05/04/2020.
//

#include "power_saving.h"

void hibernate(int duracao){
    esp_wifi_stop();
    esp_bluedroid_disable();
    esp_bt_controller_disable();
    esp_deep_sleep(duracao);
}


void hibernate(){
    hibernate(uS_TO_MIN * TIME_TO_SLEEP);
}