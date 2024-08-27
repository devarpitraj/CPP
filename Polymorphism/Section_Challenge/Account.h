#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<iostream>
#include<string>
#include"I_Printable.h"

class Account : public I_Printable {
    //friend std::ostream& operator<<(std::ostream &os, const Account &obj);
    protected:
        std::string name;
        double balance;
    public:
        Account(std::string name = "Unnamed Account", double amount = 0.0);
        virtual void print(std::ostream &os) const override;
        virtual bool deposit(double amount) = 0;
        virtual bool withdraw(double amount) = 0;
        virtual ~Account() = default;
};

#endif