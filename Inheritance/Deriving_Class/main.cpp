#include<iostream>
#include<string>

using namespace std;

class Account {
    private:
        double balance;
        string name;
    public:
        Account();
        ~Account();
        void deposit(double);
        void withdraw(double);
};

class Savings_Account:public Account {
    private:
        double int_rate;
    public:
        Savings_Account();
        ~Savings_Account();
        //void deposit(double);
        void withdraw(double);
};

Account::Account()
    :balance{0.0}, name{"New Account"} {}

Account::~Account() {}

void Account::deposit(double val) {
    cout << "Account is depositing " << val << endl;
}

void Account::withdraw(double val) {
    cout << "Account is withdrawing " << val << endl;
}

Savings_Account::Savings_Account() 
    :int_rate {3.0} {}

Savings_Account::~Savings_Account() {}

//void Savings_Account::deposit(double val) {
    //cout << "Savings Account is depositing " << val << endl;
//}

void Savings_Account::withdraw(double val) {
    cout << "Savings Account is withdrawing " << val << endl;
}

int main() { 
    Account acc;
    acc.deposit(1000);
    acc.withdraw(500);

    Savings_Account *p_acc = new Savings_Account;
    p_acc->deposit(2000);
    p_acc->withdraw(1000);
    delete p_acc;

    return 0;
}