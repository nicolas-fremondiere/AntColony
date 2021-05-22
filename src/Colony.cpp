
#include "Colony.h"
#include "GridManager.h"
#include "AntQueen.h"
#include "AntFighter.h"

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
        AntFighter *newFighter = new AntFighter(coord);
        _ants.push_back(newFighter);
        _waitArea.push_back(newFighter);
    }
}


const std::pair<int, int> &Colony::getCoord() const {
    return _coord;
}

void Colony::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}

std::vector<Ant*> Colony::getAnts() const {
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

std::vector<Ant*> Colony::getWaitArea()
{
    return _waitArea;
}
