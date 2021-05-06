#include "Ant.h"

#ifndef ANTCOLONY_ANTFIGHTER_H
#define ANTCOLONY_ANTFIGHTER_H

// AntFighter.h
class AntFighter : public Ant{
public:

    AntFighter(std::pair<int, int> coord,int age=31, int color=4, int maxHp=200, int currentHp=200, bool haveFood=false,int quantityOfFood=0,int damageByHunger=3,int _quantityMaxOfFood =10);

    bool isHaveFood() const;

    void setHaveFood(bool haveFood);

    int getQuantityOfFood() const;

    void setQuantityOfFood(int quantityOfFood);

    int getQuantityMaxOfFood() const;

    void setQuantityMaxOfFood(int quantityMaxOfFood);

private:
    bool _haveFood;
    int _quantityOfFood;
    int _quantityMaxOfFood;
};

#endif //ANTCOLONY_ANTFIGHTER_H
