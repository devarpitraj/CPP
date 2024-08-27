#include<iostream>
#include<string>

//using namespace std;

class Player {
    private:
        std::string name;
        int health;
        int xp;

    public:
        Player() 
         :Player{"Default Name", 0, 0} { //here this calls the 3args constr. , the body of 3args is executed first
            std::cout << "No args constructor is called" << std::endl;
        }

        Player(std::string n) 
         :Player{n, 0, 0} {
            std::cout << "string arg constructor is called" << std::endl;
        }

        Player(std::string n, int h, int x) 
         :name{n}, health{h}, xp{x} {
            std::cout << "3 args constructor is called" << std::endl;
        }

};

int main() {
    Player frank;
    std::cout << std::endl;   
    Player hero {"Hero"};
    std::cout << std::endl;
    Player villain {"Villain", 100, 13};

    return 0;
}