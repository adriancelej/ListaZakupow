#include "produkt.h"

Produkt::Produkt(std::string nazwa, float cena, float ilosc, float stan):nazwa_(nazwa),cena_(cena),ilosc_(ilosc),stan_(stan){}

Produkt::Produkt():nazwa_("brak"),cena_(0),ilosc_(0),stan_(0){}

void Produkt::dodaj(Lista&& nowy){}

void Produkt:: wypisz()
{
    unsigned int size_nazw=59;

    std::cout.setf(std::ios::showpoint);
    std::cout<<std::fixed;
    std::cout<<std::setprecision(2);
    std::cout<<"| "<<nazwa_;for(size_t i=0;i<size_nazw-nazwa_.size()-1;++i)std::cout<<" ";std::cout<<"|";std::cout.width(9);std::cout<<cena_<<"|";std::cout.width(9);std::cout<<ilosc_<<"|";std::cout.width(9);std::cout<<stan_<<"|";std::cout.width(9);std::cout<<((ilosc_-stan_)*cena_)<<"|"<<std::endl;
    std::cout<<" ---------------------------------------------------------------------------------------------------\n";
}

std::ostream& operator<<(std::ostream& os,Produkt& produkt)
{
    os<<"START"<<std::endl;
    os<<produkt.nazwa_<<std::endl;
    os<<produkt.cena_<<std::endl;
    os<<produkt.ilosc_<<std::endl;
    os<<produkt.stan_<<std::endl;
    os<<"END"<<std::endl;
    return os;
}

std::istream& operator>>(std::istream& in,Produkt& produkt)
{
    std::string bufor;
    std::stringstream css;
    while(bufor!="START" && bufor!="ENDLIST")
    {
        getline(in,bufor);
        if(bufor=="ENDLIST")
        return in;
    }
    getline(in,produkt.nazwa_);
    getline(in,bufor);
    css<<bufor;
    css>>produkt.cena_;
    css.str("");
    css.clear();
    getline(in,bufor);
    css<<bufor;
    css>>produkt.ilosc_;
    css.str("");
    css.clear();
    getline(in,bufor);
    css<<bufor;
    css>>produkt.stan_;
    getline(in,bufor);
    if(bufor!="END")
    {
        throw BAD_FILE();
    }
    return in;
}

void Produkt:: zmien_cene(float cena)
{
    if(cena>=0)
        cena_=cena;
    else
        throw WRONG_DATA();
}

void Produkt::zmien_ilosc(float ilosc)
{
   if(ilosc>=0)
        ilosc_=ilosc;
    else
        throw WRONG_DATA();
}

void Produkt::zmien_stan(float stan)
{
    if(stan>=0&&stan<=ilosc_)
        stan_=stan;
    else
        throw WRONG_DATA();
}

std::string Produkt::getname()const
{
    return nazwa_;
}
