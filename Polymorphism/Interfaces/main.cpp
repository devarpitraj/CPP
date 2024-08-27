#include<iostream>

class I_Printable { //Abstract Class (it contains only pure virtual functions)
    friend std::ostream& operator<<(std::ostream &os, const I_Printable &obj);
    public:
        virtual void print(std::ostream &os) const = 0; //pure virtual func
         virtual ~I_Printable() = default;
};

std::ostream& operator<<(std::ostream &os, const I_Printable &obj) {
    obj.print(os);
    return os;
}

class Account : public I_Printable {
    public:
        virtual void print(std::ostream &os) const override {
            os << "Account display";
        }
};

class Savings_Account : public Account {
    public:
        virtual void print(std::ostream &os) const override {
            os << "Savings Account display";
        }
};

class Checking_Account : public Account {
    public:
        virtual void print(std::ostream &os) const override {
            os << "Checking Account display";
        }
};

class Dog : public I_Printable {
    public:
        virtual void print(std::ostream &os) const override {
            os << "Dog display";
        }
};

int main()  {
    Account* p1 = new Savings_Account();
    std::cout << *p1 << std::endl;

    Account* p2 = new Checking_Account();
    std::cout << *p2 << std::endl;

    Dog *dog = new Dog();
    std::cout << *dog << std::endl;

    return 0;
}