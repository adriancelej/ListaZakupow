#ifndef lista_h
#define lista_h

#include <string>
#include <iostream>
#include <sstream>
#include "my_exception.h"

class Lista
{
public:
    virtual ~Lista();
    virtual void wypisz()=0;
    virtual void dodaj(Lista&& nowy)=0;
};
#endif // lista_h
