#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<iostream>

class Mystring {
    friend std::ostream& operator<< (std::ostream &os, const Mystring &obj);
    friend std::istream& operator>> (std::istream &is, Mystring &obj);

    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    private:
        char* str;
    public:
        Mystring();
        Mystring(const char* s);
        Mystring(const Mystring &source);
        Mystring(Mystring &&source);
        ~Mystring();

        Mystring& operator=(const Mystring &rhs);   //copy assignment
        Mystring& operator=(Mystring &&rhs);  //move assignment

        void display() const;
        int get_length() const;
        const char* get_str() const;
};

#endif