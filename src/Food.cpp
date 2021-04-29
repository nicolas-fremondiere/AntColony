//
// Created by nfrem on 29/04/2021.
//

#include "../include/Food.h"

Food::Food(int typeOfFood, const std::pair<int, int> &coord, int hpRecovery) : _typeOfFood(typeOfFood), _coord(coord),
                                                                               _hpRecovery(hpRecovery) {}

int Food::getTypeOfFood() const {
    return _typeOfFood;
}

void Food::setTypeOfFood(int typeOfFood) {
    _typeOfFood = typeOfFood;
}

const std::pair<int, int> &Food::getCoord() const {
    return _coord;
}

void Food::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}

int Food::getHpRecovery() const {
    return _hpRecovery;
}

void Food::setHpRecovery(int hpRecovery) {
    _hpRecovery = hpRecovery;
}
