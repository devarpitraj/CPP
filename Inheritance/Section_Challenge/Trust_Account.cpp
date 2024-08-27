#include"Savings_Account.h"
#include"Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
    :Savings_Account(name, balance, int_rate), withdrawal_count{0} {}

bool Trust_Account::deposit(double amount) {
    if(amount >= 5000) {
        amount += 50;
        return Savings_Account::deposit(amount);
    }
    else return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount) {
    double deductable_amount = balance * max_withdraw_percent;
    if((deductable_amount < amount) || withdrawal_count >= max_withdrawals) return false;
    else {
        withdrawal_count++;
        return Savings_Account::withdraw(amount);        
    }
}

std::ostream& operator<<(std::ostream &os, const Trust_Account &obj) {
    os << "[Trust Account: " << obj.name << " : " << obj.balance << " : " << obj.int_rate << "% : "
        << "withdrawals: " << obj.withdrawal_count << "]";
    return os;
}