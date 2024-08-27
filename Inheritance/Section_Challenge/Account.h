#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include<iostream>
#include<string>

class Account {
    friend std::ostream& operator<<(std::ostream &os, const Account &obj);
    protected:
        std::string name;
        double balance;
    public:
        Account(std::string name = "Unnamed Account", double amount = 0.0);
        bool deposit(double amount);
        bool withdraw(double amount);
};

#endif