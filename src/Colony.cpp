

#include "Colony.h"

Colony::Colony(int size, std::pair<int,int> coord, std::vector<Ant> ants, int foodStorage) :
        _size(size),
        _coord(coord),
        _ants(ants),
        _foodStorage(foodStorage)
{

}

int Colony::getSize() const {
    return _size;
}

void Colony::setSize(int size) {
    _size = size;
}

const std::pair<int, int> &Colony::getCoord() const {
    return _coord;
}

void Colony::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}

const std::vector<Ant> &Colony::getAnts() const {
    return _ants;
}

void Colony::setAnts(const std::vector<Ant> &ants) {
    _ants = ants;
}

int Colony::getFoodStorage() const {
    return _foodStorage;
}

void Colony::setFoodStorage(int foodStorage) {
    _foodStorage = foodStorage;
}
