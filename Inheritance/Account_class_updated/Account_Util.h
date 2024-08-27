#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include"Account.h"
#include"Savings_Account.h"
#include<vector>

//Utility helper func for Account class
void display(const std::vector<Account> &accounts);
void deposit(std::vector<Account> &accounts, double amount);
void withdraw(std::vector<Account> &accounts, double amount);

//Utility helper func for Savings_Account class
void display(const std::vector<Savings_Account> &accounts);
void deposit(std::vector<Savings_Account> &accounts, double amount);
void withdraw(std::vector<Savings_Account> &accounts, double amount);

#endif