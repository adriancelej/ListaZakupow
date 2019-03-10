#include "dane.h"

template<typename T>
std::string to_string(const T& obj)
{
    std:: stringstream ss;
    ss<<obj;
    return ss.str();
}

Dane::Dane(std::string wlasciciel)
{
    std::time_t czas = std:: time(nullptr);
    std::tm now=*std:: localtime(&czas);

    if(now.tm_mday<10)
        dzien_="0"+to_string(now.tm_mday);
    else
        dzien_=to_string(now.tm_mday);
    if(now.tm_mon+1<10)
        miesiac_="0"+to_string(now.tm_mon+1);
    else
        miesiac_=to_string(now.tm_mon+1);

    rok_=to_string(1900+now.tm_year);
    if(now.tm_hour<10)
        godziny_="0"+to_string(now.tm_hour);
    else
        godziny_=to_string(now.tm_hour);
    if(now.tm_min<10)
        minuty_="0"+to_string(now.tm_min);
    else
        minuty_=to_string(now.tm_min);

    wlasciciel_=wlasciciel;
}
bool Dane:: is_owner()
{
    return wlasciciel_!="brak";
}

std:: ostream& operator<<(std::ostream& os,Dane* dane)
    {
        os<<"LISTA"<<std::endl;
        os<<dane->dzien_<<" "<<dane->miesiac_<<" "<<dane->rok_<<" "<<dane->godziny_<<" "<<dane->minuty_<<" "<<dane->wlasciciel_<<std::endl;
        return os;
    }

std:: istream& operator>>(std::istream& in,Dane* dane)
{
    std::string bufor;
    getline(in, bufor);
    if(bufor=="LISTA")
    {
       in>>dane->dzien_;
       in>>dane->miesiac_;
       in>>dane->rok_;
       in>>dane->godziny_;
       in>>dane->minuty_;
       in>>dane->wlasciciel_;
       std::cout<<"Wczytano naglowek listy wlasciciela:"<<dane->wlasciciel_<<std::endl;
       return in;
    }
}
