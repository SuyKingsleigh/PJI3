#include "src/Message.cpp"
#include <iostream>
using namespace std; 

void teste(void (*a)()){
    a();
}

void funcao(){
    cout << "aheoo" << endl;
}

int main(void){
    time_t t = time(0);
    teste(&funcao);
}