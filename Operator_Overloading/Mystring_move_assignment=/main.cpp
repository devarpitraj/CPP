#include"Mystring.h"
#include<iostream>
#include<vector>
#include<cstring>

int main() {
    Mystring a{"Hello"};
    a.display(); 
    a = Mystring{"Rvalue"};
    a.display();
    a = "rvalue text";
    a.display();
    std::cout << std::endl;

    Mystring empty;
    Mystring larry{"Larry"};
    Mystring stooge{larry};

    empty = larry;  //l-value
    empty = "Funny";    //r-value

    std::cout << std::endl;
    Mystring stooges;
    stooges = "Laary, Moe and Curly";
    std::cout << std::endl;

    std::vector<Mystring> vec;
    vec.push_back("Larry");
    vec.push_back("Moe");
    vec.push_back("Curly");
    for(const Mystring& i:vec)
        i.display();
    
    return 0;
}