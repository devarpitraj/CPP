#include<iostream>

using namespace std;

int main() {
    int scores[] {1,2,3,4,5};

    cout << "scores = " << scores << endl;
    cout << "*scores = " << *scores << endl;

    int *arr_ptr {scores};  //& is not used since scores contains an address

    cout << "arr_ptr = " << arr_ptr << endl;
    cout << "*arr_ptr = " << *arr_ptr << endl;

    cout << "arr_ptr[0] = " << arr_ptr[0] << " = " << *(arr_ptr) << endl; //using array and pointer interchangebly
    cout << "arr_ptr[1] = " << arr_ptr[1] << " = " << *(arr_ptr + 1) << endl;
    cout << "arr_ptr[2] = " << arr_ptr[2] << " = " << *(arr_ptr + 2) << endl;

    return 0;
}