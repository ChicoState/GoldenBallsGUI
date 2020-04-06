/*
 * @file    Game.cpp - Game Class implementation
 *
 * @author  Shelley Wong, Nomaan Faiyaz Shaikh, Pratiksha Kapse
 * @date March 2020
 */
#include "Game.h"
#include "Human_Player.h"
#include "Computer_Player.h"
#include "Decision.h"
#include "Records.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

/*
 * @brief             Plays the game and changes records of all players
 * @param Game_Type   Determines if game is single (human vs computer)
 *                    or dual (human vs human)
 *
 * Play the single or dual version of the Golden Balls game. Game sets the
 * players' names and the players' choice (split or steal). Then the winner
 * is determined (4 possible cases) and the records are updated.
 */
Game::Game(Game_Type type)
{
  _players.resize(2);

  // Set players based on Game Type
  switch(type){
    case Game_Type::single:
      _players[0] = new Human_Player();
      _players[1] = new Computer_Player();
      break;
    case Game_Type::dual:
      _players[0] = new Human_Player();
      _players[1] = new Human_Player();
      break;
  }

  // Set names of players based on Game Type
  // Players all choose to split or steal
  Decision decision_list[2];
  for(int i = 0; i < _players.size(); i++){
    // Set player's name
    _players[i]->set_name();
    // Player makes decision
    decision_list[i] = _players[i]->split_or_steal();
  }

  Records& records = Records::instance();
  // Decide who won and update records
  if(decision_list[0] == Decision::steal && decision_list[1] == Decision::steal){
    records.update_record(_players[0]->get_name(), false);
    records.update_record(_players[1]->get_name(), false);
    cout<<"Both players stole, you both lose!\n";
  }
  else if(decision_list[0] == Decision::split && decision_list[1] == Decision::steal){
    records.update_record(_players[1]->get_name(), true);
    records.update_record(_players[1]->get_name(), true);
    records.update_record(_players[0]->get_name(), false);
    cout<<_players[1]->get_name()<<" stole and wins 2!\n";
  }
  else if(decision_list[0] == Decision::steal && decision_list[1] == Decision::split){
    records.update_record(_players[1]->get_name(), false);
    records.update_record(_players[0]->get_name(), true);
    records.update_record(_players[0]->get_name(), true);
    cout<<_players[0]->get_name()<<" stole and wins 2!\n";
  }
  else{ // both split
    records.update_record(_players[0]->get_name(), true);
    records.update_record(_players[1]->get_name(), true);
    cout<<"Both players split, you both win!\n";
  }
}
