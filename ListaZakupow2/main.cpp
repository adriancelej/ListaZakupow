#include <iostream>
#include "produkt.h"
#include "produkty.h"
#include <fstream>
#include "my_exception.h"

using namespace std;

void zapisz(Lista* ptr)noexcept
{
    fstream plik;

    try
    {
        plik.open("lista.txt", ios::app|ios::out);
        plik.exceptions(plik.failbit);
        cout<<"Udalo sie otworzyc plik z listami\n";
        plik<<static_cast<Produkty*>(ptr);
        plik.close();
        cout<<"Zapisano liste w pliku!!!\n";
    }
    catch(ios_base::failure &e)
    {
        cout<<e.what()<<endl;
    }
    catch(...)
    {
        cout<<"Niezdefiniowany blad"<<endl;
    }
}

void wczytaj(vector<Lista*>& listy)noexcept
{
    fstream plik;

    try
    {
        plik.open("lista.txt",ios::in);
        plik.exceptions(plik.failbit);
        cout<<"Udalo sie otworzyc plik z listami\n";
            while(!plik.eof())
            {
                Lista* ptr=new Produkty();
                plik>>static_cast<Produkty*>(ptr);
                if(static_cast<Dane*>(ptr)->is_owner())
                listy.push_back(ptr);
            }
        plik.close();
        cout<<"Zakonczono wczytywanie listy\n";
    }
    catch(ios_base::failure &e)
    {
        cout<<e.what()<<endl;
    }
    catch(BAD_FILE &ex)
    {
        ex.what();
    }
    catch(...)
    {
        cout<<"Niezdefiniowany blad..."<<endl;
    }
}

void zmien_c(Lista* ptr,string nazwa,float cena)noexcept
{
    try
    {
        (static_cast<Produkty*>(ptr)->wyszukaj(nazwa)).zmien_cene(cena);
    }
    catch(NO_ELEMENT &ex)
    {
        ex.what();
    }
    catch(WRONG_DATA &ex)
    {
        ex.what();
    }
    catch(...)
    {
        cout<<"Niezdefiniowany blad..."<<endl;
    }
}

void zmien_i(Lista* ptr,string nazwa,float ilosc)noexcept
{
    try
    {
        (static_cast<Produkty*>(ptr)->wyszukaj(nazwa)).zmien_ilosc(ilosc);
    }
    catch(NO_ELEMENT &ex)
    {
        ex.what();
    }
    catch(WRONG_DATA &ex)
    {
        ex.what();
    }
    catch(...)
    {
        cout<<"Niezdefiniowany blad..."<<endl;
    }
}

void zmien_s(Lista* ptr,string nazwa,float stan)noexcept
{
    try
    {
        (static_cast<Produkty*>(ptr)->wyszukaj(nazwa)).zmien_stan(stan);
    }
    catch(NO_ELEMENT &ex)
    {
        ex.what();
    }
    catch(WRONG_DATA &ex)
    {
        ex.what();
    }
    catch(...)
    {
        cout<<"Niezdefiniowany blad..."<<endl;
    }
}

bool znajdz(Lista* ptr,string nazwa)noexcept
{
    try
    {
        static_cast<Produkty*>(ptr)->wyszukaj(nazwa);
    }
    catch(NO_ELEMENT &ex)
    {
        cout<<ex.what()<<endl;
        return false;
    }
    catch(...)
    {
        cout<<"Niezdefiniowany blad..."<<endl;
    }
    return true;
}

void dodajprodukt(Lista* ptr,string nazwa,float cena,float ilosc, float stan)noexcept
{
    try
    {
        static_cast<Produkty*>(ptr)->wyszukaj(nazwa);
        cout<<"Produkt o podanej nazwie juz istnieje. Zmodifikuj go lub dodaj produkt o innej nazwie!!!\n";
    }
    catch(NO_ELEMENT &w)
    {
        ptr->dodaj(Produkt(nazwa,cena,ilosc,stan));
        cout<<"Dodano produkt:"<<nazwa<<endl;
    }

}

Lista* new_list(string nazwa,float cena,float ilosc,float stan, string wlasciciel)noexcept
{
    try
    {
        return new Produkty(Produkt(nazwa,cena,ilosc,stan),wlasciciel);
    }
    catch(bad_alloc &ex)
    {
        cout<<ex.what();
    }
}

void show_list(Lista* ptr)noexcept
{
    ptr->wypisz();
}

void usunprodukt(Lista* ptr,string nazwa)noexcept
{
        static_cast<Produkty*>(ptr)->delete_p(nazwa);
}

void check_data(float &a,float &b)noexcept
{
    while(a>b)
    {
        cout<<"Stan nie moze byc wiekszy od ilosci!\nPodaj odpowiedni stan:"<<endl;
        cin>>a;
    }
}

