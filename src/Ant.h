#include "include_tools.h"

#ifndef ANTCOLONY_ANT_H
#define ANTCOLONY_ANT_H

class Colony;

enum TYPE_ANT{
    EGG,
    LARVA,
    WORKER,
    FIGHTER,
    QUEEN
};


// Ant.h
class Ant
{
public:

    Ant(const std::pair<int, int> &coord,int age, int color, int maxHp, int currentHp,int damageByHunger) :
    _age(age),
    _color(color),
    _maxHP(maxHp),
    _currentHP(currentHp),
    _damageByHunger(damageByHunger),
    _coord(coord)
    {}

    virtual ~Ant() {

    }

    int getAge() const {
        return _age;
    }

    void addAge(){
        _age++;
    }

    int getColor() const {
        return _color;
    }

    int getMaxHp() const {
        return _maxHP;
    }

    int getCurrentHp() const {
        return _currentHP;
    }

    void setCurrentHp(int currentHp) {
        _currentHP = currentHp;
    }

    void hungerDamage(){
        _currentHP--;
    }
    int getDamageByHunger() const {
        return _damageByHunger;
    }

    void setDamageByHunger(int damageByHunger) {
        _damageByHunger = damageByHunger;
    }

    const std::pair<int, int> getCoord() const {
        return _coord;
    }

    void setCoord(std::pair<int, int> coord) {
        _coord = coord;
    }

    Colony* getColony() const {
        return _myColony;
    }


    void setColony(Colony* myColony) {
       _myColony = myColony;
    }

    virtual void moveTo(std::pair<int, int> coord){}
    virtual void behave(){}
    virtual TYPE_ANT getType(){
        return TYPE_ANT::EGG;
    }

protected:
    int _age;
    int _color;
    int _maxHP;
    int _currentHP;
    int _damageByHunger;
    std::pair<int,int> _coord;
    Colony* _myColony;
};

#endif //ANTCOLONY_ANT_H
