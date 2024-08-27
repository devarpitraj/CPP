#include"Account.h"
#include"Checking_Account.h"

Checking_Account::Checking_Account(std::string name, double balance, double fee)
    :Account{name, balance}, fee{fee} {}

bool Checking_Account::withdraw(double amount) {
    amount += fee;
    return Account::withdraw(amount);
}

bool Checking_Account::deposit(double amount) {
    return Account::deposit(amount);
}

void Checking_Account::print(std::ostream &os) const {
    os << "[Checking Account: " << name << " : " << balance << " : " << fee << " fee]";
}

// std::ostream& operator<<(std::ostream &os, const Checking_Account &obj) {
//     os << "[Checking Account: " << obj.name << " : " << obj.balance << " : " << obj.fee << " fee]";
//     return os;
// }