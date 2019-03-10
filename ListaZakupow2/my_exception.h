#ifndef my_exception_h
#define my_exception_h

#include <exception>
#include <iostream>

class NO_ELEMENT:std::exception
{
public:
    NO_ELEMENT();
    const char* what()const noexcept;
    ~NO_ELEMENT();
};

class BAD_FILE
{
public:
    BAD_FILE();
    const void what()const noexcept;
    ~BAD_FILE();
};

class WRONG_DATA
{
public:
    WRONG_DATA();
    const void what()const noexcept;
    ~WRONG_DATA();
};


#endif // my_exception
