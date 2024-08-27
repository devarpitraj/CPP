#ifndef _PLAYER_H_
#define _PLAYER_H_

#include<string>


class Player {
    private:
        std::string name;
        int health;
        int xp;

        static int num_players;
    
    public:
        Player(std::string n = "None", int health = 0, int xp = 0);
        ~Player();
        static int get_num_players();
};



#endif