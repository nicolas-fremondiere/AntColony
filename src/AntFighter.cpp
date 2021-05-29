

#include "AntFighter.h"
#include "GridManager.h"

AntFighter::AntFighter(std::pair<int, int> coord,int age, int color, int maxHp, int currentHp, bool haveFood,
                       int quantityOfFood,int damageByHunger,int quantityMaxOfFood, bool displayed):
        Ant(coord,age, color, maxHp, currentHp, damageByHunger),
        _haveFood(haveFood),
        _quantityOfFood(quantityOfFood),
        _quantityMaxOfFood(quantityMaxOfFood),
        _displayed(displayed)
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

void AntFighter::moveTo(std::pair<int, int> coord) {
    if(_displayed){
        GridManager::getInstance().display("", getCoord());
        GridManager::getInstance().getAnts().at(getCoord().first).at(getCoord().second) = NULL;
    }

    setCoord(coord);
    GridManager::getInstance().display(ANT_IMG, getCoord());
    GridManager::getInstance().getAnts().at(coord.first).at(coord.second) = this;
}


