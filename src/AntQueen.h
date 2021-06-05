
#include "Ant.h"

#ifndef ANTCOLONY_ANTQUEEN_H
#define ANTCOLONY_ANTQUEEN_H


class AntQueen : public Ant{
public:
    AntQueen(std::pair<int, int> coord,int age=100, int color=5, int maxHp=500, int currentHp=500, int _timeSinceEggLaying=0,int damageByHunger=10);

    int getTimeSinceEggLaying() const;

    void setTimeSinceEggLaying(int timeSinceEggLaying);

    TYPE_ANT getType(){
        return TYPE_ANT::QUEEN;
    }
private:
    int _timeSinceEggLaying;
};


#endif //ANTCOLONY_ANTQUEEN_H
