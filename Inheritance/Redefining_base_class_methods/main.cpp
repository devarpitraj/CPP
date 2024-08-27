#include<iostream>

class Account {
    double balance;
    public:
        Account() : balance {0} {};
        Account(double bal) : balance{bal} {};

        void deposit(double amount) {
            balance += amount;
            std::cout << "New Balance after depositing " << amount << " : " << balance << std::endl;
        }

        void withdraw(double amount) {
            if(balance >= amount) {
                balance -= amount;
                std::cout << "New Balance after withdrawing " << amount << " : " << balance << std::endl;
            }
            else 
                std::cout << "Not sufficient balance : " << balance << std::endl;
        }
};

class Savings_Account : public Account {
    double interest_rate;
    public:
        Savings_Account() : Account{}, interest_rate{0.0} {};
        Savings_Account(double amount) : Account{amount} {};

        void deposit(double amount, double rate) {
            amount += (amount * rate);
            Account::deposit(amount);
        }
};

int main() {
    {
        Account frank;
        frank.deposit(1000.0);
        frank.withdraw(500.0);
    }
    std::cout << std::endl;
    {
        Account frank(2000);
        frank.deposit(1000.0);
        frank.withdraw(500.0);
    }
    std::cout << std::endl;
    {
        Savings_Account frank;
        frank.deposit(1000, 0.5);
        frank.withdraw(200);
    }
    std::cout << std::endl;
    {
        Savings_Account frank(5000);
        frank.deposit(1000.0, 0.1);
        frank.withdraw(10000.0);
    }
    std::cout << std::endl;
    return 0;
}