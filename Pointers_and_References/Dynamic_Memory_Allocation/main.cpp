#include<iostream>

using namespace std;

int main() {
    int *int_ptr{nullptr};

    int_ptr = new int;

    cout << "value of int_ptr = " << int_ptr << endl;
    cout << "*int_ptr = " << *int_ptr << endl;

    *int_ptr = 50;
    cout << "*int_ptr = " << *int_ptr << endl;

    delete int_ptr;

    return 0;
}