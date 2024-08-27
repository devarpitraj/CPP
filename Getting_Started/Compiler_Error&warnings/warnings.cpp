#include <iostream>

int main() {
    int a;
    int b = 10;     //variable set but not used
    std::cout << a << std::endl;   //a is used uninitialized
    return 0;

}