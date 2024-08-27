#include"Account.h"
#include"Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    :Account{name, balance}, int_rate{int_rate} {
    }

bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate / 100);
    return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount) {
    return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream &os) const {
    os << "[Savings Account: " << name << " : " << balance << " : " << int_rate << "%]";
}

// std::ostream& operator<<(std::ostream &os, const Savings_Account &obj) {
//     os << "[Savings Account: " << obj.name << " : " << obj.balance << " : " << obj.int_rate << "%]";
//     return os;
// }