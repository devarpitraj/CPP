#include<iostream>
#include<string>

//using namespace std;

class Player {
    public:
        std::string name;
        int health;
        int xp;

    //public:
        Player(std::string n = "None", int h = 0, int x = 0);

        //Copy constructor
        Player(const Player &source);

        //Destructor
        ~Player() { std::cout << "Destructor called for " << name << std::endl; }

};

Player::Player(const Player &source) 
    : name{source.name}, health{source.health}, xp{source.xp}  //constr initialization list
    //: Player{source.name, source.health, source.xp}   //delegating constr
     {
        std::cout << "Copy constructor called for " << source.name << std::endl;
}

Player::Player(std::string n, int h, int x) 
         :name{n}, health{h}, xp{x} {
            std::cout << "3 args constructor is called" << std::endl;
}

void get_stats(Player p) {
            std::cout << "Name: " << p.name << std::endl << "Health: " << p.health << std::endl << "XP: " << p.xp << std::endl;
}

int main() {
    Player frank;
    std::cout << std::endl; 

    std::cout << "Stats of frank :" << std::endl;
    get_stats(frank);   //passing obj by value

    //Player copy (frank);    // creating copy of frank or copying attributes of one obj to a new obj


    return 0;
}

/*
output:-

3 args constructor is called // called for creating frank object


Stats of frank :
Copy constructor called for None    //called for p
Name: None
Health: 0
XP: 0
Destructor called for None  //called for p
Destructor called for None  //called for frank




*/