#ifndef _CHECKING_ACCOUNT_H_
#define _CHECKING_ACCOUNT_H_
#include"Account.h"

class Checking_Account : public Account {
    friend std::ostream& operator<<(std::ostream &os, const Checking_Account &obj);
    protected:
        double fee;
    public:
        Checking_Account(std::string name = "Unnamed Checking Account", double balance = 0.0, double fee = 1.50);
        bool withdraw(double amount);
};

#endif