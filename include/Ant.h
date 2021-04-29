#include "include_tools.h"
#ifndef ANTCOLONY_ANT_H
#define ANTCOLONY_ANT_H

// Ant.h
class Ant
{
public:

    Ant(const std::pair<int, int> &coord,int age, int color, int maxHp, int currentHp) :
    _age(age),
    _color(color),
    _maxHP(maxHp),
    _currentHP(currentHp),
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

    const std::pair<int, int> getCoord() const {
        return _coord;
    }

    void setCoord(std::pair<int, int> coord) {
        _coord = coord;
    }



private:
    int _age;
    int _color;
    int _maxHP;
    int _currentHP;
    std::pair<int,int> _coord;
};

#endif //ANTCOLONY_ANT_H
