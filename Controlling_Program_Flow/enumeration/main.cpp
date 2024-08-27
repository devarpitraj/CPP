#include<iostream>

using namespace std;

enum Color {    //color User_defined data type
    red, white, green, blue
};

int main() {
    Color shirt {green};   //shirt is a enum variable
    switch (shirt) {
        case red : cout << "red"; break;
        case white: cout << "white"; break;
        case green : cout << "green"; break;
        case blue : cout << "blue"; break;
        default : cout << "none";
    }

    return 0;
}