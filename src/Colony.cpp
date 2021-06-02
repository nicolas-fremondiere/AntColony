
#include "Colony.h"
#include "GridManager.h"
#include "AntQueen.h"
#include "AntFighter.h"

Colony::Colony(std::pair<int,int> coord, int foodStorage) :
        _coord(coord),
        _foodStorage(foodStorage)
{
    GridManager::getInstance().display(HOUSE_IMG,coord);

    // Initialization of the population in the colony by default
    AntQueen *newQueen = new AntQueen(coord);
    newQueen->setColony(this);
    _ants.push_back(newQueen);

    for (int i=0;i<3;i++)
    {
        AntFighter *newFighter = new AntFighter(coord);
        newFighter->setColony(this);
        _ants.push_back(newFighter);
        _waitArea.push_back(newFighter);
    }
}


std::pair<int, int> Colony::getCoord(){

    return _coord;
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

std::vector<Ant*>& Colony::getWaitArea() {
    return _waitArea;
}

void Colony::addFood(int amount){
    _foodStorage += amount;
}

void Colony::popBackWaitArea(){
    _waitArea.pop_back();
}

void Colony::behaveAll()
{
    for(Ant* ant : _ants ) {

        qDebug() << "Colony for a ant "<< ant->getColony();
        ant->behave();
    }
}



