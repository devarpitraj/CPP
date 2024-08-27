#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include"Savings_Account.h"
#include"Account.h"

class Trust_Account : public Savings_Account {
    friend std::ostream& operator<<(std::ostream &os, const Trust_Account &obj);
    private:
        static constexpr int max_withdrawals = 3;
        static constexpr double max_withdraw_percent = 0.2;
    protected:
        int withdrawal_count;
    public:
        Trust_Account(std::string name = "Unnamed Trust Account", double balance = 0.0, double int_rate = 0.0);
        bool deposit(double amount);
        bool withdraw(double amount);
        int get_with() { return withdrawal_count; }

};

#endif