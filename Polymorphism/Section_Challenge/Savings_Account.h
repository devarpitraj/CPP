#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include"Account.h"

class Savings_Account : public Account {
    //friend std::ostream& operator<<(std::ostream &os, const Savings_Account &obj);
    protected:
        double int_rate;
    public:
        Savings_Account(std::string name = "Unnamed Savings Account", double balance = 0.0, double int_rate = 0.0);
        virtual void print(std::ostream &os) const override;
        virtual bool withdraw(double amount) override;
        virtual bool deposit(double amount) override;
        virtual ~Savings_Account() = default;
};

#endif