
#include "../include/AntQueen.h"

AntQueen::AntQueen(std::pair<int, int> coord, int age, int color, int maxHp, int currentHp, int timeSinceEggLaying):
    Ant(coord, age, color, maxHp, currentHp),
    _timeSinceEggLaying(timeSinceEggLaying)
{

}

int AntQueen::getTimeSinceEggLaying() const{
    return _timeSinceEggLaying;
}

void AntQueen::setTimeSinceEggLaying(int timeSinceEggLaying){
    _timeSinceEggLaying = timeSinceEggLaying;
}
