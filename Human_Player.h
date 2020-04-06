// Register.h
#ifndef HPLAYER_H_
#define HPLAYER_H_
#include "Player.h"
#include "Decision.h"
#include <string>

class Human_Player: public Player {
  public:
    Human_Player();
    void set_name();
    Decision split_or_steal();
    std::string get_name();
  private:
    std::string _name;
};

#endif
