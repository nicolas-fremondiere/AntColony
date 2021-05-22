

#ifndef ANTCOLONY_COLONY_H
#define ANTCOLONY_COLONY_H

#include "Ant.h"

class Colony {
public:
    Colony(std::pair<int,int> coord, std::vector<Ant*> ants, int foodStorage=0);

    const std::pair<int, int> &getCoord() const;

    void setCoord(const std::pair<int, int> &coord);

    const std::vector<Ant*> getAnts() const;

    void setAnts(std::vector<Ant*> ants);

    int getFoodStorage() const;

    void setFoodStorage(int foodStorage);


private:
    std::pair<int,int> _coord;
    std::vector<Ant*> _ants;
    int _foodStorage;
};


#endif //ANTCOLONY_COLONY_H