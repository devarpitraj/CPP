#ifndef _ACCOUNT_UTIL_H_
#define _ACCOUNT_UTIL_H_
#include"Account.h"
#include"Savings_Account.h"
#include"Checking_Account.h"
#include"Trust_Account.h"
#include<vector>

void display(const std::vector<Account*> &accounts);
void deposit(std::vector<Account*> &accounts, double amount);
void withdraw(std::vector<Account*> &accounts, double amount);

// //helper func for Account class
// void display(const std::vector<Account> &accounts);
// void deposit(std::vector<Account> &accounts, double amount);
// void withdraw(std::vector<Account> &accounts, double amount);

// //helper func for Savings Account class
// void display(const std::vector<Savings_Account> &accounts);
// void deposit(std::vector<Savings_Account> &accounts, double amount);
// void withdraw(std::vector<Savings_Account> &accounts, double amount);

// //helper func for Checking Account class
// void display(const std::vector<Checking_Account> &accounts);
// void deposit(std::vector<Checking_Account> &accounts, double amount);
// void withdraw(std::vector<Checking_Account> &accounts, double amount);

// //helper func for Trust Account class
// void display(const std::vector<Trust_Account> &accounts);
// void deposit(std::vector<Trust_Account> &accounts, double amount);
// void withdraw(std::vector<Trust_Account> &accounts, double amount);

#endif