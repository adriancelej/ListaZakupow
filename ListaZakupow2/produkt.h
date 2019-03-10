#ifndef produkt_h
#define produkt_h

#include "lista.h"
#include <iomanip>

class Produkt:public Lista
{
private:
    std::string nazwa_;
    float cena_;
    float ilosc_;
    float stan_;
public:
    Produkt(std::string nazwa,float cena, float ilosc, float stan);
    Produkt();
    virtual void wypisz() override;
    virtual void dodaj(Lista&& nowy) override;
    friend std::ostream& operator<<(std::ostream& os,Produkt &produkt);
    friend std::istream& operator>>(std::istream& in,Produkt &produkt);
    void zmien_cene(float cena);
    void zmien_ilosc(float ilosc);
    void zmien_stan(float stan);
    std:: string getname()const;
};
#endif // produkt_h
