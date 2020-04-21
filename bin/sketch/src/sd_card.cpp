//
// Created by suy on 04/04/2020.
//

#include "sd_card.h"


// se falhar ao iniciar o cartao SD retorna falso 
bool initializeSD(uint8_t sd){
   return SD.begin(sd);
}

bool write_on_SD(const char * msg) {
    File file = SD.open(DB, FILE_WRITE);
    if(file){
        file.println(msg); 
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


bool writeSD(const char * msg,  int SD_CS) {
    if(initializeSD(SD_CS)){
        if(!check_size()) return write_on_SD(msg);
        else{
            clean_file();
            return write_on_SD(msg);
        }
    }
}


void write_buffer(int val, uint8_t sd){
    if(initializeSD(sd)){
        File file = SD.open(BUFFER, FILE_WRITE);
        file.println(val);
        file.close();
    }
}

int read_buffer(uint8_t sd){
    int b = -1; 
    if(initializeSD(sd)){
        File file = SD.open(BUFFER);
        b = file.read();
        file.close();
    }
    return b;
}

void delete_buffer(uint8_t sd){
    if(initializeSD(sd)) SD.remove(BUFFER);
}