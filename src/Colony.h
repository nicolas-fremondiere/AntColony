

#ifndef ANTCOLONY_COLONY_H
#define ANTCOLONY_COLONY_H

#include "Ant.h"

class Colony {
public:
    Colony(std::pair<int,int> coord, int foodStorage=0);

    const std::pair<int, int> &getCoord() const;

    void setCoord(const std::pair<int, int> &coord);

    std::vector<Ant*> getAnts() const;

    int getFoodStorage() const;

    void setFoodStorage(int foodStorage);

    std::vector<Ant*> getWaitArea();


private:
    std::pair<int,int> _coord;
    std::vector<Ant*> _ants;
    int _foodStorage;
    std::vector<Ant*> _waitArea;
};


#endif //ANTCOLONY_COLONY_H
