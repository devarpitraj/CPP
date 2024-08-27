#include<iostream>
#include<string>
#include"Player.h"

void display_active_players() {
    std::cout << "Active players: " << Player::get_num_players() << std::endl;
}


int main() {
    display_active_players();   //0 obj o/p: 0

    Player frank{"Frank"};  //1 obj created
    display_active_players();   //o/p: 1

    {
        Player hero{"Hero", 10};    // obj created
        display_active_players();   // o/p: 2
    }                               // obj destroyed
    display_active_players();       // o/p: 1

    Player *enemy = new Player("Villain", 100, 100);    //obj created
    display_active_players();                           // o/p:2
    delete enemy;                                       // obj destroyed
    display_active_players();                           // o/p:1

    return 0;
}


//g++ Player.cpp main.cpp in terminal to run

/*

Active players: 0
Active players: 1
Active players: 2
Active players: 1
Active players: 2
Active players: 1

*/
