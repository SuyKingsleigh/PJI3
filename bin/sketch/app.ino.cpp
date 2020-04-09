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
#line 21 "/home/suy/Desktop/pj3/projeto/app.ino"
void setup();
#line 46 "/home/suy/Desktop/pj3/projeto/app.ino"
void loop();
#line 16 "/home/suy/Desktop/pj3/projeto/app.ino"
int get_temp(){
    return 12;
}

// Message *msg = nullptr;
void setup(){
    // mede a temperatura e escreve no SD
    time_t t = time(0);

    // usar o ponteiro aqui reduz o consumo de memória 
    // como o hibernate apaga a memoria, entao nao precisa de delete (eu acho)
    Message * msg = new Message(get_temp(), localtime(&t));
    writeSD(msg->json().c_str(), SD_CS);

    // Se falhar ao enviar a mensagem pelo LORA 
    // tentara enviar pelo bluetooth
    // para isso ele hibernara por 30 segundos 
    // e entao tentara enviar pelo bluetooth N vezes
    if(!send_msg_lora(msg->json().c_str(), MAX_ATTEMPTS_LORA, TOUT))
        while(!hibernate_and_exec_func(&send_msg_bluetooth, msg->json().c_str(), 30, MAX_ATTEMPTS_BLE)) {;}


    delete[] msg;
    // depois de enviar pelo lora ou bluetooth, hiberna por meia hora 
    // hibernar depois de tentar enviar pelo bluetooth eh necessario para poupar bateria
    // uma vez que o tentar enviar pelo bluetooth consumira muito mais do que pelo LORA
    hibernate();
}   

// nunca chega no loop
void loop(){}

