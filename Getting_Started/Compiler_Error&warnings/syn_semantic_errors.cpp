#include<iostream>

int main() {
    //Syntax Errors
    //std::cout << "Errors << std::endl;   ->" is missing
    //std::cout << "Errors" << std::endlllll;  ->endlllll is not in std namespace
    //return;  ->main func returns an int

    //Semantic Errors
    //std::cout << ("Errors"/125) << std::endl;   ->mismatch operands
    //return "joe";  ->return type is int
}