#include<iostream>

using namespace std;

int main() {
    int sum {};
    for (int i{1}; i <= 20; i++) {
        sum += ((i % 2 != 0) ? i : 0);
    }
    cout << "Sum = " << sum;
    return 0;
}