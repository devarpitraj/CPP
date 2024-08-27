#include"Account_Util.h"

int main() {
    std::vector<Account> acc_vec;
    acc_vec.push_back(Account{});
    acc_vec.push_back(Account{"Frank"});
    acc_vec.push_back(Account{"Moe", 1000});

    display(acc_vec);
    deposit(acc_vec, 1000);
    withdraw(acc_vec, 1500);

    std::vector<Savings_Account> sacc_vec;
    sacc_vec.push_back(Savings_Account{});
    sacc_vec.push_back(Savings_Account{"Frank", 1000});
    sacc_vec.push_back(Savings_Account{"Moe", 2000, 5});

    display(sacc_vec);
    deposit(sacc_vec, 1000);
    withdraw(sacc_vec, 2000);

    std::vector<Checking_Account> cacc_vec;
    cacc_vec.push_back(Checking_Account{});
    cacc_vec.push_back(Checking_Account{"Frank"});
    cacc_vec.push_back(Checking_Account{"Moe", 1000});

    display(cacc_vec);
    deposit(cacc_vec, 1000);
    withdraw(cacc_vec, 1000);

    std::vector<Trust_Account> tacc_vec;
    tacc_vec.push_back(Trust_Account{});
    tacc_vec.push_back(Trust_Account{"Frank"});
    tacc_vec.push_back(Trust_Account{"Moe", 1000});
    tacc_vec.push_back(Trust_Account{"Curly", 2000, 5});

    display(tacc_vec);
    deposit(tacc_vec, 4000);
    deposit(tacc_vec, 5000);
    withdraw(tacc_vec, 1000);
    withdraw(tacc_vec, 1000);
    withdraw(tacc_vec, 1500);
    //withdraw(tacc_vec, 1000);

    return 0;
}