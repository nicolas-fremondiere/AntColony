
#include "Obstacle.h"

Obstacle::Obstacle(const std::pair<int, int> &coord) : _coord(coord) {}

const std::pair<int, int> &Obstacle::getCoord() const {
    return _coord;
}

void Obstacle::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}
