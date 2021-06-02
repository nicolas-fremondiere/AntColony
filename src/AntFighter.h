#include "Ant.h"
#include "Food.h"
#ifndef ANTCOLONY_ANTFIGHTER_H
#define ANTCOLONY_ANTFIGHTER_H

// AntFighter.h
class AntFighter : public Ant{
public:

    AntFighter(std::pair<int, int> coord,int age=31, int color=4, int maxHp=200, int currentHp=200, bool haveFood=false,int quantityOfFood=0,int damageByHunger=3,int quantityMaxOfFood =10, bool displayed = false);

    bool isHaveFood() const;

    void setHaveFood(bool haveFood);

    int getQuantityOfFood() const;

    void setQuantityOfFood(int quantityOfFood);

    int getQuantityMaxOfFood() const;

    void setQuantityMaxOfFood(int quantityMaxOfFood);

    void moveTo(std::pair<int, int> coord);

    void behave();

    Food* foodDetector();

    void addFood(int foodAmount);

    std::vector<std::pair<int,int>> getSurroundings();

    TYPE_ANT getType(){
        return TYPE_ANT::FIGHTER;
    }
private:
    bool _haveFood;
    int _quantityOfFood;
    int _quantityMaxOfFood;
    bool _displayed;
};

#endif //ANTCOLONY_ANTFIGHTER_H
