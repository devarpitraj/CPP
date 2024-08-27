#include<iostream>
#include<string>

//using namespace std;

class Player {
    private:
        std::string name;
        int health;
        int xp;

    public:
        Player(std::string n = "None", int h = 0, int x = 0);   //Default parameters are used

        void get_stats() {
            std::cout << "Name: " << name << std::endl << "Health: " << health << std::endl << "XP: " << xp << std::endl;
        }
};

Player::Player(std::string n, int h, int x) 
         :name{n}, health{h}, xp{x} {
            std::cout << "3 args constructor is called" << std::endl;
        }

int main() {
    Player frank;
    std::cout << std::endl; //no args obj is created

    Player hero {"Hero"};
    std::cout << std::endl; //1 args obj is created

    Player villain {"Villain", 100, 13};    //2 args obj is created
    std::cout << std::endl;

    Player sam {"Sam", 20}; //2 args obj is created
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Stats of frank :" << std::endl;
    frank.get_stats();

    std::cout << std::endl;
    std::cout << "Stats of Hero :" << std::endl;
    hero.get_stats();

    std::cout << std::endl;
    std::cout << "Stats of Villain :" << std::endl;
    villain.get_stats();

    std::cout << std::endl;
    std::cout << "Stats of sam :" << std::endl;
    sam.get_stats();

    return 0;
}