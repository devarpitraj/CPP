#include<iostream>
#include<string>

using namespace std;

class Account {
    private:
        double balance;
        string name;
    public:
        void set_balance(double bal) { balance = bal; }
        double get_balance() { return balance; }

        string get_name();
        void set_name(string n);

};

string Account::get_name() {
    return name;
}

void Account::set_name(string n) {
    name = n;
}

int main() {
    Account obj;
    obj.set_balance(10000.00);
    double bal = obj.get_balance();
    cout << "Balance is " << bal << endl;

    obj.set_name("frank");
    string n = obj.get_name();
    cout << "Name is " << n << endl;

    Account *ptr = new Account;
    ptr -> set_name("miles");
    string n2 = ptr -> get_name();
    cout << "Other name is " << n2 << endl;

    return 0;

}
