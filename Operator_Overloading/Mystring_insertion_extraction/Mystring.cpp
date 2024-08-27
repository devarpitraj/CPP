#include"Mystring.h"
#include<iostream>
#include<cstring>

Mystring::Mystring()
    :str{nullptr} {
        str = new char[1];
        *str = '0';
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
        str = new char [std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
    }

Mystring::Mystring(Mystring &&source)
    :str{source.str} {
        source.str = nullptr;
    }

Mystring::~Mystring() {
    delete [] str;
}

Mystring& Mystring::operator=(const Mystring &rhs) {
    if(this == &rhs) return *this;

    delete [] str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

Mystring& Mystring::operator=(Mystring &&rhs) {
    if(this == &rhs) return *this;

    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char* buff = new char[std::strlen(lhs.str) + std::strlen(rhs.str) + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

Mystring operator-(const Mystring &obj) {
    char* buff = new char[std::strlen(obj.str) + 1];
    std::strcpy(buff, obj.str);
    for(size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = tolower(buff[i]);
    Mystring temp{buff};
    delete [] buff;
    return temp;
}

bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

std::ostream& operator<<(std::ostream &os, const Mystring &obj) {
    os << obj.str;  //if friend function
    //os << obj.get_str();    //if not friend function
    return os;
}

std::istream& operator>>(std::istream &is, Mystring &obj) {
    char* buff = new char[1000];
    is >> buff;
    obj = Mystring{buff};
    delete [] buff;
    return is;
}

void Mystring::display() const {
    std::cout << get_str() << " : " << get_length() << std::endl;
}

int Mystring::get_length() const { return std::strlen(str); }
const char* Mystring::get_str() const { return str; }