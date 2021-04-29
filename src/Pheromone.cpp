//
// Created by nfrem on 29/04/2021.
//

#include "../include/Pheromone.h"

Pheromone::Pheromone(const std::pair<int, int> &coord, bool foodAhead, float concentration, int colonyId) : _coord(
        coord), _foodAhead(foodAhead), _concentration(concentration), _colonyId(colonyId) {}

const std::pair<int, int> &Pheromone::getCoord() const {
    return _coord;
}

void Pheromone::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}

bool Pheromone::isFoodAhead() const {
    return _foodAhead;
}

void Pheromone::setFoodAhead(bool foodAhead) {
    _foodAhead = foodAhead;
}

float Pheromone::getConcentration() const {
    return _concentration;
}

void Pheromone::setConcentration(float concentration) {
    _concentration = concentration;
}

int Pheromone::getColonyId() const {
    return _colonyId;
}

void Pheromone::setColonyId(int colonyId) {
    _colonyId = colonyId;
}
