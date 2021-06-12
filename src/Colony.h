

#ifndef ANTCOLONY_COLONY_H
#define ANTCOLONY_COLONY_H

#include "Ant.h"

class Colony {
public:
    Colony(std::pair<int,int> coord, int foodStorage=0, int maxFoodStorage=200);

    std::pair<int, int> getCoord();

    std::vector<Ant*> getAnts() const;

    void setAnts(std::vector<Ant*> ants);

    void addAnt(Ant *ant);

    void deleteAnt(Ant* ant);

    int getFoodStorage() const;

    void setFoodStorage(int foodStorage);

    int getMaxFoodStorage() const;

    void setMaxFoodStorage(int maxFoodStorage);

    std::vector<Ant*>& getWaitArea();

    void addFood(int amount);

    void popBackWaitArea();

    void behaveAll();

    void eraseALl();

    int countAnt(TYPE_ANT antType);

private:
    std::pair<int,int> _coord;
    std::vector<Ant*> _ants;
    int _foodStorage;
    std::vector<Ant*> _waitArea;
    int _maxFoodStorage;
};


#endif //ANTCOLONY_COLONY_H
