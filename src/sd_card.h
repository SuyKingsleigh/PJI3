//
// Created by suy on 04/04/2020.
//

#ifndef PROJ_SD_CARD_H
#define PROJ_SD_CARD_H


#include <SPI.h>
#include <SD.h>

#define DB "/db.txt"
#define BUFFER "/buffer.txt"
#define MAX_FILE_SIZE 2147483648 //2GB 

/**
 * Inicializa o cartao SD
 * @param sd Pino onde esta ligado
 * @return True caso tenha iniciado o cartao Sd 
 */
bool initializeSD(uint8_t sd);

/**
 * Escreve uma mensagem no cartao SD
 * @param msg mensagem que fora enviada
 * @return true se escreveu 
 */
bool write_on_SD(const char * msg);

/**
 * @return true se o tamanho do arquivo eh maior que o limite
 */
bool check_size();


/** 
 * Deleta todos os dados de um arquivo 
*/
void clean_file();

/**
 * Funcao que deve de fato ser usada para escrever num cartao SD 
 * @param msg : Message 
 * @param SD_CS : int porta do cartao SD
 * @return se conseguiu escrever ou nao 
 */
bool writeSD(const char * msg, int SD_CS);


void write_buffer(int val, uint8_t sd);
int read_buffer(uint8_t sd);



#endif //PROJ_SD_CARD_H
