#include<iostream>
#include "Account.h"

using namespace std;

int main() {
    Account obj;
    obj.set_balance(1000.00);
    double bal = obj.get_balance();
    cout << "Balance is " << bal << endl;

    return 0;
}

//g++ Account.cpp main.cpp in terminal to run