

#include "../include/AntFighter.h"


AntFighter::AntFighter(std::pair<int, int> coord,int age, int color, int maxHp, int currentHp, bool haveFood,
                       int typeofFood):
        Ant(coord,age, color, maxHp, currentHp),
        _haveFood(haveFood),
        _typeofFood(typeofFood)
{

}


bool AntFighter::isHaveFood() const {
    return _haveFood;
}

void AntFighter::setHaveFood(bool haveFood) {
    _haveFood = haveFood;
}

int AntFighter::getTypeofFood() const {
    return _typeofFood;
}

void AntFighter::setTypeofFood(int typeofFood) {
    _typeofFood = typeofFood;
}

