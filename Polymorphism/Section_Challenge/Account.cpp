#include"Account.h"

Account::Account(std::string name, double balance)
    :name{name}, balance{balance} {}

bool Account::deposit(double amount) {
    if(amount < 0) return false;
    else {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount) {
    if(balance >= amount) {
        balance -= amount;
        return true;
    } else return false;
}

void Account::print(std::ostream &os) const {
    os << "[Account: " << name << " : " << balance << "]";
}

// std::ostream& operator<<(std::ostream &os, const Account &obj) {
//     os << "[Account: " << obj.name << " : " << obj.balance << "]";
//     return os;
// }