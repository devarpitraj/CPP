#include"Savings_Account.h"
#include"Account.h"
#include<iostream>

Savings_Account::Savings_Account(std::string name, double balance, double int_rate)
    :Account(name, balance), int_rate{int_rate} {
}

bool Savings_Account::deposit(double amount) {
    amount += amount * (int_rate / 100);
    return Account::deposit(amount);
}

std::ostream& operator<<(std::ostream &os, const Savings_Account &account) {
    os << "[Savings Account: " << account.name << " : " << account.balance << " : " << account.int_rate << "%" << "]";
    os << std::endl;
    return os;
}