
#include "Colony.h"
#include "GridManager.h"
#include "AntQueen.h"
#include "AntWorker.h"

Colony::Colony(std::pair<int,int> coord, int foodStorage) :
        _coord(coord),
        _foodStorage(foodStorage)
{

    //for( Ant* ant : _ants ) {
    //    ant->setColony(this);
    //}

    GridManager::getInstance().display(HOUSE_IMG,coord);

    // Initialization of the population in the colony by default
    _ants.push_back(new AntQueen(coord));
    for (int i=0;i<5;i++)
    {
        AntWorker *newWorker = new AntWorker(coord);
        _ants.push_back(newWorker);
        _waitArea.push_back(newWorker);
    }

}


const std::pair<int, int> &Colony::getCoord() const {
    return _coord;
}

void Colony::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}

const std::vector<Ant*> Colony::getAnts() const {
    return _ants;
}

void Colony::setAnts(std::vector<Ant*> ants) {
    _ants = ants;
}

int Colony::getFoodStorage() const {
    return _foodStorage;
}

void Colony::setFoodStorage(int foodStorage) {
    _foodStorage = foodStorage;
}
