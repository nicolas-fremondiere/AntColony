
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

void AntFighter::moveTo(std::pair<int, int> coord) {
    if(_displayed){
        GridManager::getInstance().remove(getCoord());
        GridManager::getInstance().getAnts().at(getCoord().first).at(getCoord().second) = NULL;
    }
    else
    {
        _displayed=true;
    }

    setCoord(coord);
    GridManager::getInstance().display(ANT_IMG, getCoord());
    GridManager::getInstance().getAnts().at(coord.first).at(coord.second) = this;
}


void AntFighter::behave()
{
    float decision = (float) rand()/RAND_MAX;
//    qDebug() << "random : "<< decision;

    std::pair<int,int> here = getCoord();
    std::pair<int,int> allPosibilities[] = {
        std::make_pair(here.first-1,here.second),
        std::make_pair(here.first,here.second+1),
        std::make_pair(here.first+1,here.second),
        std::make_pair(here.first,here.second-1)
    };

//    qDebug() << "coord : "<< here.first<<here.second;


    GridManager& instGM = GridManager::getInstance();
//    std::vector<std::pair<int,int>> freeSpace;
    std::map<std::pair<int,int>,float> freeSpace;
    //get only the free space arround the ant
    for(std::pair<int,int> & coord : allPosibilities ) {
       if(instGM.getElementByCoord(coord) == Cell::FREE)
       {
           freeSpace[coord] = instGM.getElement(instGM.getPheromones(),coord)->getConcentration() + 20;
//           qDebug() << "free : "<< coord.first << coord.second;
       }
    }
    if(freeSpace.empty())return;

    float somme = std::accumulate(freeSpace.begin(), freeSpace.end(), 0, [](const size_t previous, decltype(*freeSpace.begin()) p) { return previous+p.second; });

    std::map<std::pair<int,int>,float> probabilities;
    for(auto prob : freeSpace) {
        probabilities[prob.first] = prob.second/somme;
    }


//    qDebug() << "somme : "<< somme;
//    qDebug() << "decision : "<< decision;

    std::pair<int,int> finaldecision;
    float gauge =0;
    for(auto prob : probabilities) {
//        qDebug() << "freespace here : " << prob.first.first << prob.first.second;

        gauge += prob.second;
//        qDebug() << "Gauge here : " << gauge;

        if( gauge > decision)
        {
            finaldecision = prob.first;
            break;
        }
    }
//    qDebug() << "final decision : " << finaldecision.first << finaldecision.second;
    moveTo(finaldecision);


//    int topConcentration = instGM.getPheromones().at(getCoord().first-1).at(getCoord().second)->getConcentration();
//    int rightConcentration = instGM.getPheromones().at(getCoord().first).at(getCoord().second+1)->getConcentration();
//    int botConcentration = instGM.getPheromones().at(getCoord().first-1).at(getCoord().second)->getConcentration();
//    int leftConcentration = instGM.getPheromones().at(getCoord().first).at(getCoord().second-1)->getConcentration();
//    float somme = topConcentration + rightConcentration + botConcentration + leftConcentration;


////    std::map<std::string, float> probabilities {
////        {"top", topConcentration/somme},
////        {"right", rightConcentration/somme},
////        {"bot", botConcentration/somme},
////        {"left", leftConcentration/somme},
////    };

//    float gauge =probabilities["top"];
//    if(decision <=gauge)
//    {

//    }
//    else if(decision <= gauge + probabilities["right"])
//    {

//    }
//    else if(decision <= gauge + probabilities["bot"])
//    {

//    }
//    else
//    {

//    }



}


