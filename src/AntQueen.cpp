
#include "AntQueen.h"

AntQueen::AntQueen(std::pair<int, int> coord, int age, int color, int maxHp, int currentHp, int timeSinceEggLaying,int damageByHunger):
    Ant(coord, age, color, maxHp, currentHp,damageByHunger),
    _timeSinceEggLaying(timeSinceEggLaying)
{

}

int AntQueen::getTimeSinceEggLaying() const{
    return _timeSinceEggLaying;
}

void AntQueen::setTimeSinceEggLaying(int timeSinceEggLaying){
    _timeSinceEggLaying = timeSinceEggLaying;
}
