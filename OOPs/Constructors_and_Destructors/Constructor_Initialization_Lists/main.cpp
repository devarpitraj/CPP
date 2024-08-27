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
         :name{"Default name"}, health{0}, xp{0} {  //this is initialization if this is not written then garbage initialization is done
            //name = "Default name";        // This is assignment not initialization
            //health =0;
            //xp = 0;
            std::cout << "No args constructor is called" << std::endl;
        }

        Player(std::string n) 
         :name{n}, health{50}, xp{5} {
            std::cout << "string arg constructor is called" << std::endl;
        }

        Player(std::string n, int h, int x) 
         :name{n}, health{h}, xp{x} {
            std::cout << "3 args constructor is called" << std::endl;
        }

        void get_stats() {
            std::cout << "Name: " << name << std::endl << "Health: " << health << std::endl << "XP: " << xp << std::endl;
        }
};

int main() {
    Player frank;   
    Player hero {"Hero"};
    Player villain {"Villain", 100, 13};

    std::cout << std::endl;
    std::cout << "Stats of frank :" << std::endl;
    frank.get_stats();

    std::cout << std::endl;
    std::cout << "Stats of Hero :" << std::endl;
    hero.get_stats();

    std::cout << std::endl;
    std::cout << "Stats of Villain :" << std::endl;
    villain.get_stats();

    return 0;
}