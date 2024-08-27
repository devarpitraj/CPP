#include<iostream>

using namespace std;

int main() {
    int num {};
    cout << "Enter a number";
    cin >> num;
    cout << num << " is " << ((num % 2 == 0) ? "even" : "odd");
    return 0;
}