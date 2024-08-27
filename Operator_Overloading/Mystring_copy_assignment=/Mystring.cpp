#include"Mystring.h"
#include<iostream>
#include<cstring>

Mystring::Mystring()
    :str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

Mystring::Mystring(const char* s)
    :str{nullptr} {
        if(s == nullptr) {
            str = new char[1];
            *str = '\0';
        }
        else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
    }

Mystring::Mystring(const Mystring &source) 
    :str{nullptr} {
        std::cout << "Copy constr called" << std::endl;
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
    }

Mystring::~Mystring() {
    std::cout << "Destr called for " << str << std::endl;
    delete [] str;
}

Mystring& Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy assignment = called for " << str << std::endl;
    if(this == &rhs) return *this;

    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

void Mystring::display() const {
    std::cout << get_str() << " : " << get_length() << std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char* Mystring::get_str() const {
    return str;
}