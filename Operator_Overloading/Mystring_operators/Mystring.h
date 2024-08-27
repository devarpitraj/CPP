#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring {
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

        Mystring operator-() const; //make lowercase
        Mystring operator+(const Mystring &rhs) const; //concatenate
        bool operator==(const Mystring &rhs) const;

        void display() const;
        int get_length() const;
        const char* get_str() const;
};

#endif