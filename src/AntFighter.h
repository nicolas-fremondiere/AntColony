#include "Ant.h"
#ifndef ANTCOLONY_ANTFIGHTER_H
#define ANTCOLONY_ANTFIGHTER_H


class Food;
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

    std::pair<int,int> getLastPosition() const;

    void setLastPosition(std::pair<int,int> lastPosition);

    //Move to a specific position
    void moveTo(std::pair<int, int> coord);

    //determine the action of the ant during one turn
    void behave();

    //Return a food object if one is arroung
    Food* foodDetector();

    void addFood(int foodAmount);

    //Return the 4 position arroung the ant
    std::vector<std::pair<int,int>> getSurroundings();

    TYPE_ANT getType(){
        return TYPE_ANT::FIGHTER;
    }
private:
    bool _haveFood;
    int _quantityOfFood;
    int _quantityMaxOfFood;
    bool _displayed;
    std::pair<int,int> _lastPosition;
};

#endif //ANTCOLONY_ANTFIGHTER_H
