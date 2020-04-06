/*
 * @file  Game.h - Game Class header file
 *
 * @author  Shelley Wong, Nomaan Faiyaz Shaikh, Pratiksha Kapse
 * @date March 2020
 */
#ifndef GAME_H
#define GAME_H

#include "Game_Type.h"
#include "Player.h"
#include <vector>

class Game {
  public:
    Game(Game_Type);  // play game

  private:
    std::vector<Player*> _players;   // list of players
};

#endif
