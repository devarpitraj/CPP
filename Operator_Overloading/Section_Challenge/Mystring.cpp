#include"Mystring.h"
#include<iostream>
#include<cstring>

std::ostream& operator<<(std::ostream &os, const Mystring &obj) {
    os << obj.str << " : " << std::strlen(obj.str) << std::endl;
    return os;
}

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
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
    }

Mystring::Mystring(const Mystring &source)
    :str{nullptr} {
        std::cout << "using copy constr" << std::endl;
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
    }

Mystring::Mystring(Mystring &&source)
    :str{source.str} {
        std::cout << "using move constr" << std::endl;
        source.str = nullptr;
    }

Mystring::~Mystring() {
    std::cout << "using destr" << std::endl;
    delete [] str;
}

Mystring& Mystring::operator=(const Mystring &rhs) {
    std::cout << "using copy assignment=" << std::endl;
    if(this == &rhs) return *this;

    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);

    return *this;
}

Mystring& Mystring::operator=(Mystring &&rhs) {
    std::cout << "using move assignment=" << std::endl;
    if(this == &rhs) return *this;

    str = rhs.str;
    rhs.str = nullptr;
    
    return *this;
}

Mystring Mystring::operator-() const {
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = 0; i < std::strlen(buff); i++) {
        buff[i] = tolower(buff[i]);
    }
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) == 0);
}

bool Mystring::operator!=(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) != 0);
}

bool Mystring::operator<(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) < 0);
}

bool Mystring::operator>(const Mystring &rhs) const {
    return (std::strcmp(str, rhs.str) > 0);
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    char* buff = new char[std::strlen(str) +  std::strlen(rhs.str) + 1];
    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring& Mystring::operator+=(const Mystring &rhs) {
    Mystring temp;
    temp = *this + rhs;
    *this = temp;

    return *this;
}

Mystring Mystring::operator*(int n) {
    char* buff = new char[(n*std::strlen(str)) + 1];
    std::strcpy(buff, str);
    /*while(n) {
        std::strcat(buff, str);
        n--;
    }*/
    for(int i = 0; i < n - 1; i++)
        std::strcat(buff, str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring& Mystring::operator*=(int n) {
    Mystring temp;
    temp = *this * n;
    *this = temp;
    return *this;
}

Mystring Mystring::operator++() {
    std::cout << "using pre increment" << std::endl;
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = 0; i < (std::strlen(buff) / 2); i++)   
        buff[i] = toupper(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator++(int) {
    std::cout << "using post increment" << std::endl;
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = (std::strlen(buff) / 2); i < std::strlen(buff); i++)
        buff[i] = toupper(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator--() {
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = 0; i < (std::strlen(buff) / 2); i++)
        buff[i] = tolower(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring Mystring::operator--(int) {
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for(size_t i = (std::strlen(buff) / 2); i < std::strlen(buff); i++)
        buff[i] = tolower(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}