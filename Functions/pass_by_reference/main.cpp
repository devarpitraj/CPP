#include<iostream>

using namespace std;

void swap (int &a, int &b) {
    cout << a << endl;
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x{20}, y{40};
    cout << "x:" << x << " y:" << y << endl;
    swap(x,y);
    cout << "x:" << x << " y:" << y << endl;
    return 0;
}