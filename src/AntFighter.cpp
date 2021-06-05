
#include "AntFighter.h"
#include "GridManager.h"
#include <QDebug>
#include <QRandomGenerator>


AntFighter::AntFighter(std::pair<int, int> coord,int age, int color, int maxHp, int currentHp, bool haveFood,
                       int quantityOfFood,int damageByHunger,int quantityMaxOfFood, bool displayed):
        Ant(coord,age, color, maxHp, currentHp, damageByHunger),
        _haveFood(haveFood),
        _quantityOfFood(quantityOfFood),
        _quantityMaxOfFood(quantityMaxOfFood),
        _displayed(displayed)
{
    _lastPosition = coord;
}


bool AntFighter::isHaveFood() const {
    return _haveFood;
}

void AntFighter::setHaveFood(bool haveFood) {
    _haveFood = haveFood;
}

int AntFighter::getQuantityOfFood() const {
    return _quantityOfFood;
}

void AntFighter::setQuantityOfFood(int quantityOfFood) {
    _quantityOfFood = quantityOfFood;
}

int AntFighter::getQuantityMaxOfFood() const {
    return _quantityMaxOfFood;
}

void AntFighter::setQuantityMaxOfFood(int quantityMaxOfFood) {
    _quantityMaxOfFood = quantityMaxOfFood;
}

std::pair<int,int> AntFighter::getLastPosition() const{
    return _lastPosition;
}

void AntFighter::setLastPosition(std::pair<int,int> lastPosition){
    _lastPosition = lastPosition;
}


void AntFighter::addFood(int foodAmount)
{
    _quantityOfFood +=foodAmount;
    if(_quantityOfFood > _quantityMaxOfFood)
        _quantityOfFood = _quantityMaxOfFood;
}


void AntFighter::moveTo(std::pair<int, int> coord) {
    if(_displayed){
        GridManager::getInstance().removeDisplay(getCoord());
        GridManager::getInstance().removeAnt(getCoord());
        _lastPosition = getCoord();
    }
    else
    {
        _displayed=true;
    }

    setCoord(coord);
    GridManager::getInstance().display(ANT_IMG, getCoord());
    GridManager::getInstance().addAnts(this,coord);
}


void AntFighter::behave()
{
    float decision = (float) rand()/RAND_MAX;

    std::vector<std::pair<int,int>> allPosibilities = getSurroundings();


    GridManager& instGM = GridManager::getInstance();
    std::map<std::pair<int,int>,float> freeSpace;
    //get only the free space arround the ant
    for(std::pair<int,int> & coord : allPosibilities ) {
       if(instGM.getElementByCoord(coord) == Cell::FREE)
       {

           freeSpace[coord] = instGM.getElement(instGM.getPheromones(),coord)->getConcentration() + 20;

           if(_lastPosition == coord)
           {
               freeSpace[coord] = freeSpace[coord]/4;
           }
       }
    }
    if(freeSpace.empty())return;

    float somme = std::accumulate(freeSpace.begin(), freeSpace.end(), 0, [](const size_t previous, decltype(*freeSpace.begin()) p) { return previous+p.second; });

    std::map<std::pair<int,int>,float> probabilities;
    for(auto prob : freeSpace) {
        probabilities[prob.first] = prob.second/somme;
    }

    //Get the final decision
    std::pair<int,int> finaldecision;
    float gauge =0;
    for(auto prob : probabilities) {
        gauge += prob.second;
        if( decision<gauge )
        {
            finaldecision = prob.first;
            break;
        }
    }

    //Add pheromone
    if(_haveFood)
        instGM.getPheromones().at(_coord.first).at(_coord.second)->addConcentration(30);
    else
        instGM.getPheromones().at(_coord.first).at(_coord.second)->addConcentration(15);
    instGM.getPheromones().at(_coord.first).at(_coord.second)->updateDisplay();

    moveTo(finaldecision);

    //Detect if food nearby
    Food* myFood = foodDetector();
    if(myFood != NULL && !_haveFood)
    {
        int foodAmount = myFood->getCurrentQuantity();
        _haveFood= true;
        _quantityOfFood = getQuantityMaxOfFood();
        foodAmount -= _quantityOfFood;
        myFood->setCurrentQuantity(foodAmount);
    }

    //Detect if colony nearby
    std::vector<std::pair<int,int>> newSurroundings = getSurroundings();

    //put down the food in the colony
    Colony* mcol = _myColony;
    for(auto pos : newSurroundings) {
        if(pos.first == mcol->getCoord().first && pos.second == mcol->getCoord().second && _haveFood)
        {
            mcol->addFood(_quantityOfFood);
            _quantityOfFood = 0;
            _haveFood = false;
        }
    }

}

Food* AntFighter::foodDetector(){
    std::vector<std::pair<int,int>> allPosibilities = getSurroundings();
    GridManager& instGM = GridManager::getInstance();
    for(std::pair<int,int> & coord : allPosibilities ) {
       if(instGM.getElementByCoord(coord) == Cell::FOOD)
       {
            return instGM.getFoods().at(coord.first).at(coord.second);
       }
    }
    return NULL;
}

std::vector<std::pair<int,int>> AntFighter::getSurroundings(){
    std::pair<int,int> here = getCoord();
    std::vector<std::pair<int,int>> allPosibilities = {
        std::make_pair(here.first-1,here.second),
        std::make_pair(here.first,here.second+1),
        std::make_pair(here.first+1,here.second),
        std::make_pair(here.first,here.second-1)};
    return allPosibilities;
}
