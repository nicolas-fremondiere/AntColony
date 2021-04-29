
#include "include_tools.h"

#ifndef ANTCOLONY_FOOD_H
#define ANTCOLONY_FOOD_H

class Food {
public:
    Food(int typeOfFood, const std::pair<int, int> &coord, int hpRecovery);

    int getTypeOfFood() const;

    void setTypeOfFood(int typeOfFood);

    const std::pair<int, int> &getCoord() const;

    void setCoord(const std::pair<int, int> &coord);

    int getHpRecovery() const;

    void setHpRecovery(int hpRecovery);


private:
    int _typeOfFood;
    std::pair<int,int> _coord;
    int _hpRecovery;

};


#endif //ANTCOLONY_FOOD_H
