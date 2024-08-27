#include"Mystring.h"
#include<iostream>
#include<vector>

int main() {
    Mystring empty;
    Mystring larry{"Larry"};
    larry.display();
    std::cout << std::endl;

    larry = empty;
    empty.display();
    larry.display();
    std::cout << std::endl;

    Mystring test;
    test.display();
    test = "This is a test";
    test.display();
    std::cout << std::endl;

    std::vector<Mystring> stooge_vec;
    stooge_vec.push_back(larry);
    stooge_vec.push_back("Moe");
    stooge_vec.push_back("Curly");

    for(auto &obj:stooge_vec) {
        obj.display();
    }
    std::cout << std::endl;

    std::cout << "Passing R-value" << std::endl;
    Mystring m1{};
    m1 = Mystring{"Rvalue"};
    m1.display();
    std::cout << std::endl;

    return 0;
}