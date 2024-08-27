#include<iostream>
#include<string>

//using namespace std;

class Player {
    private:
        std::string name;
        int health;
        int xp;

    public:
        Player() {
            name = "No args cons";
            std::cout << "No args constructor is called" << std::endl;
        }

        Player(std::string n) {
            name = "string cons";
            std::cout << "string arg constructor is called" << std::endl;
        }

        Player(std::string n, int health, int xp) {
            name = "3 args cons";
            std::cout << "3 args constructor is called" << std::endl;
        }

        ~Player() {
            std::cout << "Destructor is called for " << name << std::endl;
        }
};

int main() {
    Player frank;   
    Player hero {"Hero"};
    Player villain {"Villain", 100, 13};
    
    //Destructors are called in reverse order i.e. from last obj created to first obj created
    //here 3 args destructor will be called first then string args and then no args destructor will be called.

    return 0;
}