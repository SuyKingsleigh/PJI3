#ifndef BLUETOOTH
#define BLUETOOTH

/**
 *  Tentará enviar uma mensagem, N vezes, pelo BLE. 
 * @return true caso tenha conseguido 
*/
bool send_msg_bluetooth(const char * msg, int max_attempts);

#endif //BLUETOOTH