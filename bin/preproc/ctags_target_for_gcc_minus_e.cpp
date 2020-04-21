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

/**

 * Toda vez que o hibernate é invocado, ele desligará tudo 

 * Exceto o RTC 

 * Então quando acorda, ele volta pra cá 

 * Ou seja, se falhar ao enviar pelo Lora, ele vai medir a temperatura novamente 

 * Mas isso tem um custo de energia menor do que mantê-lo ativo durante X minutos

*/
# 27 "/home/suy/Desktop/pj3/projeto/app.ino"
void setup(){
    // mede a temperatura e escreve no SD
    time_t t = time(0);
    Message * msg = new Message(get_temp(), localtime(&t));
    writeSD(msg->json().c_str(), 5 /* pino do cartao S*/);

    // tenta enviar a mensagem pelo LORA N vezes 
    // caso consiga enviar, dormira por meia hora
    if(!send_msg_lora(msg->json().c_str(), 5 /* maximo de tentativas pra enviar uam mensagem pelo LORA*/, 500 /* tempo de timeout ms*/)){
        // caso falhe ao enviar pelo Lora 
        // tentara enviar pelo BLE M vezes 
        // se falhar pelo BLE, dormira por 30s e tentara novamente 
        if(!send_msg_bluetooth(msg->json().c_str(), 500 /* maximo de tentativas pra enviar uam mensagem pelo BLE*/))
            hibernate(60000000 /* converte uS pra minutos*/ * 0.5);
    }

    hibernate();
}


void loop(){}
