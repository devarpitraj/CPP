#include"Account.h"
#include"IllegalBalanceException.h"
#include"IllegalFundsException.h"

Account::Account(std::string name, double balance)
    :name{name}, balance{balance} {
        if(balance < 0)
            throw IllegalBalanceException{};
    }

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
    } else throw IllegalFundsException{};
}

void Account::print(std::ostream &os) const {
    os << "[Account: " << name << " : " << balance << "]";
}

// std::ostream& operator<<(std::ostream &os, const Account &obj) {
//     os << "[Account: " << obj.name << " : " << obj.balance << "]";
//     return os;
// }