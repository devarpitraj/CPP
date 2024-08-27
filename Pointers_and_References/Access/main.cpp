#include<iostream>

using namespace std;

int main() {
    int num{10};
    cout << "Address of num is " << &num << endl;

    int *p1{};
    double *p2{};
    cout << "Size of pointer p1 is:" << sizeof(p1) << endl;
    cout << "Size of pointer p2 is:" << sizeof(p2) << endl;

    return 0;
}