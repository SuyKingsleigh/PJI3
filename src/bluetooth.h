#ifndef BLUETOOTH
#define BLUETOOTH

// esse metodo sera usado junto com o hibernate_and_exec_func 
// e talvez ele apagara os dados da memoria 
// portanto a msgm sera um NULL ou nullptr 
// mas felizmente sera a ultima mensagem do arquivo TXT no SD 
// o numero de tentativas devera ser armazenado no SD e decrementado cada vez que falhar ao enviar
// esse numero devera ser calculado de forma que ele fique tentando enviar por meia hora 
// quando o numero de tentativa chegar em 0 ele devera retornar TRUE 
// pois assim hibernara por mais meia hora e seguira o fluxo do programa 
bool send_msg_bluetooth(const char * msg, int max_attempts);

#endif //BLUETOOTH