int main()
{
    vector<Lista*> listy;
    unsigned int sw1=0,sw2=0;
    string bufor;

    cout<<"Witaj!!!Co chcesz zrobic?"<<endl;

    while(sw1!=4)
    {
        sw1=0;
        sw2=0;
        cout<<"[1] - Utworz liste"<<endl;
        cout<<"[2] - Wczytaj listy"<<endl;
        cout<<"[3] - Wypisz wczytane listy"<<endl;
        cout<<"[4] - Zakoncz"<<endl;

        cin>>sw1;getline(cin,bufor);

        switch(sw1)
        {
            case 1:
                {
                    string buf1,buf2;
                    float c,i,s;

                    cout<<"Podaj imie wlasciciela listy:"<<endl;
                    cin>>buf1;getline(cin,bufor);
                    cout<<"Podaj nazwe produktu:"<<endl;
                    cin>>buf2;getline(cin,bufor);
                    cout<<"Podaj ile chcesz zakupic:"<<endl;
                    cin>>i;getline(cin,bufor);
                    cout<<"Podaj ile juz zakupiono:"<<endl;
                    cin>>s;getline(cin,bufor);
                    cout<<"Podaj cene(moze byc orientacyjna):"<<endl;
                    cin>>c;getline(cin,bufor);
                    check_data(s,i);

                    Lista* nowa=new_list(buf2,c,i,s,buf1);
                    listy.push_back(nowa);

                    while(sw2!=5)
                    {
                        sw2=0;
                        cout<<"[1] - Dodaj produkt do listy\n";
                        cout<<"[2] - Usun produkt z listy\n";
                        cout<<"[3] - Wyswietl liste\n";
                        cout<<"[4] - Modyfikuj produkt\n";
                        cout<<"[5] - Zakoncz dodawanie produktow(wyswietli utworzona liste)\n";
                        cin>>sw2;getline(cin,bufor);

                        switch(sw2)
                        {
                        case 1:
                            {
                                cout<<"Podaj nazwe produktu:"<<endl;
                                cin>>buf1;getline(cin,bufor);
                                cout<<"Podaj cene(moze byc orientacyjna):"<<endl;
                                cin>>c;getline(cin,bufor);
                                cout<<"Podaj ile chcesz zakupic:"<<endl;
                                cin>>i;getline(cin,bufor);
                                cout<<"Podaj ile juz zakupiono:"<<endl;
                                cin>>s;getline(cin,bufor);
                                check_data(s,i);
                                dodajprodukt(nowa,buf1,c,i,s);
                                break;
                            }
                        case 2:
                            {
                                cout<<"Podaj nazwe produktu do usuniecia z listy:"<<endl;
                                cin>>buf1;getline(cin,bufor);
                                usunprodukt(nowa,buf1);
                                break;
                            }
                        case 3:
                            {
                                show_list(nowa);
                                break;
                            }
                        case 4:
                            {
                                char sw3='a';
                                cout<<"Podaj nazwe produktu do modyfikacji:"<<endl;
                                cin>>buf1;getline(cin,bufor);
                                if(znajdz(nowa,buf1))
                                {
                                    while(sw3!='k')
                                    {
                                        cout<<"Co chcesz zmienic?"<<endl;
                                        cout<<"[c] - cene"<<endl;
                                        cout<<"[i] - ilosc"<<endl;
                                        cout<<"[s] - stan"<<endl;
                                        cout<<"[k] - Zakoncz modyfikacje produktu"<<endl;
                                        cin>>sw3;getline(cin,bufor);
                                        if(sw3=='c')
                                        {
                                            cout<<"Podaj nowa cene:"<<endl;
                                            cin>>c;getline(cin,bufor);
                                            zmien_c(nowa,buf1,c);
                                        }
                                        if(sw3=='i')
                                        {
                                            cout<<"Podaj nowa ilosc:"<<endl;
                                            cin>>i;getline(cin,bufor);
                                            zmien_i(nowa,buf1,i);
                                        }
                                        if(sw3=='s')
                                        {
                                            cout<<"Podaj nowy stan:"<<endl;
                                            cin>>s;getline(cin,bufor);
                                            zmien_s(nowa,buf1,s);
                                        }
                                        if(sw3!='c'&&sw3!='i'&&sw3!='s'&&sw3!='k')
                                        {
                                            cout<<"Nie zdefiniowano zachowania dla podanej przez urzytkownika opcji!!!"<<endl;
                                        }
                                    }

                                }
                                break;
                            }
                        case 5:
                            {
                                char sw5='A';
                                show_list(nowa);
                                while(sw5!='Y'&&sw5!='N')
                                {
                                    cout<<"Zapisac liste w pliku? Umozliwi to jej pozniejszy odczyt"<<endl;
                                    cout<<"Y - TAK  N - NIE"<<endl;
                                    cin>>sw5;getline(cin,bufor);
                                    if(sw5=='Y')
                                        zapisz(nowa);
                                    if(sw5=='N'){}
                                    if(sw5!='N'&&sw5!='Y')
                                        cout<<"Niezdefiniowano zachowania dla:"<<sw5<<endl;
                                }
                                    break;
                            }
                        }
                    }
                    break;
                }
            case 2:
                {
                    wczytaj(listy);
                    break;
                }
            case 3:
                {
                    if(listy.empty())
                    {
                        cout<<"Nie wczytano list!!!"<<endl;
                    }
                    else
                    {
                        vector<Lista*> ::const_iterator it = listy.begin();
                        while(it!=listy.end())
                        {
                            show_list(*it);
                            ++it;
                        }
                    }
                   break;
                }
            case 4:
                {
                    sw1=4;
                    break;
                }
        }
    }
        return 0;
    }
