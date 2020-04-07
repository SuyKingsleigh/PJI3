#ifndef BLUETOOTH
#define BLUETOOTH

// esse metodo sera usado junto com o hibernate_and_exec_func 
// e talvez ele apagara os dados da memoria 
// portanto a msgm sera um NULL ou nullptr 
// mas felizmente sera a ultima mensagem do arquivo TXT no SD 
bool send_msg_bluetooth(const char * msg, int max_attempts);

#endif //BLUETOOTH