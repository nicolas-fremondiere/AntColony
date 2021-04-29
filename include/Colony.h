
#include "Ant.h"

#ifndef ANTCOLONY_COLONY_H
#define ANTCOLONY_COLONY_H


class Colony {
public:
    Colony(int size, std::pair<int, int> coord, std::vector<Ant> ants, int foodStorage);

    int getSize() const;

    void setSize(int size);

    const std::pair<int, int> &getCoord() const;

    void setCoord(const std::pair<int, int> &coord);

    const std::vector<Ant> &getAnts() const;

    void setAnts(const std::vector<Ant> &ants);

    int getFoodStorage() const;

    void setFoodStorage(int foodStorage);


private:
    int _size;
    std::pair<int,int> _coord;
    std::vector<Ant> _ants;
    int _foodStorage;
};


#endif //ANTCOLONY_COLONY_H
