#include "produkty.h"

Produkty::Produkty(Produkt&& nowy,std::string wlasciciel):Dane(wlasciciel)
{
    produkty_.push_back(nowy);
}

Produkty::Produkty():Dane("brak"){}

void Produkty::dodaj(Lista&& nowy)
{
    produkty_.push_back(static_cast<Produkt&&>(nowy));
}

void Produkty::wypisz()
{
    using namespace std;

    string line=" ___________________________________________________________________________________________________\n";
    string line2=" ---------------------------------------------------------------------------------------------------\n";
    string title="| Lista Zakupow     Wlasciciel: "+wlasciciel_+"      Data utworzenia: "+godziny_+":"+minuty_+"  "+dzien_+"."+miesiac_+"."+rok_+"r. ";
    string title2="| Nazwa produktu:                                           | Cena:   | Ilosc:  | Stan:   | Wartosc:|\n";

    cout<<line<<title;
    for(size_t i=0;i<line.size()-title.size()-1;++i)
        cout<<" ";
    cout<<"|\n"<<line2<<title2<<line2;//koniec naglowka tabeli

   for(size_t i=0;i<produkty_.size();++i)
    produkty_.at(i).wypisz();
}

std:: ostream& operator<<(std::ostream& os,Produkty* produkty)
{
    os<<static_cast<Dane*>(produkty);
    for(size_t i=0;i<produkty->produkty_.size()-1;++i)
        {
            os<<produkty->produkty_.at(i);
            os<<""<<std::endl;
        }
    os<<produkty->produkty_.at(produkty->produkty_.size()-1);
    os<<"ENDLIST"<<std::endl;
    return os;
}

std:: istream& operator>>(std::istream& in,Produkty* produkty)
{
    in>>static_cast<Dane*>(produkty);
    std::string bufor;
    while(!in.eof()&&bufor!="ENDLIST")
        {
            Produkt nowy=*(new Produkt());
            in>>nowy;
            produkty->produkty_.push_back(nowy);
            getline(in,bufor);
        }
    return in;

}

Produkt& Produkty:: wyszukaj(const std::string& nazwa)
{
    for(size_t i=0;i<produkty_.size();++i)
    {
        if(produkty_.at(i).getname()==nazwa)
            return produkty_.at(i);
    }
    throw NO_ELEMENT();
}

void Produkty:: delete_p(const std::string nazwa)
{
    std::string brak="Brak elementu!!!\n";
    bool tn_=true;
    std::vector<Produkt>::const_iterator it=produkty_.begin();
    for(size_t i=0;i<produkty_.size();++i)
    {
        if(produkty_.at(i).getname()==nazwa)
            {
                produkty_.erase(it);
                std::cout<<"Usunieto produkt:"<<nazwa<<std::endl;
                tn_=false;
            }
        ++it;
    }
    if(tn_)
        std::cout<<brak;
}
