#include <Arduino.h>
#line 1 "/home/suy/Desktop/pj3/projeto/app.ino"
#include "src/Message.h"
#include "src/sd_card.h"
#include "src/power_saving.h"
#include "src/lora.h"
#include "src/bluetooth.h"


#define SENSOR_TEMP_PIN 34 //analog adc1_ch6
#define SD_CS 5 // pino do cartao S

#define MAX_ATTEMPTS_LORA 5 // maximo de tentativas pra enviar uam mensagem pelo LORA
#define MAX_ATTEMPTS_BLE 500 // maximo de tentativas pra enviar uam mensagem pelo BLE
#define TOUT 500 // tempo de timeout ms


#line 16 "/home/suy/Desktop/pj3/projeto/app.ino"
int get_temp();
#line 27 "/home/suy/Desktop/pj3/projeto/app.ino"
void setup();
#line 47 "/home/suy/Desktop/pj3/projeto/app.ino"
void loop();
#line 16 "/home/suy/Desktop/pj3/projeto/app.ino"
int get_temp(){
    return 12;
}

/**
 * Toda vez que o hibernate é invocado, ele desligará tudo 
 * Exceto o RTC 
 * Então quando acorda, ele volta pra cá 
 * Ou seja, se falhar ao enviar pelo Lora, ele vai medir a temperatura novamente 
 * Mas isso tem um custo de energia menor do que mantê-lo ativo durante X minutos
*/
void setup(){
    // mede a temperatura e escreve no SD
    time_t t = time(0);
    Message * msg = new Message(get_temp(), localtime(&t));
    writeSD(msg->json().c_str(), SD_CS);

    // tenta enviar a mensagem pelo LORA N vezes 
    // caso consiga enviar, dormira por meia hora
    if(!send_msg_lora(msg->json().c_str(), MAX_ATTEMPTS_LORA, TOUT)){
        // caso falhe ao enviar pelo Lora 
        // tentara enviar pelo BLE M vezes 
        // se falhar pelo BLE, dormira por 30s e tentara novamente 
        if(!send_msg_bluetooth(msg->json().c_str(), MAX_ATTEMPTS_BLE))
            hibernate(uS_TO_MIN * 0.5);
    }

    hibernate();
}   


void loop(){}
