#ifndef POWER_SAVING
#define POWER_SAVING

#define uS_TO_MIN 60000000 // converte uS pra minutos
#define uS_TO_SEC 1000000 // converte uS pra segundos
#define TIME_TO_SLEEP 30   // dorme por 30 minutos

#include "esp_sleep.h"
#include "esp_wifi.h" // wifi_disable
#include "esp_bt.h" // esp_bt_controller_disable
#include "esp_bt_main.h" // esp_bluedroid_disable


/** 
 *  Desativa: esp32 core, ULP, WiFi, Bluetooth, Radio, Periferico 
 *  Ativo: RTC 
 *  Consumo: 2.5uA a 5uA
 *  Devera ser ativada apos enviar (com sucesso) a mensagem pelo LORA
 *  Fazendo assim que o dispositivo durma por pelo menos meia hora
 */
void hibernate();

void hibernate(int duracao);


#endif //POWER_SAVING