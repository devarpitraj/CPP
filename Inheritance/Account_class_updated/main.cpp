#include"Account_Util.h"
#include<iostream>
#include<vector>

int main() {
    std::vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Frank"});
    accounts.push_back(Account {"Joe", 1000});

    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 500);

    std::vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account{});
    sav_accounts.push_back(Savings_Account{"Frank"});
    sav_accounts.push_back(Savings_Account{"Joe", 1000, 5});
    sav_accounts.push_back(Savings_Account{"Moe", 3000, 2});

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 500);

    return 0;
}