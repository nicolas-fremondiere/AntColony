#include "Ant.h"

#ifndef ANTCOLONY_ANTLARVA_H
#define ANTCOLONY_ANTLARVA_H

// AntLarva.h
class AntLarva : public Ant{
public:
    AntLarva(const std::pair<int, int> &coord, int age=11, int color=1, int maxHp=50, int currentHp=50,int damageByHunger=1);


private:
};

#endif //ANTCOLONY_ANTLARVA_H
