#include "Player.h"

int Player::num_players = 0;

Player::Player(std::string n, int h, int x) 
    :name{n}, health{h}, xp{x} {
        ++num_players;
    }

Player::~Player() {
    --num_players;
}

int Player::get_num_players() {
    return num_players;
}

