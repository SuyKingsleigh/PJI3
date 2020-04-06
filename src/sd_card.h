//
// Created by suy on 04/04/2020.
//

#ifndef PROJ_SD_CARD_H
#define PROJ_SD_CARD_H


#include "Message.h"
#include <SPI.h>
#include <SD.h>

#define DB "/db.txt"
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
bool write_on_SD(Message &msg);

/**
 * @return true se o tamanho do arquivo eh maior que o limite
 */
bool check_size();


/** 
 * Deleta todos os dados de um arquivo 
*/
void clean_file();

#endif //PROJ_SD_CARD_H
