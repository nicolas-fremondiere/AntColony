
#include "Colony.h"
#include "GridManager.h"
#include "AntQueen.h"
#include "AntFighter.h"
#include "AntLarva.h"
#include "AntWorker.h"


Colony::Colony(std::pair<int,int> coord, int foodStorage, int maxFoodStorage) :
        _coord(coord),
        _foodStorage(foodStorage),
        _maxFoodStorage(maxFoodStorage)
{
    GridManager::getInstance().display(HOUSE_IMG,coord);

    // Initialization of the population in the colony by default
    AntQueen *newQueen = new AntQueen(coord);
    newQueen->setColony(this);
    _ants.push_back(newQueen);

    for (int i=0;i<10;i++)
    {
        AntFighter* newFighter = new AntFighter(coord);
        newFighter->setColony(this);
        _ants.push_back(newFighter);
        _waitArea.push_back(newFighter);

        AntLarva* newLarva = new AntLarva(this->getCoord());
        newLarva->setColony(this);
        this->addAnt(newLarva);
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

void Colony::addAnt(Ant* ant){
    _ants.push_back(ant);
}

void Colony::deleteAnt(Ant* ant){
    remove(_ants.begin(), _ants.end(), ant);
    _ants.resize(_ants.size()-1);
}

int Colony::getFoodStorage() const {
    return _foodStorage;
}

void Colony::setFoodStorage(int foodStorage){
    _foodStorage = foodStorage;
}

int Colony::getMaxFoodStorage() const {
    return _maxFoodStorage;
}

void Colony::setMaxFoodStorage(int maxFoodStorage){
    _maxFoodStorage = maxFoodStorage;
}

std::vector<Ant*>& Colony::getWaitArea(){
    return _waitArea;
}

void Colony::addFood(int amount){
    _foodStorage += amount;

    // If foodStorage bigger than maxFoodStorage
    if( getFoodStorage() > getMaxFoodStorage()){
        _foodStorage = getMaxFoodStorage();
    }
}

void Colony::popBackWaitArea(){
    _waitArea.pop_back();
}

void Colony::behaveAll()
{
    for(Ant* ant : _ants ) {
        ant->behave();
    }
}

void Colony::eraseALl()
{
    for(Ant* ant : _ants ) {
        delete ant;
    }
}

int Colony::countAnt(TYPE_ANT antType)
{
    int sum = 0;
    for(Ant* ant : _ants ) {
        if(ant->getType()==antType) sum++;
    }
    return sum;
}


