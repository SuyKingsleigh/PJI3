#include "src/Message.h"
#include "src/sd_card.h"
#include "src/power_saving.h"
#include "src/lora.h"
#include "src/bluetooth.h"


#define SENSOR_TEMP_PIN 34 //analog adc1_ch6
#define SD_CS 5 // pino do cartao S

#define MAX_ATTEMPTS 5 // maximo de tentativas pra enviar uam mensagem pelo LORA
#define TOUT 500 // tempo de timeout ms


int get_temp(){
    return 12;
}

void setup(){
    // mede a temperatura e escreve no SD
    time_t t = time(0);
    const char * msg = Message(get_temp(), localtime(&t)).json().c_str();
    writeSD(msg, SD_CS);

    // Se falhar ao enviar a mensagem pelo LORA 
    // tentara enviar pelo bluetooth
    // para isso ele hibernara por 30 segundos 
    // e entao tentara enviar pelo bluetooth N vezes
    if(!send_msg_lora(msg, MAX_ATTEMPTS, TOUT))
        while(!hibernate_and_exec_func(&send_msg_bluetooth, msg, 30, MAX_ATTEMPTS)) {;}

    // depois de enviar pelo lora ou bluetooth, hiberna por meia hora 
    hibernate();
}   

void loop(){}
