#include "Ant.h"

#ifndef ANTCOLONY_ANTEGG_H
#define ANTCOLONY_ANTEGG_H

// AntEgg.h
class AntEgg : public Ant{
public:
    AntEgg(const std::pair<int, int> &coord,int age=0, int color=1, int maxHp=30, int currentHp=30);


private:
};

#endif //ANTCOLONY_ANTEGG_H
