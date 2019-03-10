#ifndef produkty_h
#define produkty_h

#include "dane.h"
#include <vector>
#include "produkt.h"

class Produkty:public Dane
{
private:
    std::vector<Produkt> produkty_;
public:
    Produkty(Produkt&& nowy,std::string wlasciciel);
    Produkty();
    virtual void dodaj(Lista&& nowy) override;
    virtual void wypisz() override;
    friend std::ostream& operator<<(std::ostream& os,Produkty* produkty);
    friend std::istream& operator>>(std::istream& in,Produkty* produkty);
    Produkt& wyszukaj(const std::string& nazwa);
    void delete_p(const std::string nazwa);
};
#endif // produkty_h
