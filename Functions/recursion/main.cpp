#include<iostream>

using namespace std;

int sum_of_digits(int num) {
    if(num / 10 == 0)
        return num;
    else
        return num % 10 + sum_of_digits(num / 10);
}

int main() {
    int num{};
    cout << " Enter a number:";
    cin >> num;
    cout << "Sum of digits of " << num << " is:" << sum_of_digits(num) << endl;

}