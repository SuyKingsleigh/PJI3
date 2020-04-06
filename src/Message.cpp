#include "Message.h"

// o metodo to_string so existe no c++11
// e pelo visto isso ta limitado ao 98
template <typename T>
std::string to_string(T val){
    std::stringstream stream;
    stream << val;
    return stream.str();
}


Message::Message(int temp, struct tm *date){
    this->temp = temp;
    this->date = date;
}

std::string Message::json(){
    return R"({"date" : ")" + this->date_to_string() + R"(", "temp" : )" + to_string(this->temp) + "}";
}

std::string Message::date_to_string(){
        return to_string(this->date->tm_hour)+ ":" + to_string(this->date->tm_min) + ":" +
               to_string(this->date->tm_sec) + " " + to_string(this->date->tm_mday) + "/" +
               to_string(this->date->tm_mon) + "/" + to_string(this->date->tm_year);
}