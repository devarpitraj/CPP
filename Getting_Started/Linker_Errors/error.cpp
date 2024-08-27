#include<iostream>

extern int x;       //The extern keyword in C++ is used to declare a global variable 
                    //or function which can be accessed from any part of the  
                    //program or from other files included in the program's header.

int main() {
    std::cout << x; //undefined reference to `x' ->linker error no compiler error
    return 0;
}