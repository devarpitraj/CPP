#include"Account.h"
#include"Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
    :Account{name, balance}, fee{fee} {}

bool Checking_Account::withdraw(double amount) {
    amount += fee;
    return Account::withdraw(amount);
}

std::ostream& operator<<(std::ostream &os, const Checking_Account &obj) {
    os << "[Checking Account: " << obj.name << " : " << obj.balance << " : " << obj.fee << " fee]";
    return os;
}