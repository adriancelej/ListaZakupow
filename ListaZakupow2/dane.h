#ifndef dane_h
#define dane_h

#include <ctime>
#include "lista.h"

class Dane:public Lista
{
protected:
std::string dzien_;
std::string miesiac_;
std::string rok_;
std::string godziny_;
std::string minuty_;
std::string wlasciciel_;

public:
    Dane(std::string wlasciciel);
    bool is_owner();
    friend std:: ostream& operator<<(std::ostream& os, Dane* dane);
    friend std:: istream& operator>>(std::istream& in, Dane* dane);
};
#endif // dane_h
