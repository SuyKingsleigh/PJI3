#ifndef POWER_SAVING
#define POWER_SAVING

#define uS_TO_MIN 60000000 // converte uS pra minutos
#define uS_TO_SEC 1000000 // converte uS pra minutos
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
void _hibernate(int duracao);


/** 
 * Hiberna e quando acorda executa uma funcao
 * Deve ser usado quando falha ao enviar pelo LORA 
 * ficara dormindo por N segundos e entao tentara enviar pelo BLE 
 * consiga enviar pelo BLE retorna True e entao devera ser chamado o Hibernate()
 * a ideia e manter isso dentro de um while
 * while(hibernate_and_exec_func(send_BLE), N);
 * @param (*f) funcao a ser executada 
 * @param duracao duracao EM segundos da hibernacao
*/
bool hibernate_and_exec_func(bool (*f)(const char *), const char * msg, int duracao);



#endif //POWER_SAVING