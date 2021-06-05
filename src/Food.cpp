
#include "Food.h"
#include "GridManager.h"

Food::Food( const std::pair<int, int> &coord, int hpRecovery) :  _coord(coord), _hpRecovery(hpRecovery)
{
    //Random between 50 and 149
    _currentQuantity = (rand()%100)+50;
    GridManager::getInstance().display(LEAF_IMG,coord);

}

Food::~Food()
{
    GridManager::getInstance().removeDisplay(_coord);
}

int Food::getCurrentQuantity() const {
    return _currentQuantity;
}

void Food::setCurrentQuantity(int currentQuantity) {
    _currentQuantity = currentQuantity;
}

const std::pair<int, int> Food::getCoord() {
    return _coord;
}

void Food::setCoord(const std::pair<int, int> &coord) {
    _coord = coord;
}

int Food::getHpRecovery() const {
    return _hpRecovery;
}

void Food::setHpRecovery(int hpRecovery) {
    _hpRecovery = hpRecovery;
}
