#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_
#include"Savings_Account.h"
#include"Account.h"

class Trust_Account : public Savings_Account {
    //friend std::ostream& operator<<(std::ostream &os, const Trust_Account &obj);
    private:
        static constexpr int max_withdrawals = 3;
        static constexpr double max_withdraw_percent = 0.2;
    protected:
        int withdrawal_count;
    public:
        Trust_Account(std::string name = "Unnamed Trust Account", double balance = 0.0, double int_rate = 0.0);
        virtual void print(std::ostream &os) const override;
        virtual bool deposit(double amount) override;
        virtual bool withdraw(double amount) override;
        virtual ~Trust_Account() = default;

};

#endif