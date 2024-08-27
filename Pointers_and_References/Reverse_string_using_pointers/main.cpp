#include<iostream>
#include<string>

using namespace std;

int main() {
    string str {};
    cout << "Enter a string:";
    cin >> str;

    //We use const char* because we are dealing with C-style strings, 
    //where each character is represented by a char.
    const char *start = str.c_str();    //c_str() function is used to convert string into C-style string
    const char *end = str.c_str() + str.size() - 1;

    string reversed{};
    while (end >= start) {
        reversed.push_back(*end);
        end--;
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reversed << endl;

    return 0;

}