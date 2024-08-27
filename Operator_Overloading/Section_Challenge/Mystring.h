#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include<iostream>

class Mystring {
    friend std::ostream& operator<<(std::ostream &os, const Mystring &obj);
    private:
        char* str;
    public:
        Mystring(); //no-args constr
        Mystring(const char* s);    //overloaded constr
        Mystring(const Mystring &source);   //copy constr
        Mystring(Mystring &&source);  //move constr
        ~Mystring();    //destr

        Mystring& operator=(const Mystring &rhs);   //copy assignment
        Mystring& operator=(Mystring &&rhs);  //move assignment

        //overloaded operators
        Mystring operator-() const;
        bool operator==(const Mystring &rhs) const;
        bool operator!=(const Mystring &rhs) const;
        bool operator<(const Mystring &rhs) const;
        bool operator>(const Mystring &rhs) const;
        Mystring operator+(const Mystring &rhs) const;
        Mystring& operator+=(const Mystring &rhs);
        Mystring operator*(int n);
        Mystring& operator*=(int n);
        Mystring operator++(); //pre-increment
        Mystring operator++(int);  //post-increment
        Mystring operator--();  //pre-decrement
        Mystring operator--(int);   //post-decrement
};

#endif