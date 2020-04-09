#ifndef LORA
#define LORA 

/**
 * Envia uma mensagem pelo LORA
 * @param msg dados a serem enviados (Message(bla,bla).json().c_str())
 * @param num_tentativas quantidade de tentivas antes de retornar false 
 * @param tout timeout antes de tentar outra vez
 * @return true caso tenha enviado com sucesso a mensagem 
 * */
bool send_msg_lora(const char * msg, int num_tentativas, int tout);



#endif //LORA