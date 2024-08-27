#include<iostream>

class Base {
    public:
        int a;
    protected:
        int b;  //(only accesible in class not by object)
    private:
        int c;  
};

class Derived_public: public Base {
    //public: a
    //protected: b 
    //no access to c
};

class Derived_protected: protected Base {
    //protected: a
    //protected: b
    //no access to c
};

class Derived_private: private Base {
    //private: a
    //private: b
    //no access to c
};

int main() {
    /*
    Base base;
    base.a {100};   //accessible(public)
    base.b {200};   //inaccesible(protected)
    base.c {300};   //inaccesible(private)
    */

    /*
    Derived_public pub;
    pub.a{100};     //accessible(public)
    pub.b{200};     //inaccesible(protected)
    pub.c{300};     //inaccesible(private)
    */

    /*
    Derived_protected pri;
    pri.a{100};     //inaccesible(protected)
    pri.b{200};     //inaccesible(protected)
    pri.c{300};     //inaccesible(private)
    */

    /*
    Derived_private private;
    private.a{100}; //inaccesible(private)
    private.b{200}; //inaccesible(private)
    private.c{300}; //inaccesible(private)
    */
}