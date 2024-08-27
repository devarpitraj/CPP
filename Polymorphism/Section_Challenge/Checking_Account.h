#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include"Account.h"

class Checking_Account : public Account {
    //friend std::ostream& operator<<(std::ostream &os, const Checking_Account &obj);
    protected:
        double fee;
    public:
        Checking_Account(std::string name = "Unnamed Checking Account", double balance = 0.0, double fee = 1.50);
        virtual void print(std::ostream &os) const override;
        virtual bool deposit(double amount) override;
        virtual bool withdraw(double amount) override;
        virtual ~Checking_Account() = default;
};

#endif