#include <Arduino.h>
#line 1 "/home/suy/Desktop/pj3/projeto/app.ino"
#include "src/Message.h"
#include "src/sd_card.h"
#include "src/power_saving.h"

#define SENSOR_TEMP_PIN 34 //analog adc1_ch6
#define SD_CS 5 // pino do cartao SD

#define SERIAL_BR 9600 // baudrate

#define MAX_ATEMPTS 5 // maximo de tentativas pra enviar uam mensagem pelo LORA
#define TOUT 500 // tempo de timeout ms


#line 14 "/home/suy/Desktop/pj3/projeto/app.ino"
void setup();
#line 21 "/home/suy/Desktop/pj3/projeto/app.ino"
void loop();
#line 14 "/home/suy/Desktop/pj3/projeto/app.ino"
void setup(){
    hibernate();
    time_t now = time(0);
    Message msg = Message(13, localtime(&now));
    writeSD(msg, SD_CS);
}

void loop(){}

