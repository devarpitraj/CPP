#include"Mystring.h"
#include<cstring>
#include<iostream>


Mystring::Mystring()
    :str{nullptr} {
        std::cout << "using no-args constr" << std::endl;
        str = new char[1];
        *str = '\0';
    }

Mystring::Mystring(const char* s)
    :str{nullptr} {
        std::cout << "using overloaded constr" << std::endl;
        if(s == nullptr) {
            str = new char[1];
            *str = '\0';
        }
        else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
    }

Mystring::Mystring(const Mystring &source)  //copy constr
    :str{nullptr} {
        std::cout << "using copy constr" << std::endl;
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str); 
    }

Mystring::Mystring(Mystring &&source)   //move constr
    :str{source.str} {
        std::cout << "using move constr" << std::endl;
        source.str = nullptr;
    }

Mystring::~Mystring() {
    delete [] str;
}

Mystring& Mystring::operator=(const Mystring &rhs) {    //copy assignment
    std::cout << "using copy assignment" << std::endl;
    if(this == &rhs) return *this;
    
    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

Mystring& Mystring::operator=(Mystring &&rhs) { //move assignment
    std::cout << "Using move assignment" << std::endl;
    if(this == &rhs) return *this;

    delete [] str;
    str = rhs.str;  //steal the pointer
    rhs.str = nullptr;

    return *this;
}

void Mystring::display() const {
    std::cout << get_str() << " : " << get_length() << std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char* Mystring::get_str() const { return str; }