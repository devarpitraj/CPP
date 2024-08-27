#include"Mystring.h"
#include<iostream>

int main() {
    Mystring larry;
    Mystring moe;
    Mystring curly;

    std::cout << "Enter three stooges : ";
    std::cin >> larry >> moe >> curly;

    std::cout << "The three stooges are : " << larry << ", " << moe << ", " << curly << std::endl;

    return 0;

}