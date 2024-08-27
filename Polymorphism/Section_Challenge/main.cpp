#include"Account_Util.h"

int main() {
    //Account frank{"Frank"};   //obj of abstract class is not allowed

    // Savings_Account frank{"Frank"};
    // std::cout << frank << std::endl;

    // Checking_Account joe{"Joe", 1000};
    // std::cout << joe << std::endl;

    // Trust_Account moe{"Moe", 3000, 5};
    // std::cout << moe << std::endl;

    // Account *trust = new Trust_Account{"Trust", 2000, 4};
    // std::cout << *trust << std::endl;
    // trust->deposit(2000);
    // std::cout << *trust << std::endl;
    // trust->withdraw(200);
    // std::cout << *trust << std::endl;

    Account* p1 = new Savings_Account{"Sav", 1000, 6};
    Account* p2 = new Checking_Account{"Chec", 3000};
    Account* p3 = new Trust_Account{"Trus", 10000, 2};

    std::vector<Account*> vec {p1, p2, p3};
    display(vec);
    deposit(vec, 2000);
    withdraw(vec, 2000);
    deposit(vec, 6000);
    withdraw(vec, 5000);

    display(vec);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}