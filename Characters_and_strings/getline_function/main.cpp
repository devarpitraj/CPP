#include <iostream>

using namespace std;

int main() {
    char full_name[20] {};
    char full_name1[20] {};

    //cout << "Enter full name(cin funtion)";
    //cin >> full_name;
    //cout << "Your full name is " << full_name << endl;  //cin only reads upto blank space

    cout << "Enter full name(getline function)";
    cin.getline(full_name1,20);
    cout << "Your full name is " << full_name1 << endl;  //cin.getline reads upto 20 characters

    return 0;
}