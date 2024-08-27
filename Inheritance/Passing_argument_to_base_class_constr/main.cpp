#include<iostream>

class Base {
    int val1;
    int val2;
    public:
        Base() : val1{0}, val2{0} {
            std::cout << "Base no-args constr" << std::endl;
        }

        Base(int x) : val1{x}, val2{0} {
            std::cout << "Base 1 arg constr" << std::endl;
        }

        Base(int x, int y) : val1{x}, val2{y} {
            std::cout << "2 args Base constr" << std::endl;
        }
};

class Derived : public Base {
    int double_val1;
    int double_val2;
    public:
        Derived() : Base{}, double_val1{0}, double_val2{0} {
            std::cout << "Derived no args constr" << std::endl;
        }

        Derived(int x) : Base{x}, double_val1{x*2} {
            std::cout << "Derived 1 arg constr" << std::endl;
        }

        Derived(int x, int y) : double_val1(x*2), double_val2{y*2} {
            //Base no args constr will be called because Base 2 args constr is delegated here
            std::cout << "Derived 2 args constr" << std::endl;
        }
};

int main() {
    Base base;  //Base no-args constr

    Base base1(10); //Base 1 arg constr

    Base base2(10, 20); //2 args Base constr

    Derived derived;    //Base no-args constr
                        //Derived no args constr

    Derived derived1(10);   //Base 1 arg constr
                            //Derived 1 arg constr

    Derived derived2(10, 20);   //Base no-args constr
                                //Derived 2 args constr

    return 0;
}