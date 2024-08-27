#include"Account_Util.h"
#include"IllegalBalanceException.h"
#include"IllegalFundsException.h"
#include<memory>

int main() {
    try {
        Account* p1 = new Savings_Account{"Frank"};
        Account* p2 = new Checking_Account{"Joe", 1000};

        //auto s1 = std::make_unique<Account> ("Moe", 1000);

        std::vector<Account*> vec_ptr{p1, p2};
        display(vec_ptr);
        deposit(vec_ptr, 2000);
        withdraw(vec_ptr, 4000);

        delete p1;
        delete p2;
    }


    catch(const IllegalBalanceException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    catch(const IllegalFundsException &ex) {
        std::cerr << ex.what() << std::endl;
    }
    
    return 0;
}