#include "Message.h"
#include <iostream>


using namespace std; 


bool teste(bool (*f)(const char *, int), const char * msg){
    return f(msg, 4);
}

bool funcaoTosca(const char * a, int b){
    cout << a << endl;
    return b > 1;
}

int main(void){
    time_t t = time(0);
    teste(&funcaoTosca, Message(123,localtime(&t)).json().c_str());
}