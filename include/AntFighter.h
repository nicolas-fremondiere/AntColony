#include "Ant.h"

#ifndef ANTCOLONY_ANTFIGHTER_H
#define ANTCOLONY_ANTFIGHTER_H

// AntFighter.h
class AntFighter : public Ant{
public:

    AntFighter(std::pair<int, int> coord,int age=31, int color=4, int maxHp=200, int currentHp=200, bool haveFood=false,int typeofFood=0);

    bool isHaveFood() const;

    void setHaveFood(bool haveFood);

    int getTypeofFood() const;

    void setTypeofFood(int typeofFood);

public:

private:
    bool _haveFood;
    int _typeofFood;
};

#endif //ANTCOLONY_ANTFIGHTER_H
