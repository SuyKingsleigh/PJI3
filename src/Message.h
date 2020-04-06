#ifndef APP_ESP32_Message
#define APP_ESP32_Message 


// #include <string>
#include <sstream>

class Message{
    private:
        int temp; 

        // nao ha a necessidade(nem DEVE) de destrutor pois eh um endereco estatico
        struct tm *date; 

        std::string date_to_string();
    public:
        Message(int temp, struct tm *date);
        /**
         * Converte a mensagem para o estilo JSON
         * @return {"date" : "hora:min:seg dia:mes:ano", "temp" : temp}
         */
        std::string json();

};

#endif