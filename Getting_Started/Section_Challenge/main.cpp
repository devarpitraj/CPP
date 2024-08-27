#include<iostream>
int main() {
    int num;
    std::cout << "Emter your favourite number between 1 and 100:";
    std::cin >> num;
    std::cout << "Amazing!! That's my favourite number too!" << std::endl;
    std::cout << "No really! " << num << ", is my favourite number";
    return 0;
}