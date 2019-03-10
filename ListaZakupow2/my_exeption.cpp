#include "my_exception.h"

NO_ELEMENT::NO_ELEMENT(){}

NO_ELEMENT::~NO_ELEMENT(){}

const char* NO_ELEMENT::what()const noexcept
    {
        return "Brak elementu o podanej nazwie!!!";
    }

BAD_FILE::BAD_FILE(){}

BAD_FILE::~BAD_FILE(){}

const void BAD_FILE::what()const noexcept
{
    std::cout<<"Plik z listami uszkodzony!!!"<<std::endl;
}

WRONG_DATA::WRONG_DATA(){}

WRONG_DATA::~WRONG_DATA(){}

const void WRONG_DATA::what()const noexcept
{
    std::cout<<"Podano niewlasciwe dane!!!"<<std::endl;
}
