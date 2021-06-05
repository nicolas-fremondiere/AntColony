
#include "include_tools.h"
#include "AntFighter.h"
#ifndef ANTCOLONY_FOOD_H
#define ANTCOLONY_FOOD_H


class Food {
public:
    Food( const std::pair<int, int> &coord, int hpRecovery = 10);

    ~Food();
    int getCurrentQuantity() const;

    void setCurrentQuantity(int currentQuantity);

    const std::pair<int, int> getCoord();

    void setCoord(const std::pair<int, int> &coord);

    int getHpRecovery() const;

    void setHpRecovery(int hpRecovery);

    int getFoodAmount(AntFighter* ant);

private:
    int _currentQuantity;
    std::pair<int,int> _coord;
    int _hpRecovery;

};


#endif //ANTCOLONY_FOOD_H
