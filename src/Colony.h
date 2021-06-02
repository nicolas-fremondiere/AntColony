

#ifndef ANTCOLONY_COLONY_H
#define ANTCOLONY_COLONY_H

#include "Ant.h"

class Colony {
public:
    Colony(std::pair<int,int> coord, int foodStorage=0);

    std::pair<int, int> getCoord();

    std::vector<Ant*> getAnts() const;

    void setAnts(std::vector<Ant*> ants);

    int getFoodStorage() const;

    void setFoodStorage(int foodStorage);

    std::vector<Ant*>& getWaitArea();

    void addFood(int amount);

    void popBackWaitArea();

    void behaveAll();

private:
    std::pair<int,int> _coord;
    std::vector<Ant*> _ants;
    int _foodStorage;
    std::vector<Ant*> _waitArea;
};


#endif //ANTCOLONY_COLONY_H
