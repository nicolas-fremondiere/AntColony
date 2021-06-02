#include "Ant.h"

#ifndef ANTCOLONY_ANTWORKER_H
#define ANTCOLONY_ANTWORKER_H

// AntWorker.h
class AntWorker : public Ant {
public:

    AntWorker(const std::pair<int, int> &coord, int age=21, int color=3, int maxHp=100, int currentHp=100,int damageByHunger=2);

    TYPE_ANT getType(){
        return TYPE_ANT::WORKER;
    }
};

#endif //ANTCOLONY_ANTWORKER_H
