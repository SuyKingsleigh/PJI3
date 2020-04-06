# 1 "/home/suy/Desktop/pj3/app-esp32/app.ino"
# 2 "/home/suy/Desktop/pj3/app-esp32/app.ino" 2
# 3 "/home/suy/Desktop/pj3/app-esp32/app.ino" 2


#define SENSOR_TEMP_PIN 34 /*analog adc1_ch6*/
#define SD_CS 5 /* pino do cartao SD*/

#define SERIAL_BR 9600 /* baudrate*/
#define uS_TO_MIN 60000000 /* converte uS pra minutos*/
#define TIME_TO_SLEEP 30 /* dorme por 30 minutos*/

#define MAX_ATEMPTS 5 /* maximo de tentativas pra enviar uam mensagem pelo LORA*/
#define TOUT 500 /* tempo de timeout ms*/

// funcao apenas para dormir
void snooze(){
    //  http://esp-idf.readthedocs.io/en/latest/api-reference/system/deep_sleep.html
    esp_sleep_enable_timer_wakeup(30 /* dorme por 30 minutos*/ * 60000000 /* converte uS pra minutos*/);
    // definir os perifericos a ficarem ligados
    // Devera dormir por 30 minutos, coletar dados, so acordara caso de o timer 
    // ou tenha um dispostivo com BLE por perto
    //esp_deep_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
    esp_deep_sleep_start();
}

// escreve a mensagem que foi enviada no cartao SD
void writeSD(Message &msg) {
    // copia msgs pro cartao SD 
    // caso o tamanho do arquivo exceda 2gb ele apagara os dados do cartao 
    if(initializeSD(5 /* pino do cartao SD*/)){
        if(!check_size()) write_on_SD(msg);
        else{
            clean_file();
            write_on_SD(msg);
        }
    }
}

// envia uma mensagem pelo LORA
void sendMsgLora(String &msg) {
    // enviar mensagem 
    // copiar pra SD 
    // esperar ack 
    // se n receber resposta ate o tout, envia novamente
    // tenta N veze ate desistir
}

// envia uma mensagem pelo BLE
void sendMsgBLE() {
    // caso encontre um dispotivo por perto
    // envia uma copia do banco de dados pro dispositivo 
    // devera enviar do mais recente ao mais antigo. 
}


// devido ao snooze, o codigo inteiro vai rolar no setup
void setup(){
    Serial.begin(9600 /* baudrate*/);
    delay(1000);
}

void loop(){}
