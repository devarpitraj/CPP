#include<iostream>
#include<memory>

class Base {
    public:
        void say_hello() const {
            std::cout << "Hello - It is a base obj" << std::endl;
        }
};

class Derived : public Base {
    public:
        void say_hello() const {
            std::cout << "Hello - It is a derived obj" << std::endl;
        }
};

void greetings(const Base &obj) {
    std::cout << "Greetings : ";
    obj.say_hello();
}

int main() {
    Base base;
    base.say_hello();   //binds to Base::say_hello

    Derived derived;
    derived.say_hello();    //binds to Derived::say_hello

    Base* p = new Derived();
    p->say_hello();     //binds to Base::say_hello because p is a pointer to Base class

    greetings(base);    //binds to Base::say_hello coz obj is ref to Base class
    greetings(derived); //binds to Base::say_hello coz obj is ref to Base class

    //Smart pointer
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived> ();
    ptr1->say_hello();  //this also binds to Base::say_hello


    delete p;
    return 0;
}