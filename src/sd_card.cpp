//
// Created by suy on 04/04/2020.
//

#include "sd_card.h"


// se falhar ao iniciar o cartao SD retorna falso 
bool initializeSD(uint8_t sd){
   return SD.begin(sd);
}

bool write_on_SD(Message &msg) {
    File file = SD.open(DB, FILE_WRITE);
    if(file){
        file.println(msg.json().c_str()); // converte a msg pra const char *
        file.close();
        return true;
    } return false; 
}

bool check_size(){
    return SD.open(DB).size() >= MAX_FILE_SIZE;
}


void clean_file(){
    SD.remove(DB);
}


bool writeSD(Message &msg, int SD_CS) {
    if(initializeSD(SD_CS)){
        if(!check_size()) return write_on_SD(msg);
        else{
            clean_file();
            return write_on_SD(msg);
        }
    }
}