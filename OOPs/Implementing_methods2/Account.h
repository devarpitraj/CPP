#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
    private:
        double balance;
    public:
        void set_balance(double bal);
        double get_balance();
};

#endif