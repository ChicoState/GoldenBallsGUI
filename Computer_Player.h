#ifndef COMPUTER_PLAYER_H_
#define COMPUTER_PLAYER_H_
#include<string>
#include "Player.h"
#include "Decision.h"

using std::string;

class Computer_Player : public Player{
    private:
        string _name;

    public:
        void set_name();
        Decision split_or_steal();
        string get_name();
};
#endif
