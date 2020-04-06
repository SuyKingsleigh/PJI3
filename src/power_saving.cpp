//
// Created by suy on 05/04/2020.
//

#include "power_saving.h"

void _hibernate(int duracao){
    esp_wifi_stop();
    esp_bluedroid_disable();
    esp_bt_controller_disable();
    esp_deep_sleep(duracao);
}

void hibernate(){
    _hibernate(uS_TO_MIN * TIME_TO_SLEEP);
}

bool hibernate_and_exec_func(bool (*f)(const char *), const char * msg, int duracao){
    _hibernate(duracao * uS_TO_SEC); // dorme por n segundos
    return f(msg);
}