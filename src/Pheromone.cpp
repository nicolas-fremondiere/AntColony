
#include "Pheromone.h"

Pheromone::Pheromone(std::pair<int, int> &coord, float concentration) :
    _coord(coord), _concentration(concentration) {}

const std::pair<int, int> &Pheromone::getCoord() const {
    return _coord;
}

void Pheromone::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}


float Pheromone::getConcentration() const {
    return _concentration;
}

void Pheromone::setConcentration(float concentration) {
    _concentration = concentration;
}

