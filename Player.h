#ifndef PLAYER_H
#define PLAYER_H
#include "Decision.h"
#include <string>

class Player
{
    public:
        virtual void set_name() = 0;
        virtual Decision split_or_steal() = 0;
        virtual std::string get_name() = 0;
};

#endif
