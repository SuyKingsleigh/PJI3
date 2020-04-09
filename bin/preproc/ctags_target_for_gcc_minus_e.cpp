# 1 "/home/suy/Desktop/pj3/projeto/app.ino"
# 2 "/home/suy/Desktop/pj3/projeto/app.ino" 2
# 3 "/home/suy/Desktop/pj3/projeto/app.ino" 2
# 4 "/home/suy/Desktop/pj3/projeto/app.ino" 2
# 5 "/home/suy/Desktop/pj3/projeto/app.ino" 2
# 6 "/home/suy/Desktop/pj3/projeto/app.ino" 2


#define SENSOR_TEMP_PIN 34 /*analog adc1_ch6*/
#define SD_CS 5 /* pino do cartao S*/

#define MAX_ATTEMPTS_LORA 5 /* maximo de tentativas pra enviar uam mensagem pelo LORA*/
#define MAX_ATTEMPTS_BLE 500 /* maximo de tentativas pra enviar uam mensagem pelo BLE*/
#define TOUT 500 /* tempo de timeout ms*/


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
    writeSD(msg->json().c_str(), 5 /* pino do cartao S*/);

    // Se falhar ao enviar a mensagem pelo LORA 
    // tentara enviar pelo bluetooth
    // para isso ele hibernara por 30 segundos 
    // e entao tentara enviar pelo bluetooth N vezes
    if(!send_msg_lora(msg->json().c_str(), 5 /* maximo de tentativas pra enviar uam mensagem pelo LORA*/, 500 /* tempo de timeout ms*/))
        while(!hibernate_and_exec_func(&send_msg_bluetooth, msg->json().c_str(), 30, 500 /* maximo de tentativas pra enviar uam mensagem pelo BLE*/)) {;}


    delete[] msg;
    // depois de enviar pelo lora ou bluetooth, hiberna por meia hora 
    // hibernar depois de tentar enviar pelo bluetooth eh necessario para poupar bateria
    // uma vez que o tentar enviar pelo bluetooth consumira muito mais do que pelo LORA
    hibernate();
}

// nunca chega no loop
void loop(){}
