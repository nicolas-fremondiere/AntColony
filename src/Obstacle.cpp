
#include "Obstacle.h"
#include "GridManager.h"


Obstacle::Obstacle(std::pair<int, int> &coord) : _coord(coord)
{
    GridManager::getInstance().display(STONE_IMG,coord);
}
Obstacle::~Obstacle()
{
    GridManager::getInstance().removeDisplay(_coord);
}

const std::pair<int, int> &Obstacle::getCoord() const {
    return _coord;
}

void Obstacle::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}
