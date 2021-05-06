

#include "AntFighter.h"


AntFighter::AntFighter(std::pair<int, int> coord,int age, int color, int maxHp, int currentHp, bool haveFood,
                       int quantityOfFood,int damageByHunger):
        Ant(coord,age, color, maxHp, currentHp,damageByHunger),
        _haveFood(haveFood),
        _quantityOfFood(quantityOfFood)
{

}


bool AntFighter::isHaveFood() const {
    return _haveFood;
}

void AntFighter::setHaveFood(bool haveFood) {
    _haveFood = haveFood;
}

int AntFighter::getQuantityOfFood() const {
    return _quantityOfFood;
}

void AntFighter::setQuantityOfFood(int quantityOfFood) {
    _quantityOfFood = quantityOfFood;
}

int AntFighter::getQuantityMaxOfFood() const {
    return _quantityMaxOfFood;
}

void AntFighter::setQuantityMaxOfFood(int quantityMaxOfFood) {
    _quantityMaxOfFood = quantityMaxOfFood;
}

