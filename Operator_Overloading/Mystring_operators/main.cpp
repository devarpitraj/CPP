#include"Mystring.h"
#include<iostream>

int main() {
    std::cout << std::boolalpha << std::endl;

    Mystring larry{"Larry"};
    Mystring moe{"Moe"};
    Mystring stooge;

    stooge = larry;

    larry.display();
    moe.display();
    stooge.display();

    std::cout << (larry == moe) << std::endl;
    std::cout << (larry == stooge) << std::endl;

    Mystring curly{"CURLY"};
    curly.display();
    Mystring curly2 = -curly;
    curly.display();
    curly2.display();

    Mystring stooges = larry + " " + "Moe";
    //Mystring stooges = "Moe" + larry;   //lhs must be Mystring obj in case of member func
    stooges.display();

    return 0;
}