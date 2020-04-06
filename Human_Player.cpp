#include <iostream>
#include "Human_Player.h"
#include "Decision.h"

using std::cout;
using std::cin;
using std::endl;

Human_Player::Human_Player()
{
  _name = "Anonymous";
}

void Human_Player::set_name()
{
  cout<<"Enter player name: "<<endl;
  cin>>_name;
}

Decision Human_Player::split_or_steal()
{
  int menu;
  do
  {
    cout<<"Choose your move:\n"
        <<"1. Steal\n"
        <<"2. Split\n";
    cin>>menu;

    if( menu != 1 && menu != 2)
    {
      cout<<"Please choose 1 or 2.\n";
    }
  }while( menu != 1 && menu != 2);

  if( menu == 1)
  {
      return Decision::steal;
  }
  else
  {
      return Decision::split;
  }
}

std::string Human_Player::get_name(){
    return _name;
}
