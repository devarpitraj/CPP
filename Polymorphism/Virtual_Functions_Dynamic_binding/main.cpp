#include<iostream>
#include<vector>

class Account {
    public:
        virtual void withdraw() {
            std::cout << "Account::withdraw" << std::endl;
        }
        virtual ~Account() {
            std::cout << "Account::destructor" << std::endl;
        }
};

class Savings : public Account {
    virtual void withdraw() {
        std::cout << "Savings::withdraw" << std::endl;
    }
    virtual ~Savings() {
        std::cout << "Savings::destructor" << std::endl;
    }
};

class Checking : public Account {
    virtual void withdraw() {
        std::cout << "Checking::withdraw" << std::endl;
    }
    virtual ~Checking() {
        std::cout << "Checking::destructor" << std::endl;
    }
};

class Trust : public Account {
    virtual void withdraw() {
        std::cout << "Trust::withdraw" << std::endl;
    }
    virtual ~Trust() {
        std::cout << "Trust::destructor" << std::endl;
    }
};

int main() {
    Account* p1 = new Account();
    Account* p2 = new Savings();
    Account* p3 = new Checking();
    Account* p4 = new Trust();

    p1->withdraw();
    p2->withdraw();
    p3->withdraw();
    p4->withdraw();

    std::cout << "=======Array============" << std::endl;
    Account* array[] = {p1, p2, p3, p4};
    for(auto i{0}; i < 4; i++)
        array[i]->withdraw();

    std::cout << "=======Vector============" << std::endl;
    std::vector<Account*> vec {p1, p2, p3, p4};
    for(auto acc_ptr:vec)
        acc_ptr->withdraw();
    
    std::cout << std::endl;
    delete p1;  //warning
    std::cout << std::endl;

    delete p2;  //warning
    std::cout << std::endl;

    delete p3;  //warning
    std::cout << std::endl;

    delete p4;  //warning
    std::cout << std::endl;
                //warning :- deleting object of 
                // polymorphic class type 'Account' which has non-virtual destructor might cause undefined behavior
                //solution :- define virtual destructors

    
    return 0;
}