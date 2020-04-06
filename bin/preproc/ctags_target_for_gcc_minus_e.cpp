# 1 "/home/suy/Desktop/pj3/projeto/app.ino"
# 2 "/home/suy/Desktop/pj3/projeto/app.ino" 2
# 3 "/home/suy/Desktop/pj3/projeto/app.ino" 2
# 4 "/home/suy/Desktop/pj3/projeto/app.ino" 2

#define SENSOR_TEMP_PIN 34 /*analog adc1_ch6*/
#define SD_CS 5 /* pino do cartao SD*/

#define SERIAL_BR 9600 /* baudrate*/

#define MAX_ATEMPTS 5 /* maximo de tentativas pra enviar uam mensagem pelo LORA*/
#define TOUT 500 /* tempo de timeout ms*/


void setup(){
    hibernate();
    time_t now = time(0);
    Message msg = Message(13, localtime(&now));
    writeSD(msg, 5 /* pino do cartao SD*/);
}

void loop(){}
