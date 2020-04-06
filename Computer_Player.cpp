#include <string>
#include "Computer_Player.h"
#include "Decision.h"

void Computer_Player :: set_name(){
    _name = "Computer";
}

Decision Computer_Player :: split_or_steal()
{
    return Decision::steal;
}

std::string Computer_Player :: get_name(){
    return _name;
}
